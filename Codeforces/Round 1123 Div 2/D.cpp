#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> par, int n,bool init){
  
  bool ok=1;
  vector<bool> tak(n+1,0);
  bool p=init;
  for(int i=1;i<=n;i++){
    if(p==par[i]){
      tak[i]=1;
      p=!p;
    }
  }
  for(int i=n;i>=1;i--){
    if(p==par[i] && !tak[i]){
      tak[i]=1;
      p=!p;
    }
  }
  for(int i=1;i<=n;i++){
    if(!tak[i]){
      return 0;
    }
  }
  return 1;
}

int main(){
  int t; cin>>t;
  while(t--){
    int n; cin>>n;
    vector<int> x(n);
    for(auto &v:x) cin>>v;
    vector<int> par(n+1);
    for(int i=0;i<n;i++){
      par[x[i]]=i%2;
    }
    cout<<((check(par,n,0)||check(par,n,1))?"Yes\n":"No\n");
  }
}
