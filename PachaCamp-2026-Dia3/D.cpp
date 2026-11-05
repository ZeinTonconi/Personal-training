#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX=1e16;
int main(){
  int t; cin>>t;
  while(t--){
    int n,k; cin>>n>>k;
    vector<ll> x(n);
    for(auto &v:x) cin>>v;
    ll sum=0;
    sort(x.begin(),x.end());
    reverse(x.begin(),x.end());
    for(auto &v:x){
      sum+=v;
    }
    cout<<max(x[0],(sum/k)+(sum%k!=0))<<endl;

  }
}
