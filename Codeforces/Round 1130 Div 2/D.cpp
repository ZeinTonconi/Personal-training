#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;

struct Tree{
  vector<vi> G;
  int N;
  Tree(int n):N(n),G(n){}

  void add_edge(int a,int b){
    G[a].push_back(b);
    G[b].push_back(a);
  }

  vector<vi> dp;
  vector<int> act;

  void dfs(int v,int p,int a){

    if(dp[v][a]!=-1) return;

    int ans=a;
    if(a==1){
      for(auto &u:G[v]){
	if(u!=p){
	  dfs(u,v,0);
	  ans+=dp[u][0];
	  
	}
      }
    } else{
      for(auto &u:G[v]){
	if(u!=p){
	  dfs(u,v,0);
	  dfs(u,v,1);
	  ans+=max(dp[u][0],dp[u][1]);
	}
      }
    }
    dp[v][a]=ans;
  }
  
  void get_mis(){
    dp.assign(N,vi(2,-1));
    act.assign(N,-1);
    dfs(1,1,1);
    dfs(1,1,0);

    int s=1,a=(dp[1][1]>dp[1][0]);

    queue<ii> q;
    q.push(ii(s,a));
    while(!q.empty()){
      auto [v,a]=q.front();
      act[v]=a;
      q.pop();
      for(auto &u:G[v]){
	if(act[u]==-1){
	  if(a==1) q.push({u,0});
	  else{
	    if(dp[u][1]>dp[u][0]) q.push({u,1});
	    else q.push({u,0});
	  }
	}
      }
    }
  }
};


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t; cin>>t;
  while(t--){
    int k; cin>>k;

    int idT=-1,idV=1;
    
    for(int i=1;i<=k;i++){
      int n; cin>>n;
      Tree ti(n+1);
      for(int j=0;j<n-1;j++){
	int a,b; cin>>a>>b;
	ti.add_edge(a,b);
      }

      ti.get_mis();
      if(idT==-1){
	for(int j=1;j<=n;j++){
	  if(!ti.act[j]){
	    idT=i;
	    idV=j;
	  }
	}
      }
    }
    if(idT==-1) idT=1;
    for(int i=1;i<=k;i++){
      if(i==idT) continue;
      else cout<<idT<<" "<<idV<<" "<<i<<" 1\n";
    }
    
  }
}
