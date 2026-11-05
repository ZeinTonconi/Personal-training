#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
const int MAX_N=2e5+10;
const int E=20;

const int MAX_M=(1<<20)+1;

int freq[MAX_M];
int child[MAX_M];
int mask[MAX_N];
ll prop[MAX_N];

int val[MAX_N];
ll ans[MAX_N];

struct CentroidDecomposition{
  int n;
  vector<vi> adj;
  vi sz, par, depth;
  vector<bool> removed;
  vector<vector<pair<int,int> > > ancestors;

  CentroidDecomposition(int n): n(n), adj(n), sz(n), par(n,-1),
				depth(n), removed(n,false),
				ancestors(n) {}

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

  int get_centroid(int v,int p, int total){
   for(int u:adj[v]){
      if(u==p || removed[u]) continue;
      if(sz[u]>total/2)
	return get_centroid(u,v,total);
    }
   return v;
  }

  void decompose(int entry,int p=-1, int dep=0){
    int total=get_size(entry,-1);
    int c=get_centroid(entry,-1,total);

    par[c]=p;
    depth[c]=dep;

    solve_centroid_tree(c);
    removed[c]=true;

    for(int u:adj[c]){
      if(!removed[u])
	decompose(u,c,dep+1);
    }
  }

  void build(){
    decompose(0);
  }


  void frequency(int v,int p,int c,int d){
    if(p!=-1)
      freq[d]++;
    mask[v]=d;
    for(auto &u:adj[v]){
      if(!removed[u] && u!=p)
	frequency(u,v,c,d^val[u]);
    }
  }
  void getSubtree(int v,int p){
    child[mask[v]]++;
    for(auto &u:adj[v]){
      if(!removed[u] && u!=p)
	getSubtree(u,v);
    }
  }
  void clearChild(int v,int p){
    child[mask[v]]=0;
    for(auto &u:adj[v]){
      if(!removed[u] && u!=p)
	clearChild(u,v);
    }
  }
  void getAns(int v,int p,int c){

    if(__builtin_popcount(mask[v]^val[c])<=1){
      prop[v]++;
      prop[c]++;
    }
    
    int newMask=mask[v]^val[c];
    prop[v]+=freq[newMask]-child[newMask];
    
    for(int i=0;i<E;i++){
      newMask=(1<<i)^mask[v]^val[c];
      prop[v]+=freq[newMask]-child[newMask];
    }
    
    for(auto &u:adj[v]){
      if(!removed[u] && u!=p){
	getAns(u,v,c);
      }
    }
  }

  void propagate(int v,int p){
    for(auto &u:adj[v]){
      if(!removed[u] && u!=p){
	propagate(u,v);
      }
    }
    if(p!=-1){
      ans[v]+=prop[v];
      prop[p]+=prop[v];
      prop[v]=0;
    }
    freq[mask[v]]=0;
    mask[v]=0;
  }
  
  void solve_centroid_tree(int c){
    
    //cout<<"Centroid: "<<c<<endl;

    frequency(c,-1,c,0);

    for(auto &u:adj[c]){
      if(removed[u]) continue;
      getSubtree(u,c);

      getAns(u,c,c);
      
      clearChild(u,c);
    }

    /*for(int i=0;i<n;i++){
      cout<<bitset<5>(mask[i])<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
      cout<<prop[i]<<" ";
    }
    cout<<endl;*/

    propagate(c,-1);
    ans[c]+=prop[c]/2;
    prop[c]=0;
    /*for(int i=0;i<n;i++){
      cout<<ans[i]<<" ";
    }
    cout<<endl;*/
  }
  
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n; cin>>n;

  CentroidDecomposition G(n);
  for(int i=0;i<n-1;i++){
    int a,b; cin>>a>>b;
    a--; b--;
    G.add_edge(a,b);
  }
  string x; cin>>x;
  for(int i=0;i<n;i++){
    val[i]=(1<<(x[i]-'a'));
  }
  G.build();

  for(int i=0;i<n;i++){
    cout<<ans[i]+1<<" ";
  }

  cout<<'\n';
  
}
