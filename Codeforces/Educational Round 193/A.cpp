#include <bits/stdc++.h>
using namespace std;
int main(){
  int t; cin>>t;
  while(t--){
    int n; cin>>n;
    bool ok=1;
    for(int i=2;i*i<=n+1;i++){
      if((n+1)%i==0){
	ok=0;
	break;
      }
    }
    cout<<(ok?"YES\n":"NO\n");
  }
}
