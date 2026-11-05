#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,m; cin>>n>>m;
  vector<int> x(n),y(m);
  for(auto &v:x) cin>>v;
  for(auto &v:y) cin>>v;

  sort(x.begin(),x.end());
  sort(y.begin(),y.end());
  int ans=0;
  int j=0;
  for(int i=0;i<n;i++){
    if(j<m && y[j]<=2*x[i]){
      j++;
      ans++;
    }
  
  }
  cout<<ans<<endl;
  
}
