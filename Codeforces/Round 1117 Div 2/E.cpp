#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MAX=1e17;

struct ProfitFloor{
  int project;
  int id;
  ll profit,min;
  
  bool operator < (const ProfitFloor &o) const {
    return min>o.min;
  }
};

struct Project{
  int n;
  vector<ll> a,b;
  Project(int _n):n(_n){
    a.resize(n);
    b.resize(n);
  }
  ll cost(int i){
    return b[i]-a[i];
  } 
};

bool check(int a,int b,ll k, Project &p){
  for(int i=a+1;i<=b;i++){
    if(k<p.a[i]) return 0;
    k+=p.cost(i);
  }
  return 1;
}


ll getMin(int a,int b, Project &p){

  ll l=-1,r=MAX;
  while(r-l>1){
    ll mid=(l+r)/2;
    if(check(a,b,mid,p))
      r=mid;
    else
      l=mid;
  }
  return r;
  
}

vector<ProfitFloor> getProfitFloor(Project &p, int project){
  ll sum=0;
  int l=-1;
  vector<ProfitFloor> pf;
  for(int i=0;i<p.n;i++){
    sum+=p.cost(i);
    if(sum>=0){
      pf.push_back({project,l,sum,getMin(l,i,p)});
      sum=0;
      l=i;
    }
  }
  pf.push_back({project, l,sum,-1});
  return pf;
}

void update(int &ans,int &id,int pans, int i){
  if(ans<pans){
    ans=pans;
    id=i;
  } else if(ans==pans){
    id=min(id,i);
  }
}

int main(){
  int t; cin>>t;
  while(t--){
    int n;
    ll x; cin>>n>>x;
    vector<Project> proj;
    for(int i=0;i<n;i++){
      int k; cin>>k;
      Project a(k);
      for(auto &v:a.a) cin>>v;
      for(auto &v:a.b) cin>>v;
      proj.push_back(a);
    }
    vector<vector<ProfitFloor> > profitFloor(n);
    for(int i=0;i<n;i++){
      vector<ProfitFloor> pf=getProfitFloor(proj[i],i);
      reverse(pf.begin(),pf.end());
      profitFloor[i]=pf; 
    }
    priority_queue<ProfitFloor> pq;
    for(int i=0;i<n;i++){
      if(profitFloor[i].back().min!=-1)
	pq.push(profitFloor[i].back());
    }
    
    while(!pq.empty() && pq.top().min<=x){
      ProfitFloor t=pq.top();
      pq.pop();
      x+=t.profit;
      profitFloor[t.project].pop_back();
      if(profitFloor[t.project].back().min!=-1)
	pq.push(profitFloor[t.project].back());
      
    }
    
    int ans=-1,id=-1;
    for(int i=0;i<n;i++){
      
      ProfitFloor last=profitFloor[i].back();
      int pans=last.id+1;
      ll xAux=x;
      for(int j=last.id+1;j<proj[i].n;j++){
	if(xAux<proj[i].a[j])
	  break;
	xAux+=proj[i].cost(j);
	pans++;
      }
      update(ans,id,pans,i);
    }
    cout<<ans<<" "<<id+1<<endl;
  }
}
