#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> transform(vector<ll> &x){
  vector<ll> y;
  int n=x.size();
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      y.push_back(x[i]^x[j]);
    }
  }

  sort(y.begin(),y.end());
  vector<ll> res;
  for(int i=0;i<n;i++) res.push_back(y[i]);
  return res;
  
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t; cin>>t;
  while(t--){
    int n,q; cin>>n>>q;
    vector<ll> x(n);
    for(auto &v:x) cin>>v;

    sort(x.begin(),x.end());
    
    vector<ll> ans;
    while(true){
      ans.push_back(x[n-1]-x[0]);
      if(x[n-1]==0) break;
      x=transform(x);
    }
    
    while(q--){
      int xi; cin>>xi;
      if(xi<ans.size()){
	cout<<ans[xi]<<'\n';
      } else cout<<"0\n";
    }
  }
}
