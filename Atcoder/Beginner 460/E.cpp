#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod=998244353;

ll pot(ll b,ll e){
  if(e==0) return 1;
  if(e==1) return b;
  ll aux=pot(b,e/2);
  aux=(aux*aux)%mod;
  if(e%2!=0) aux=(aux*b)%mod;
  return aux;
}

int numberDigits(ll n){
  int c=0;
  while(n!=0){
    n/=10;
    c++;
  }
  return c;
}


int main(){
  int t; cin>>t;
  
  vector<ll> pot10;
  pot10.push_back(1);
  for(int i=1;i<19;i++){
    pot10.push_back(10LL*pot10.back());
  }
  while(t--){
    ll n,m; cin>>n>>m;

    ll ans=0;

    ll p=1;
    
    for(int i=1;i<=numberDigits(n);i++){
      p=(p*10LL)%m;
      
      ll g=__gcd((p-1+m)%m,m);
      ll gPrime=m/g;

      ll numberY;
      if(i==numberDigits(n))
	numberY=n-pot10[i-1]+1;
      else
	numberY=pot10[i]-1-pot10[i-1]+1;
      ans+=(((n/gPrime)%mod)*(numberY%mod))%mod;
      ans%=mod;
    }
    cout<<ans<<endl;
    
  }
}
