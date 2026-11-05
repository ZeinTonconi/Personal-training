#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
  int t; cin>>t;
  while(t--){
    int n,m; cin>>n>>m;
    vector<int> x(n),y(m);
    for(auto &v:x) cin>>v;
    for(auto &v:y) cin>>v;
    ll sa=x[n-1],sb=y[m-1];

    for(int i=1;i<n;i++){
      sa+=x[i-1]-x[i]+1;
    }
    for(int i=1;i<m;i++){
      sb+=y[i-1]-y[i]+1;
    }
    cout<<(sa>=sb?"1\n":"2\n");
  }
}
