#include <bits/stdc++.h>

using namespace std;

bool has[510][3][510][3];

int main(){
  int n,m,q; cin>>n>>m>>q;
  for(int i=0;i<n;i++){
    string x; cin>>x;
    for(int j=0;j<m;j++){
      for(int k=0;k<m;k++){
	has[j][x[j]-'0'][k][x[k]-'0']=1;
      }
    }
  }
  while(q--){
    string x; cin>>x;
    bool ok=1;
    for(int i=0;i<m;i++){
      for(int j=0;j<m;j++){
	if(!has[i][x[i]-'0'][j][x[j]-'0']){
	  ok=0;
	  break;
	}
      }
      if(!ok) break;
    }
    cout<<(ok?"Yes\n":"No\n");
  }
}
