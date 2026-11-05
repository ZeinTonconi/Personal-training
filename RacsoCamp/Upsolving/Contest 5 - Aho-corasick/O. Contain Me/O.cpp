#include <bits/stdc++.h>
using namespace std;

const int sigma=26;
const int MOD=239;

template<int E=sigma>
struct AhoCorasick {
  int nodes;
  vector<int> suf;
  vector<int> super;
  vector<bool> terminal;
  vector<array<int,E>> go;

  AhoCorasick(){
    add_node();
    nodes=1;
  }

  void add_node(){
    terminal.emplace_back();
    suf.emplace_back();
    go.emplace_back();
    super.emplace_back();
  }

  void insert(string &s){
    int pos=0;
    for(char ch: s){
      int c=ch-'a';
      if(go[pos][c]==0){
	go[pos][c]=nodes++;
	add_node();
      }
      pos=go[pos][c];
    }
    terminal[pos]=true;
  }

  void build(){
    queue<int> Q;
    Q.emplace(0);
    while(!Q.empty()){
      int u=Q.front(); Q.pop();
      super[u]=(suf[u]==0 || terminal[suf[u]] ? suf[u] : super[suf[u]]);

      terminal[u]=terminal[u]|terminal[suf[u]];

      for(int c=0;c<E;++c){
	if(go[u][c]){
	  int v=go[u][c];
	  Q.emplace(v);
	  suf[v]=u==0?0:go[suf[u]][c];
	}
	else{
	  go[u][c]=u==0?0:go[suf[u]][c];
	}
      }
    }
  }
};


struct Matrix {
  int n;
  vector<vector<int>> a;

  Matrix(int n, bool identity = false) : n(n) {
    a.assign(n, vector<int>(n, 0));
    if (identity) {
      for (int i = 0; i < n; i++)
	a[i][i] = 1;
    }
  }

  Matrix operator*(const Matrix &other) const {
    Matrix res(n);

    for (int i = 0; i < n; i++) {
      for (int k = 0; k < n; k++) {
	if (a[i][k] == 0) continue;
	for (int j = 0; j < n; j++) {
	  res.a[i][j] = (res.a[i][j] + a[i][k] * other.a[k][j]) % MOD;
	}
      }
    }

    return res;
  }
};

Matrix power(Matrix base, int  exp) {
  Matrix res(base.n,true);
  
  while (exp) {
    if (exp & 1)
      res = res * base;
    base = base * base;
    exp >>= 1;
  }

  return res;
}

int power(int base,int exp){
  int res=1;
  while(exp){
    if(exp&1)
      res=(res*base)%MOD;
    base=(base*base)%MOD;
    exp>>=1;
  }
  return res;
}

template<int E=sigma>
Matrix buildGraph(AhoCorasick<E> &AC){
  Matrix G(AC.nodes);

  for(int i=0;i<AC.nodes;i++){
    if(AC.terminal[i]) continue;
    for(auto &v:AC.go[i]){
      if(!AC.terminal[v]){
	G.a[i][v]++;
      }
    }
  }
  return G;
}

int main(){
  int l,n; cin>>l>>n;
  AhoCorasick<26> AC;
  for(int i=0;i<n;i++){
    string x; cin>>x;
    AC.insert(x);
  }
  AC.build();

  Matrix G=buildGraph(AC);

  Matrix Gl=power(G,l);

  int paths=0;
  for(int i=0;i<Gl.n;i++){
    paths=(paths+Gl.a[0][i])%MOD;
  }
  
  int univ=power(26,l);
  
  cout<<(univ-paths+MOD)%MOD<<endl;
}
