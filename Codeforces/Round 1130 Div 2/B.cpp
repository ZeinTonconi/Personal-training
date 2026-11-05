#include <bits/stdc++.h>
using namespace std;
int main(){
  int t; cin>>t;
  while(t--){
    int n; cin>>n;
    string t,b; cin>>t>>b;
    int c=0;
    for(int i=0;i<n;i++){
      c+=(t[i]=='f');
      c+=(b[i]=='f');
    }
    cout<<c%2<<endl;
  }
}
