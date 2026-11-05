#include <bits/stdc++.h>
using namespace std;

const int MAX_N=35;
const int MAX_K=55;
const int MAX=1e9;

int dp[MAX_N][MAX_N][MAX_K];

int choco(int a,int b,int res){
  if(a*b<res) return MAX;
  if(a*b==res || res==0) return 0;

  if(dp[a][b][res]!=-1) return dp[a][b][res];

  int ans=MAX;
  for(int i=1;i<a;i++){
    for(int j=0;j<=res;j++){
      if(i*b>=j && (a-i)*b>=res-j)
	ans=min(ans,b*b+choco(i,b,j)+choco(a-i,b,res-j));
    }
  }

  for(int i=1;i<b;i++){
    for(int j=0;j<=res;j++){
      if(a*i>=j && a*(b-i)>=res-j)
	ans=min(ans,a*a+choco(a,i,j)+choco(a,b-i,res-j));
      
    }
    
  }
  return  dp[a][b][res]=ans;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int t; cin>>t;

  memset(dp,-1,sizeof dp);
  while(t--){
    int a,b,c; cin>>a>>b>>c;
    cout<<choco(a,b,c)<<'\n';
  }
}
