#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

struct CentroidDecomposition{
  int n;
  vector<vi> adj;
  vi sz, par, depth;
  vector<bool> removed;
  vector<vector<pair<int,int> > > ancestors;

  vector<multiset<int> > distances;

  CentroidDecomposition(int n):
    n(n), adj(n), sz(n), par(n,-1), depth(n), removed(n,false),ancestors(n),
    distances(n)
  {}

  void add_edge(int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int get_size(int v,int p){
    sz[v]=1;
    for(int u:adj[v]){
      if(u==p || removed[u]) continue;
      sz[v]+=get_size(u,v);
    }
    return sz[v];
  }

  int get_centroid(int v,int p,int total){
    for(int u:adj[v]){
      if(u==p || removed[u]) continue;
      if(sz[u] > total/2)
	return get_centroid(u,v,total);
    }
    return v;
  }
  void collect_distance(int v,int p,int d,int c){
    ancestors[v].push_back({c,d});
    for(int u:adj[v]){
      if(u==p || removed[u]) continue;
      collect_distance(u,v,d+1,c);
    }
  }
  void decompose(int entry, int p=-1, int dep=0){
    int total=get_size(entry,-1);
    int c=get_centroid(entry,-1,total);

    par[c]=p;
    depth[c]=dep;

    collect_distance(c,-1,0,c);
    removed[c]=true;
    for(int u:adj[c]){
      if(!removed[u])
	decompose(u,c,dep+1);
    }
  }

  void build(){
    decompose(0);
  }
};


void insertDis(int v, CentroidDecomposition &cd){
  for(auto &[c,dis]:cd.ancestors[v]){
    cd.distances[c].insert(dis);
  }
}

void eraseDist(int v,CentroidDecomposition &cd){
  for(auto &[c,dis]:cd.ancestors[v]){
    auto it=cd.distances[c].find(dis);
    cd.distances[c].erase(it);
  }
}

int query(int v, CentroidDecomposition &cd){
  int ans=-1;
  for(auto &[c,dis]:cd.ancestors[v]){
    if(!cd.distances[c].empty()){
      if(ans==-1) ans=*cd.distances[c].begin()+dis;
      ans=min(ans,*cd.distances[c].begin()+dis);
    }
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n; cin>>n;
  CentroidDecomposition cd(n);

  vector<bool> colors(n,0);
  
  for(int i=0;i<n-1;i++){
    int a,b; cin>>a>>b;
    a--; b--;
    cd.add_edge(a,b);
  }

  cd.build();
  int q; cin>>q;
  while(q--){
    int op, v; cin>>op>>v;
    v--;
    if(op==0){
      if(colors[v]==0) insertDis(v,cd);
      else eraseDist(v,cd);
      colors[v]=colors[v]^1;
    } else{
      cout<<query(v,cd)<<"\n";
    }
  }
}
