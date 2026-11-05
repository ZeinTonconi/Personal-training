#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
  int t; cin>>t;
  while(t--){
    ll x,y;
    cin>>x>>y;
    vector<int> pot;
    pot.push_back(x);
    for(int i=0;i<10;i++){
      if(pot.back()*10LL>y) break;
      pot.push_back(pot.back()*10LL);
    }

    ll ans=y;
    int c=0;
    for(int i=pot.size()-1;i>=0;i--){
      while(y>=pot[i]){
	c++;
	y-=pot[i];
	ans=min(ans,c+y);
      }
    }
    cout<<ans<<endl;
  }
}
