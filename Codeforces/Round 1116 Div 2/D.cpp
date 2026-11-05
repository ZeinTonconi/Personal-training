#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=998244353;
const int MAX_N=1e6+10;

ll pot(ll b,ll e){
  if(e==1) return b;
  if(e==0) return 1;
  ll aux=pot(b,e/2);
  aux=(aux*aux)%mod;
  if(e%2!=0) aux=(aux*b)%mod;
  return aux;
}


int main() {
  int t; cin>>t;

  vector<ll> fac,inv;
  fac.push_back(1);
  inv.push_back(1);
  for(ll i=1;i<MAX_N;i++){
    fac.push_back((fac.back()*i)%mod);
    inv.push_back(pot(fac.back(),mod-2));
  }

  auto combi=[&](int n,int k){
    return (ll)(((inv[k]*inv[n-k])%mod)*fac[n])%mod;
  };
  
  while(t--){
    int n; cin>>n;
    string x; cin>>x;
    x+='$';
    int z=0,o=0;
    int zb=0,ob=0;
    for(int i=0;i<n;i++){
      if(x[i]=='0') z++;
      else o++;
      if(x[i]!=x[i+1]){
	if(x[i]=='0') zb++;
	else ob++;
      }
    }
    ll ans;
    if(zb==0 || ob==0) ans=1;
    else
      ans=(combi(z-1,zb-1)*combi(o-1,ob-1))%mod;
    cout<<ans<<endl;
  }
}
