#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX=3001;
const ll mod=998244353;

int dp[MAX][MAX];

vector<int> primes[MAX];

int n;
vector<int> x;

int getX(int xmax,int xmin){

  if(dp[xmax][xmin]!=-1)
    return dp[xmax][xmin];

  if(xmax==xmin)
    return dp[xmax][xmin]=xmax;

  // if(xmax<xmin)
  //   return dp[xmax][xmin]=getX(xmin,xmax);

  int ans=0;
  for(int p:primes[xmax]){
    if(xmin%p==0) ans=max(ans,getX(xmax-1,xmin-1));
    else ans=max(ans,getX(xmax-1,xmin));
  }
  return dp[xmax][xmin]=ans;
}

vector<int> pref;

int getRange(int l,int r){
  if(r<l) return 0;
  return pref[r]-pref[l-1];
}

int main(){

  for(int i=2;i<MAX;i++){
    int a=i;
    for(int j=2;j*j<=i;j++){
      if(a%j==0){
	primes[i].push_back(j);
	while(a%j==0){
	  a/=j;
	}
      }
    }
    if(a!=1)
      primes[i].push_back(a);
  }

  memset(dp,-1,sizeof dp);

  for(int i=1;i<MAX;i++){
    for(int j=i;j<MAX;j++){
      dp[j][i]=getX(j,i);
    }
  }

  vector<ll> pot2;
  pot2.push_back(1);
  for(int i=1;i<MAX;i++){
    pot2.push_back((pot2.back()*2)%mod);
  }
  
  int t; cin>>t;
  while(t--){
    cin>>n;
    x.resize(n);
    for(auto &v:x) cin>>v;
    pref.assign(n+1,0);
    for(auto &v:x)
      pref[v]++;
    
    for(int i=1;i<=n;i++)
      pref[i]+=pref[i-1];
    
    ll ans=0;

    sort(x.begin(),x.end());
    x.erase(unique(x.begin(),x.end()),x.end());

    for(int i=0;i<x.size();i++){
      ll ti=(pot2[getRange(x[i],x[i])]-1+mod)%mod;
      
      ans=(ans+(ti*dp[x[i]][x[i]])%mod)%mod;
  
      for(int j=i+1;j<x.size();j++){

	ll tj=(pot2[getRange(x[j],x[j])]-1+mod)%mod;
	ll tij=pot2[getRange(x[i]+1,x[j]-1)];

	ll pa=(ti*tj)%mod;
	pa=(pa*tij)%mod;
	pa=(pa*dp[x[j]][x[i]])%mod;
        
	ans=(ans+pa)%mod;
      }
    }
    cout<<ans<<endl;
  }
}
