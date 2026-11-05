#include <bits/stdc++.h>
using namespace std;
int main(){
  int t; cin>>t;
  while(t--){
    int n; char c; cin>>n>>c;
    string x; cin>>x;
    int j=n-1;
    int ans=0;
    for(int i=0;i<j;i++){
      if(x[i]!=x[j]){
	if(x[i]!=c) ans++;
	if(x[j]!=c) ans++;
      }
      j--;
    }
    cout<<ans<<endl;
  }
}
