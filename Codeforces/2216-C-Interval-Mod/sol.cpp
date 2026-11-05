#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(){
  int t; cin>>t;
  while(t--){

    int n,k,p,q; cin>>n>>k>>p>>q;
    vector<int> x(n);
    for(auto &v:x) cin>>v;
    vector<ll> pref,suf(n+1);
    pref.push_back(0);
    for(int i=0;i<n;i++)
      pref.push_back(pref[i]+min(x[i]%p, x[i]%q%p));

    suf[n]=0;
    for(int i=n-1;i>=0;i--)
      suf[i]=suf[i+1]+min(x[i]%p, x[i]%q%p);
    
    ll slidp=0;
    ll slidqp=0;
    
    for(int i=0;i<k;i++){
      slidp+=x[i]%p;
      slidqp+=x[i]%q%p;
    }

    ll ans=min(slidp,slidqp)+suf[k];
    
    for(int i=k;i<n;i++){
      slidp-=x[i-k]%p;
      slidqp-=x[i-k]%q%p;

      slidp+=x[i]%p;
      slidqp+=x[i]%q%p;
      ans=min(ans,min(slidp,slidqp)+pref[i-k+1]+suf[i+1]);
      
    }
    
    cout<<ans<<endl;
    
  }
}
