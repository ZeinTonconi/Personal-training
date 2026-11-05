#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int MAX_N=3e5+10;

string x;

int dp[MAX_N][7][6];

int cost(int id,int prev,int ma){
  if(id==x.size())
    return ma;
 
  if(dp[id][prev][ma]!=-1)
    return dp[id][prev][ma];
  
  int ans=4;
  for(int i=-3;i<=3;i++){
    if(i==0) continue;
    int act=(prev-3)+i;
    if(x[id]=='0' && (prev-3)+i==0)
      ans=cost(id+1,3,max(ma,abs(i)));
    if(x[id]=='+' && act>0 && act<=3)
      ans=min(ans,cost(id+1,act+3, max(ma,abs(i))));
    if(x[id]=='-' && act<0 && act>=-3)
      ans=min(ans,cost(id+1,act+3,max(ma,abs(i))));
  }
  return dp[id][prev][ma]=ans;
}


int main(){
  int t; cin>>t;
  while(t--){
    int n; cin>>n;
    cin>>x;
    bool ok=1;

    for(int i=0;i<n;i++){
      if(x[i]==x[i+1] && x[i]=='0') ok=0;
    }
    
    if(x[0]=='0' || !ok){
      cout<<"-1\n";
      continue;
    }
    
    for(int i=0;i<=n;i++){
      for(int j=0;j<7;j++){
	for(int k=0;k<6;k++) dp[i][j][k]=-1;
      }
    }
    cout<<cost(0,3,0)<<endl;
  }
}
