#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
vector<ii> ans;


int main(){
  int t; cin>>t;
  while(t--){
    
    int n,m; cin>>n>>m;

    ans.clear();
    if(n==1){
      cout<<"0"<<endl;
      continue;
    }
    int k=(n+1)/2;
    for(int i=0;i<(n+1)/2;i++){
      ans.push_back(ii(i,i+k-1));
    }
    cout<<ans.size()<<endl;
    for(auto &v:ans) cout<<v.first+1<<" "<<v.second+1<<endl;
    
  }
}
