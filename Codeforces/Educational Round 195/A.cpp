#include <bits/stdc++.h>
using namespace std;
int main(){
  int t; cin>>t;
  while(t--){
    int a,b; cin>>a>>b;
    if(a<=b) {
      cout<<"-1\n";
      continue;
    }
    if(a/2>=b) {
      cout<<b<<"\n";
      continue;
    }
    cout<<a-b<<endl;
    
  }
}
