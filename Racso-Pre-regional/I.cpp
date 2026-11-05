#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=998244353;

vector<ll> berries;

const int MAX_N=62;
ll dp[MAX_N][3];

ll prefix(ll n,ll x){ 
  dp[n][0]=dp[n][1]=1;
  for(ll i=n-1;i>=0;i--){
    for(ll j=0;j<2;j++){
      
      dp[i][j]=dp[i+1][(x&(1LL<<(n-i-1)))==0 && j];

      if(!j || (j && (x&(1LL<<(n-i-1)))))
	dp[i][j]=(dp[i][j]+(berries[i]*dp[i+1][j])%mod)%mod;
    }
  }
  return dp[0][1];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n; cin>>n;
  berries.resize(n);
  for(auto &v:berries) cin>>v;

  reverse(berries.begin(),berries.end());
  int q; cin>>q;
  while(q--){
    ll a,b; cin>>a>>b;

    // num=binary(b,n);
    ll ans=prefix(n,b);

    // num=binary(a-1,n);
    ans=(ans-prefix(n,a-1)+mod)%mod;
    cout<<ans<<'\n';
  }
}
