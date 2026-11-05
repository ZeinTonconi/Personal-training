#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int MAX_N=1e6+10;

ll p[MAX_N],w[MAX_N];
ll sumP[MAX_N],sumW[MAX_N];

int anc[MAX_N];

struct Candidate{
  ll p, w, x;
};

class Compare{
 public:
 bool operator()(Candidate a, Candidate b){
   // true if  a and b must swap
   // false if a is before b, the order is correct
   return (b.p*a.w<b.w*a.p);
 }
};

int pa[MAX_N];
vector<list<int> >  ord;

void init(int n){
  
  ord.resize(n+1);
  for(int i=0;i<=n;i++){
    pa[i]=i;
    sumP[i]=p[i];
    sumW[i]=w[i];
    ord[i].push_back(i);
  }
}

int findset(int i){
  return (pa[i]==i?i:pa[i]=findset(pa[i]));
}

bool issameset(int i,int j){
  return findset(i)==findset(j);
}


void unionset(int i,int j){
  if(!issameset(i,j)){
    int u=findset(i), v=findset(j);
    sumP[v]+=sumP[u];
    sumW[v]+=sumW[u];
    pa[u]=v;
    ord[v].splice(ord[v].end(),ord[u]);
    
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int n; cin>>n;
  for(int i=1;i<=n;i++)
    cin>>p[i];

  for(int i=1;i<=n;i++)
    cin>>w[i];

  int m; cin>>m;

  memset(anc,-1,sizeof anc);
  
  for(int i=0;i<m;i++){
    int a,b; cin>>a>>b;
    anc[a]=b;
  }

  for(int i=1;i<=n;i++){
    if(anc[i]==-1) anc[i]=0;
  }

  priority_queue<Candidate, vector<Candidate>, Compare> pq;

  for(int i=1;i<=n;i++){
    pq.push({p[i],w[i],i});
  }
  
  init(n);

  while(!pq.empty()){
    auto u = pq.top();

    pq.pop();

    if(sumP[findset(u.x)]!=u.p || sumW[findset(u.x)]!=u.w) continue;
    
    if(issameset(findset(u.x),anc[findset(u.x)])) continue;

    unionset(findset(u.x),anc[findset(u.x)]);
    
    pq.push({sumP[findset(u.x)],sumW[findset(u.x)],findset(u.x)});
  }

  
  ll t=0;
  ll ans=0;
  for(auto &v:ord[findset(0)]){
    ans+=(t+p[v])*w[v];
    t+=p[v];
  }
  cout<<ans<<'\n';
  
}
