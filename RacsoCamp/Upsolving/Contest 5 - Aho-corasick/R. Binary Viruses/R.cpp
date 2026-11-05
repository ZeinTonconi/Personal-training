#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
vector<vi> G;

template<int E=26>
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
      int c=ch-'0';
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

vector<int> vis;

void buildGraph(AhoCorasick<2> &AC){
  G.resize(AC.nodes);
  vis.resize(AC.nodes);
  
  for(int i=0;i<AC.nodes;i++){
    if(AC.terminal[i]) continue;
    for(auto &v:AC.go[i]){
      if(!AC.terminal[v]){
	G[i].push_back(v);
      }
    }
  }
}

bool checkLoop(int u){
  vis[u]=1;
  for(auto &v:G[u]){
    if(vis[v]==1) return 1;
    
    if(!vis[v] && checkLoop(v)) return 1;
  }
  vis[u]=2;
  return 0;
}

int main(){
  int n; cin>>n;
  AhoCorasick<2> AC;
  for(int i=0;i<n;i++){
    string x; cin>>x;
    AC.insert(x);
  }
  AC.build();
  buildGraph(AC);
  
  cout<<(checkLoop(0)?"YES\n":"NO\n");
}
