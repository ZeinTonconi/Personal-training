#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod=998244353;
const int MAX_N=2e5+10;

ll pot(ll b,ll e){
  if(e==0) return 1;
  if(e==1) return b;
  ll aux=pot(b,e/2);
  aux=(aux*aux)%mod;
  if(e%2!=0) aux=(aux*b)%mod;
  return aux;
}

int main(){
  vector<ll> fac;
  fac.push_back(1);
  for(int i=1;i<MAX_N;i++){
    fac.push_back((fac.back()*i)%mod);
  }

  int t; cin>>t;
  while(t--){
    int n; cin>>n;
    vector<int> x(n);
    for(auto &v:x) cin>>v;
    sort(x.begin(),x.end());

    vector<ll> suf(n+1,0);
    for(int i=n-1;i>=0;i--){
      suf[i]=suf[i+1]+x[i];
    }

    ll ans=0;
    for(int i=0;i<n;i++){
      ll trees=(fac[n-1]*pot(n-i-1,mod-2))%mod;
      
      ll we=(((suf[i+1]-1LL*(n-i-1)*x[i]))%mod+mod)%mod;

      ans=(ans+(trees*we))%mod;
    }
    cout<<ans<<endl;
    
  }
}
