#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef long long ll;

struct Range{
  int l,r;
  ll init,need;
  Range(){
    init=l=r=need=0;
  }
  
};

const ll MAX=1e16;
const int MAX_N=2e5+10;

int pa[MAX_N];
int minEle[MAX_N];

void init(int n){
  for(int i=0;i<=n;i++){
    pa[i]=minEle[i]=i;
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
    minEle[v]=min(minEle[u],minEle[v]);
  }
}

struct Fenwick{
  int N;
  vector<ll> tr;
  Fenwick(int _n):N(_n){
    tr.assign(N+1,0);
  }

  int lsone(int s){
    return s&(-s);
  }
  
  void add(int id,ll v){
    for(;id<=N;id+=lsone(id))
      tr[id]+=v;
  }

  ll sum(int id){
    ll s=0;
    for(;id;id-=lsone(id))
      s+=tr[id];
    return s;
  }

  ll sumLR(int l,int r){
    return sum(r)-sum(l);
  }
  
};


bool check(ll mid, vector<Range> ofi, vector<int> h, ll k){
  int m=h.size();
  int n=ofi.size();
  for(auto &v:ofi){
    v.need=max(0LL,mid-v.init);
  }

  init(m);

  Fenwick ft(m);
  
  for(auto &o:ofi){

    int i=minEle[findset(o.r-1)];
    o.need-=ft.sumLR(o.l,o.r);
    while(o.need>0){
      if(h[i]<o.need){
	ft.add(i+1,h[i]);
	o.need-=h[i];
	h[i]=0;
	if(i-1<o.l) return false;
	
	unionset(i,i-1);
	i=minEle[findset(i)];
      } else{
	h[i]-=o.need;
	ft.add(i+1,o.need);
	o.need=0;
      }
    }
    
  }
  return ft.sum(m)<=k;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int m,n;
  ll k;
  cin>>m>>n>>k;

  vector<int> x(m),h(m);
  for(int &v:x) cin>>v;
  for(int &v:h) cin>>v;

  vector<Range> ofi(n);
  for(auto &v:ofi){
    cin>>v.l>>v.r;
    v.l--;
  }

  vector<ll> pref(m+1,0);
  for(int i=0;i<m;i++)
    pref[i+1]=pref[i]+x[i];

  for(auto &v:ofi)
    v.init=pref[v.r]-pref[v.l];

  for(int i=0;i<m;i++)
    h[i]-=x[i];
  
    
  sort(ofi.begin(),ofi.end(),[&](Range a,Range b){
    if(a.r==b.r)
      return a.l<b.l;
    return a.r<b.r;
  });

  ll l=0,r=MAX;
  while(r-l>1){
    ll mid=(l+r)/2;
    if(check(mid,ofi,h,k))
      l=mid;
    else
      r=mid;
  }
  cout<<l<<endl;
}
