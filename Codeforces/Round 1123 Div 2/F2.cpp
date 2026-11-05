#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

template <int E=2>
struct Trie{
  int nodes;
  vector<int> terminal;
  vector<int> level;
  vector<int> freq;
  vector<ii> range;
  vector<array<int, E>> go;

  vector<int> val;

  Trie(){
    add_node();
    nodes=1;
  };
  
  void add_node(){
    terminal.emplace_back(-1);
    level.emplace_back();
    go.emplace_back();
    range.emplace_back(ii(1e9,-1));
    freq.emplace_back(0);
  }

  void insert(int s){
    int pos=0;
    for(int i=29;i>=0;i--){
      bool c=(s&(1<<i));
      if(go[pos][c]==0){
	go[pos][c]=nodes++;
	add_node();
      }
      pos=go[pos][c];
    }
    terminal[pos]=s;
    freq[pos]++;
  }
  
  vector<int> byLevel[30];
  
  void dfs(int u){

    if(terminal[u]!=-1){
      int t=val.size();
      range[u]=ii(t,t+freq[u]-1);
      for(int i=0;i<freq[u];i++)
	val.push_back(terminal[u]);
    }
    
    bool ok=1;
    for(int i=0;i<E;i++){
      if(go[u][i]){
	int v=go[u][i];
	level[v]=level[u]+1;
	dfs(v);
	range[u].first=min(range[u].first,range[v].first);
	range[u].second=max(range[u].second,range[v].second);
      } else
	ok=0;
    }
    
    if(ok){
      byLevel[level[u]].push_back(u);
    }
  }
};


vector<int> transform(vector<int> &x){
  
  int n=x.size();
  vector<int> y;
  int c=0;
  for(int i=0;i<n-1;i++){
    c++;
    if(x[i]!=x[i+1]){
      for(int j=0;j<1LL*c*(c-1)/2;j++){
	y.push_back(0);
	if(y.size()==n)
	  return y;
      }
      c=0;
    }
  }
  c++;
  for(int j=0;j<1LL*c*(c-1)/2;j++){
    y.push_back(0);
    if(y.size()==n)
      return y;
  }
  
  Trie<2> T;
  for(auto &v:x)
    T.insert(v);

  T.dfs(0);

  
  for(int i=29;i>=0;i--){
    for(auto &u:T.byLevel[i]){
      int a=T.go[u][0],b=T.go[u][1];
      for(int j=T.range[a].first;j<=T.range[a].second;j++){
	for(int k=T.range[b].first;k<=T.range[b].second;k++){
	  y.push_back(T.val[j]^T.val[k]);
	}
      }
    }
    if(y.size()>=n) break;
  }
  sort(y.begin(),y.end());
  vector<int> res;
  for(int i=0;i<n;i++){
    res.push_back(y[i]);
  }
  
  return res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t; cin>>t;
  while(t--){
    int n,q; cin>>n>>q;
    vector<int> x(n);
    for(auto &v:x) cin>>v;

    sort(x.begin(),x.end());
    
    vector<int> ans;
    while(true){
      ans.push_back(x[n-1]-x[0]);
      if(x[n-1]==0) break;
      x=transform(x);
    }
    
    while(q--){
      int xi; cin>>xi;
      if(xi<ans.size()){
	cout<<ans[xi]<<'\n';
      } else cout<<"0\n";
    }
  }
}
