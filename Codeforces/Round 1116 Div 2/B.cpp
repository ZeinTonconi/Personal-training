#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=998244353;
const int MAX_N=2e5+10;
string x;

ll dp[MAX_N][5][5];

ll tryTile(int id,int curr,int prev, int prevSum);

ll tiles(int id,int prev,int prevSum){
  if(dp[id][prev][prevSum]!=-1) return dp[id][prev][prevSum];
  if(id==x.size()) return 1;

  ll ans=0;
  if(x[id]=='?'){
    ans=(ans+tryTile(id,1,prev,prevSum))%mod;
    ans=(ans+tryTile(id,0,prev,prevSum))%mod;
  }
  else
    ans=(ans+tryTile(id,x[id]-'0',prev,prevSum))%mod;
  
  return dp[id][prev][prevSum]=ans;
  
}

ll tryTile(int id,int curr,int prev, int prevSum){

  if(curr+prev==prevSum) return 0;
  
  return tiles(id+1,curr,curr+prev);
}

int main(){
  int t; cin>>t;
  while(t--){
    int n; cin>>n;
    cin>>x;
    for(int i=0;i<=n;i++){
      for(int j=0;j<=4;j++){
	for(int k=0;k<=4;k++)
	  dp[i][j][k]=-1;
      }
    }
    cout<<tiles(0,3,0)<<endl;
  }
}
