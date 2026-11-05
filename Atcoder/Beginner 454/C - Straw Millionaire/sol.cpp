#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

const int MAX_N=3e5+10;

vector<vi> G;

int ans=0;
bool vis[MAX_N];

void dfs(int u){
  ans++;
  vis[u]=1;
  for(auto &v:G[u]){
    if(!vis[v])
      dfs(v);
  }
}

int main(){
  int n,m; cin>>n>>m;
  G.resize(n+1);
  for(int i=0;i<m;i++){
    int a,b; cin>>a>>b;
    G[a].push_back(b);
  }
  dfs(1);
  cout<<ans<<endl;
}
