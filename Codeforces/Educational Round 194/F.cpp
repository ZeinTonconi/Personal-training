
/* Check only for one vertex cycles
   It only matters the simple cycles, as we are doing for all the vertex as
   start point so we are going to all the simple cycles
   As there are only 10 extra edges, we can do backtracking it wont be expensive
   because the only vertext that increase my recursion it is bounded
   -> The 3-degree vertex will have 1 extra decision and in total we are going
   to have 18 extra decisions so when all the vertex are 3-degree we are going
   to have 2^10 decisions which is managable.
*/

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

const int MAX_N=3010;

vector<vi> G,H;
int to[MAX_N],from[MAX_N];
int degree[MAX_N];

bool alive[MAX_N];
bool vis[MAX_N];

bool us[MAX_N];

int n,m,ns;
int pa[MAX_N];

void init(){
  for(int i=0;i<=n;i++)
    pa[i]=i;
  ns=n;
}

int findset(int i){
  return (pa[i]==i)?i:pa[i]=findset(pa[i]);
}

bool issameset(int i,int j){
  return findset(i)==findset(j);
}

void unionset(int i,int j){

  if(!issameset(i,j)){
    int u=findset(i);
    int v=findset(j);
    pa[u]=v;
    ns--;
  }
}

bool check(){
  init();
  for(int i=0;i<m;i++){
    if(!us[i])
      unionset(from[i],to[i]);
  }
  
  return ns==1;
}

bool dfs(int u,int p,int d){
  if(d>10) return 0;
  vis[u]=1;
  bool ans=0;
  for(auto &id:H[u]){
    int v=(from[id]==u?to[id]:from[id]);
    if(p==v) continue;
    us[id]=1;
    if(vis[v]){
      ans|=check();
    } else {
      ans|=dfs(v,u,d+1);
    }
    us[id]=0;
  }
  vis[u]=0;
  return ans;

}
void reset(){
  G.clear(); G.resize(n+1);
  H.clear(); H.resize(n+1);
  for(int i=0;i<=n;i++) alive[i]=1;
  for(int i=0;i<=n;i++) degree[i]=0;
 
}

int main(){
  int t; cin>>t;
  while(t--){
    cin>>n>>m;
    reset();
    for(int i=0;i<m;i++){
      int a,b; cin>>a>>b;
      G[a].push_back(i);
      G[b].push_back(i);
      to[i]=a; from[i]=b;
      degree[a]++; degree[b]++;
    }

    queue<int> q;
    for(int i=1;i<=n;i++){
      if(degree[i]==1){
	q.push(i);
	degree[i]--;
	alive[i]=0;
      }
    }
    while(!q.empty()){
      int u=q.front();
      q.pop();
      for(auto &id:G[u]){
	int v=(to[id]==u?from[id]:to[id]);
	if(alive[v]){
	  degree[v]--;
	  if(degree[v]==1){
	    alive[v]=0;
	    q.push(v);
	  }
	}
      }
    }

    for(int i=1;i<=n;i++){
      if(!alive[i]) continue;
      for(auto &id:G[i]){
	int v=(to[id]==i?from[id]:to[id]);
	if(alive[v]){
	  H[i].push_back(id);
	}
      }
    }

    bool ok=0;
    for(int i=1;i<=n;i++){
      if(dfs(i,0,0)){
	ok=1;
	break;
      }
    }
    if(ok) cout<<"YES\n";
    else cout<<"NO\n";
  }
}
