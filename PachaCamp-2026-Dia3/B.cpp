#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  int t; cin>>t;
  while(t--){
    int n,x; cin>>n>>x;
    vector<int> car(n);
    for(auto &v:car) cin>>v;
    sort(car.begin(),car.end());
    ll ans=0;
    for(int i=0;i<n;i++){
      ans+=car[i];
      for(int j=i;j<min(n,j+x);j++)
	car[j]-=car[i];
    }
    cout<<ans<<endl;
  }
}
