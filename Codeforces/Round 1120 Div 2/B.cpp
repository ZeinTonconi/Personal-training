#include <bits/stdc++.h>
using namespace std;

const int MAX_N=1010;

int ma[MAX_N][MAX_N];

int main(){
  int t; cin>>t;
  while(t--){
    int n,k; cin>>n>>k;
    if(k<n || k>2*n-1) {
      cout<<"-1\n";
      continue;
    }
    ma[0][0]=1; k--;
    bool diag=0;
    int c=2;
    for(int i=1;i<n;i++){
      int res=n-i;
      if(res==k || diag){
	diag=1;
	ma[i][i]=c;
	c++;
	k--;
      } else{
	ma[i][0]=c++;
	ma[0][i]=c++;
	k-=2;
      }
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
	if(ma[i][j]==0) ma[i][j]=c++;
      }
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
	cout<<ma[i][j]<<" ";
      }
      cout<<endl;
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++) ma[i][j]=0;
    }
  }
  
}
