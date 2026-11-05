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

int main(){
  int n,m; cin>>n>>m;
  map<int,int> occ;
  for(int i=0;i<m;i++){
    int a; cin>>a;
    occ[a]++;
  }
  ll ans=1;
  for(auto &v:occ){
    if(n/v.first<v.second)
      ans=(ans*pot(2,v.second/2+1))%mod;
  }
  cout<<ans<<endl;
}
