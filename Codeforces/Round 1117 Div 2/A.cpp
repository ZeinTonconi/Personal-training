#include <bits/stdc++.h>
using namespace std;
int main(){
  int t; cin>>t;
  while(t--){
    int n,m; cin>>n>>m;
    vector<bool> exist(27);
    for(int i=0;i<n;i++){
      string x; cin>>x;
      exist[x[0]-'a']=1;
    }

    bool ok=1;
    for(int i=0;i<m;i++){
      string x; cin>>x;
      for(auto &v:x){
	if(!exist[v-'A']){
	  ok=0;
	  break;
	}
      }
    }
    cout<<(ok?"YES\n":"NO\n");
  }
}
