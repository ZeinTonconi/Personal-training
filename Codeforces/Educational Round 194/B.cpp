#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
  int t; cin>>t;
  while(t--){
    int x,y;
    ll k;
    cin>>x>>y>>k;
    ll ans=0;
    while(k>0 && y/x!=1){
      ans+=(y%x);
      x++; y++;
      k--;
    }
    ans+=k*(y%x);
    cout<<ans<<endl;
  }
}
