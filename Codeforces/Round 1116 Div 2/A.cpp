#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int t; cin>>t;
  while(t--){
    vector<ll> x(3);
    for(auto &v:x) cin>>v;
    sort(x.begin(),x.end());
    ll ans=x[2]-x[0];
    while(true){
      ll pans=ans;
      vector<ll> nx;
      for(int i=0;i<3;i++){
	for(int j=0;j<3;j++){
	  for(int k=0;k<3;k++){
	    if(i==j || j==k || i==k) continue;
	    vector<ll> y=x;
	    y[k]=y[i]+y[j];
	    sort(y.begin(),y.end());
	    if(y[2]-y[0]<pans){
	      pans=y[2]-y[0];
	      nx=y;
	    }
	  }
	}
      }
      ans=pans;
      x=nx;
      if(pans==ans)
	break;
    }
    cout<<ans<<endl;
  }
}
