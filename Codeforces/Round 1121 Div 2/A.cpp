#include <bits/stdc++.h>
using namespace std;
int main(){
  int t; cin>>t;
  while(t--){

    int n; cin>>n;
    vector<int> x(n);
    for(auto &v:x) cin>>v;
    vector<int> pos,y;
    for(int i=0;i<n;i++){
      if(x[i]!=i+1){
	pos.push_back(i);
	y.push_back(x[i]);
      }
    }
    reverse(y.begin(),y.end());
    for(int i=0;i<pos.size();i++){
      int p=pos[i];
      x[p]=y[i];
    }
    bool ok=1;
    for(int i=0;i<n;i++){
      if(x[i]!=i+1){
	ok=0;
	break;
      }
    }
    cout<<(ok?"YES\n":"NO\n");
  }
}
