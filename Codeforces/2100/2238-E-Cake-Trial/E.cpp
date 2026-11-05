#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_N=510;
const int MAX=1e9;

string x;

int dp[MAX_N][MAX_N][MAX_N];

int main(){
  int t; cin>>t;
  while(t--){
    int n; cin>>n;
    cin>>x;
    for(int i=0;i<=n;i++){
      for(int j=0;j<=n;j++){
	for(int k=0;k<=n;k++){
	  dp[i][j][k]=MAX;
	}
      }
    }

    dp[0][0][0]=0;
    
    for(int i=0;i<n;i++){
      for(int j=0;j<=n;j++){
	for(int k=0;k<=n;k++){
	  
	  if(x[i]!='F')
	    dp[i+1][j][max(0,k-1)]=min(dp[i+1][j][max(0,k-1)],dp[i][j][k]);
	    
	  if(x[i]!='T')
	    dp[i+1][j+1][k+1]=min(dp[i+1][j+1][k+1], max(dp[i][j][k],k+1));
	}
      }
    }

    int ans=0;
    for(int i=0;i<=n;i++){
      for(int j=0;j<=n;j++){
	ans=max(ans,i-dp[n][i][j]);
      }
    }
    cout<<ans<<endl;
  }
}
