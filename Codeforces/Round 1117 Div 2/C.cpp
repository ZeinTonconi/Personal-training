#include <bits/stdc++.h>
using namespace std;

const int MAX_N=1e5+10;

int pa[MAX_N];

int main(){
  int t; cin>>t;
  while(t--){
    int n; cin>>n;
    for(int i=2;i<=n;i++){
      cin>>pa[i];
    }
    int m; cin>>m;
    vector<int> x(m);
    for(auto &v:x) cin>>v;
    sort(x.begin(),x.end());
    cout<<m-1<<" ";
    for(int i=1;i<m;i++)
      cout<<x[i]<<" ";
    cout<<endl;
    
  }
}
