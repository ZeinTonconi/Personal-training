#include <bits/stdc++.h>
using namespace std;
int main(){
  int t; cin>>t;
  while(t--){
    int n,k; cin>>n>>k;
    vector<int> pref(n+1,0);
    for(int i=0;i<n;i++){
      int a; cin>>a;
      pref[i+1]=(pref[i]+a)%k;
    }
    vector<int> available(k);
    long long ans=0;
    for(int i=n-k-1;i>=0;i--){
      available[pref[i+k+1]]++;
      ans+=available[pref[i]];
    }
    cout<<ans<<endl;
    
  }
}
