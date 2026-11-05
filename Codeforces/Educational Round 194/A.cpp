#include <bits/stdc++.h>
using namespace std;
int main(){
  int t; cin>>t;
  while(t--){
    int n; cin>>n;
    vector<int> x(n);
    for(auto &v:x) cin>>v;
    int c=0;
    for(int i=0;i<n;i++){
      if(!x[i]) c++;
    }
    if(c<2) cout<<"-1\n";
    else{
      int ans=0;
      if(x[0]) ans++;
      if(x[n-1]) ans++;
      cout<<ans<<endl; 
    }
  }
}
