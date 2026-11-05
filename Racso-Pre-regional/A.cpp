#include <bits/stdc++.h>
using namespace std;
int main(){
  string a,b; cin>>a>>b;
  int n=b.size();
  int m=a.size();
  string ans="-1";
  for(int i=0;i<n;i++){
    string c;
    for(int j=0;j<m;j++){
      c+=('0'+(b[i]-a[j]+10)%10);
    }
    while(!c.empty() && c[0]=='0'){
      c.erase(c.begin());
    }
    int dig=c.size();

    if(i+m-1<n-dig){
      ans=c;
      break;
    }
  }
  cout<<ans<<endl;
}
