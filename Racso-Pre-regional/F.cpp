#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//const double EPS=1e-15;

bool check(vector<ll> &x,vector<ll> &shelt, ll mid, int res){
  vector<ll> y;
  int r=shelt.size();
  int n=x.size();
  vector<ll> cov(n+1);
  
  for(int i=0;i<shelt.size();i++){
    ll l=shelt[i]-mid;
    ll r=shelt[i]+mid;
    auto it=lower_bound(x.begin(),x.end(),l);
    int left=it-x.begin();

    auto itr=upper_bound(x.begin(),x.end(),r);
    int right=itr-x.begin();

    cov[left]++;
    cov[right]--;
  }
  int c=0;
  for(int i=0;i<n;i++){
    c+=cov[i];
    if(c==0) y.push_back(x[i]);
  }

  int extra=0;
  int j=0;
  while(j<y.size()){
    auto it=upper_bound(y.begin(),y.end(),y[j]+2*mid);
    j=it-y.begin();
    extra++;
  }
  return extra<=res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t; cin>>t;
  while(t--){
    int n,m; cin>>n>>m;
    vector<ll> x(n);
    for(auto &v:x) cin>>v;
    for(auto &v:x) v*=2;
    
    sort(x.begin(),x.end());
    while(m--){
      int k,rr; cin>>k>>rr;
      vector<ll> shelt(rr);
      for(auto &v:shelt) cin>>v;
      for(auto &v:shelt) v*=2;
      
      ll l=0,r=1e9;

      for(int i=0;i<100;i++){
	ll mid=(l+r)/2;

	if(check(x,shelt,mid,k-rr)) r=mid;
	else l=mid;
      }
      
      cout<<fixed<<setprecision(12)<<r/2.0<<" ";
     
    }
    cout<<endl;
  }
}
