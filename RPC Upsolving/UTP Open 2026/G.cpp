/*
  given u and v endpoints of the diameter of the tree, for a given vertex y
  the maximum distance to another vertex z is the max of the distance of the
  endpoints
  max(dis(y,z)) = max(dis(y,u), dis(y,v))
*/

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

const int MAX_N=3e5+10;

vector<int> G[MAX_N];;

int s,e;

int pa[MAX_N][30];
int d[MAX_N];
bool vis[MAX_N];

void dfs(int u,int p){
  vis[u]=1;
  pa[u][0]=p;
  for(int i=1;i<20;i++){
    pa[u][i]=pa[pa[u][i-1]][i-1];
  }
  for(auto &v:G[u]){
    if(v!=p) {
      d[v]=d[u]+1;
      dfs(v,u);
    }
  }
}

int lca(int u,int v){
  if(d[u]<d[v]) swap(u,v);
  int dis=d[u]-d[v];
  for(int i=0;i<20;i++){
    if(dis&(1<<i)){
      u=pa[u][i];
    }
  }
  if(u==v) return u;
  for(int i=19;i>=0;i--){
    if(pa[u][i]!=pa[v][i]){
      u=pa[u][i];
      v=pa[v][i];
    }
  }
  return pa[u][0];
  
}

int dist(int a,int b){
  return d[a]+d[b]-2*d[lca(a,b)];
}

int main(){
  int n; cin>>n;
  for(int i=0;i<n-1;i++){
    int a,b; cin>>a>>b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  for(int i=0;i<MAX_N;i++){
    if(!vis[i]) dfs(i,i);
  }

  int ma=0;
  for(int i=0;i<MAX_N;i++){
    if(ma<d[i]){
      ma=d[i];
      s=i;
    }
  }
  ma=0;
  for(int i=0;i<MAX_N;i++){
    if(ma<dist(s,i)){
      ma=dist(s,i);
      e=i;
    }
  }
  
  int prev=dist(s,e);
  cout<<prev<<endl;

  int m; cin>>m;
  while(m--){
    int a,b; cin>>a>>b;
    d[a]=d[b]+1;
    pa[a][0]=b;
    for(int i=1;i<20;i++){
      pa[a][i]=pa[pa[a][i-1]][i-1];
    }
    int as=dist(a,s);
    int ae=dist(a,e);
    if(prev<max(as,ae)){
      prev=max(as,ae);
      if(as>ae)
	e=a;
      else
	s=a;
    }
    cout<<prev<<"\n";
  }
  
}
