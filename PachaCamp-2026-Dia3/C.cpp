#include <bits/stdc++.h>
using namespace std;

const int MAX_N=2e5+10;

int sum[MAX_N];

int main(){
  int t; cin>>t;
  while(t--){
    int n; cin>>n;
    vector<int> x(n);
    for(int i=0;i<=n;i++) sum[i]=0;
    for(auto &v:x) cin>>v;
    for(int i=0;i<n;i++){
      if(x[i]!=0){
	sum[max(0,i-x[i]+1)]++;
	sum[i+1]--;
      }
    }
    int ans=0;
    for(int i=0;i<n;i++){
      ans+=sum[i];
      if(ans>0) cout<<"1 ";
      else cout<<"0 ";
    }
    cout<<endl;
  }
}
