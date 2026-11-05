#include <bits/stdc++.h>
using namespace std;

bool check(int mid,vector<int> &x,int k){
  int n=x.size();
  vector<bool> act(n);

  for(int i=0;i<n-1;i++){
    if(x[i+1]-x[i]<=mid) act[i]=act[i+1]=1;
  }

  vector<int> y;
  for(int i=0;i<n;i++){
    if(!act[i]) y.push_back(x[i]);
  }

  
  int m=y.size();
  act.assign(m,0);
  for(int i=0;i<m;i++){
    if(act[i]) continue;
    int a=y[i]+mid;
    if(i+1<m && y[i+1]-a<=mid) act[i+1]=1;
    act[i]=1;
    k--;
  }
  return k>=0;
}

int main(){
  int t; cin>>t;
  while(t--){
    int n,k; cin>>n>>k;
    vector<int> x(n);
    for(auto &v:x) cin>>v;

    int l=0,r=1e9+1;
    while(r-l>1){
      int mid=(l+r)/2;
      if(check(mid,x,k)) r=mid;
      else l=mid;
    }
    cout<<r<<endl;
  }

}
