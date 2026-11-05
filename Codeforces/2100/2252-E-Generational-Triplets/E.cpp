/*
  The identity that i didnt use but is in the editorial:
  a + c = (a ^ c) + 2 * (a & c)

  and also:
  (a + b + c) % 2 = a ^ b ^ c
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_B=61;
const ll mod=1e9+7;

int bitN[MAX_B];

ll dp[MAX_B][2][2][2][2][2];


ll countB(int id,bool actA, bool actC, bool acc, bool topA, bool topC){

  // cout<<id<<" actA: "<<actA<<" actC: "<<actC<<" acc: "<<acc<<" topA: "<<topA<<" topC: "<<topC<<endl;
  
  if(id==0)
    return !acc;
  
  if(dp[id][actA][actC][acc][topA][topC]!=-1)
    return dp[id][actA][actC][acc][topA][topC];

  ll ans=0;

  int actAC=(actA+actC+acc)%2;
  
  for(int i=0;i<=(topA?bitN[id-1]:1);i++){
    for(int j=0;j<=(topC?bitN[id-1]:1);j++){
      for(int k=0;k<=1;k++){
	if(actAC==(i^j) && (i+j+k)/2==acc)
	  ans=(ans +
	       countB(id-1,i,j,k,
		      (topA && i==bitN[id-1]),
		      (topC && j==bitN[id-1]))
	       )%mod;
      }
    }
  }
  return dp[id][actA][actC][acc][topA][topC]=ans;
}

ll pot(ll b,ll e){
  if(e==1) return b;
  ll aux=pot(b,e/2);
  aux=(aux*aux)%mod;
  if(e%2!=0) aux=(aux*b)%mod;
  return aux;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll inv2=pot(2,mod-2);
  int t; cin>>t;
  while(t--){
    ll n; cin>>n;
    for(ll i=59;i>=0;i--){
      bitN[i]=!!(n&(1LL<<i));
    }
    
    // for(int i=3;i>=0;i--) cout<<bitN[i]<<" ";
    // cout<<endl;

    for(int i=0;i<=60;i++){
      for(int j=0;j<=1;j++){
	for(int k=0;k<=1;k++){
	  for(int l=0;l<=1;l++){
	    for(int u=0;u<=1;u++){
	      for(int v=0;v<=1;v++){
		dp[i][j][k][l][u][v]=-1;
	      }
	    }
	  }
	}
      }
    }
    
    ll ans=(countB(60,0,0,0,1,1)+countB(60,0,0,1,1,1))%mod;
    ans=(ans-1+mod)%mod;
    ans=(ans*inv2)%mod;
    cout<<ans<<'\n';
  }
  
}
