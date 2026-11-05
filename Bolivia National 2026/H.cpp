/*
  Take careful the LCA preprocessing the parent of the root cannot be -1 as
  we later we are using pa[u][i]=pa[pa[u][i-1][i-1] so when i=1, it will be
  pa[-1][0] and not necessary will crash, in this problem you get WA instead
  of RE so be careful. One way to compile the code and take care or detect
  this kind of things is:
  g++ -std=c++20 -O1 -g \
    -fsanitize=address,undefined \
    -fno-omit-frame-pointer main.cpp -o main

  Another way to do the intersection of to paths is to use the median of
  three vertices, which is the vertex where for three vertices (x,y,z) the
  paths P(x,y), P(x,z) and P(y,z) intersect. The median is the vertex which
  is lowest in the lca of (x,y), (x,z), (y,z). So if we take a path P1 (a,b)
  and we take the median with a vertex c, the median will mean that the path
  P2 (c,d) will start intersecting at the median as it is entering to the
  path P1, and the median of (a,b,d) will be when they separate. So after
  that we need to check if this median truly belongs to the P2 path, and
  we can do this with the distance checking, some vertex x belongs to P2 if
  dis(c,x)+dist(x,d) = dist(c,d) we are splitting the path, so if their
  intersection is nonempty, then both medians must be on the path P2, if the
  intersection is empty then neither of medians belongs to P2.
  You can also see the LCA as the branching point of to paths from the root
  
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const int MAX_N=2e5+10;

int pa[MAX_N];
int sz[MAX_N];

void init(int n){
  for(int i=0;i<=n;i++){
    pa[i]=i;
    sz[i]=1;
  }
}

int findset(int i){
  return pa[i]==i?i:pa[i]=findset(pa[i]);
}

bool issameset(int i,int j){
  return findset(i)==findset(j);
}

void unionset(int i,int j){
  if(!issameset(i,j)){
    int u=findset(i),v=findset(j);
    pa[u]=v;
    sz[v]+=sz[u];
  }
}

set<ii> bridges;

vector<vi> G;

int tin[MAX_N], low[MAX_N];
bool vis[MAX_N];
int timer=0;

void dfs(int v,int p=-1){
  vis[v]=1;
  tin[v]=low[v]=timer++;
  bool parent=false;
  for(int to:G[v]){
    if(to==p && !parent){
      parent=true;
      continue;
    }
    if(vis[to]){
      low[v]=min(low[v],tin[to]);
    } else{
      dfs(to,v);
      low[v]=min(low[v],low[to]);
      if(low[to]>tin[v]){
	bridges.insert(ii(min(v,to),max(v,to)));
      }
    }
  }
}

vector<vi> T;

void scc(int u){
  vis[u]=1;
  for(auto &v:G[u]){
    if(!vis[v] && bridges.find(ii(min(u,v),max(u,v)))==bridges.end()){
      unionset(u,v);
      scc(v);
    }
  }
}

const int B=20;

int up[MAX_N][B];
int level[MAX_N];
int weightSum[MAX_N];

void dfsUp(int u,int p){
  up[u][0]=p;
  weightSum[u]+=sz[u];
  level[u]++;
  for(int i=1;i<B;i++){
    up[u][i]=up[up[u][i-1]][i-1];
  }
  for(auto &v:T[u]){
    if(v!=p){
      weightSum[v]=weightSum[u];
      level[v]=level[u];
      dfsUp(v,u);
    }
  }
}

int lca(int u,int v){
  if(level[u]<level[v]) swap(u,v);
  int dif=level[u]-level[v];
  for(int i=0;i<B;i++){
    if(dif&(1<<i))
      u=up[u][i];
  }
  if(u==v) return u;
  for(int i=B-1;i>=0;i--){
    if(up[u][i]!=up[v][i]){
      u=up[u][i];
      v=up[v][i];
    }
  }
  return up[u][0];
}

int getSize(int a,int b){
  int l=lca(a,b);
  return weightSum[a]+weightSum[b]-2*weightSum[l]+sz[l];
}

int main(){
  int n,m,q; cin>>n>>m>>q;
  G.assign(n+1,vi());
  for(int i=0;i<m;i++){
    int a,b; cin>>a>>b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  dfs(1);

  init(n);
  T.assign(n+1,vi());
  memset(vis,0,sizeof vis);
  for(int i=1;i<=n;i++){
    if(!vis[i]){
      scc(i);
    }
  }

  for(auto &[a,b]:bridges){
    T[findset(a)].push_back(findset(b));
    T[findset(b)].push_back(findset(a));
  }

  dfsUp(findset(1), findset(1));


  while(q--){
    int a,b,c,d;
    cin>>a>>b>>c>>d;

    a=findset(a);
    b=findset(b);
    c=findset(c);
    d=findset(d);
    int lcaAB=lca(a,b);
    int lcaCD=lca(c,d);

    if(level[lcaCD]>level[lcaAB]){
      swap(a,c);
      swap(b,d);
      swap(lcaAB,lcaCD);
      
    }

    ll c1=getSize(a,b);
    ll c2=getSize(c,d);

    vector<int> A={a,b};
    vector<int> B={c,d};
    set<int> cand;
    for(int i=0;i<2;i++){
      for(int j=0;j<2;j++){
	int lcaIJ=lca(A[i],B[j]);
	if(level[lcaIJ]>=level[lcaAB]){
	  cand.insert(lcaIJ);
	}
      }
    }
    if(cand.size()==0){
      cout<<"0\n";
      continue;
    }

    ll inter=-1;
    cand.erase(lcaAB);
    if(cand.size()==2){
      auto it=cand.begin();
      inter=getSize(*it,*next(it));
    }
    if(cand.size()==1){
      auto it=cand.begin();
      inter=getSize(lcaAB,*it);
    }
    if(cand.size()==0){
      inter=sz[lcaAB];
    }
    ll ans=(c1-inter)*(c2-inter);
    cout<<ans<<endl;
  }
  
}
 
