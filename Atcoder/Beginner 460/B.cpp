#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
  int t; cin>>t;
  while(t--){
    ll x1,y1,r1,x2,y2,r2;
    cin>>x1>>y1>>r1>>x2>>y2>>r2;
    ll dx=abs(x1-x2);
    ll dy=abs(y1-y2);
    ll d=dx*dx+dy*dy;
    ll r=(r1+r2)*(r1+r2);

    if(r1<r2){
      swap(x1,x2);
      swap(y1,y2);
      swap(r1,r2);
    }
    if(d<=r1*r1){
      cout<<((d>=(r1-r2)*(r1-r2))?"Yes\n":"No\n");
    }else
      cout<<((d<=r)? "Yes\n":"No\n");
  }
}
