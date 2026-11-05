#include <bits/stdc++.h>
using namespace std;
int main(){
  int t; cin>>t;
  while(t--){
    int n; cin>>n;
    string x; cin>>x;
    int l=n+1,r=0;
    int c=0;
    for(int i=0;i<n;i++){
      if(x[i]=='1'){

	l=min(l,i);
	r=max(r,i);
	c++;
      }
    }
    if(c==1) cout<<"0\n";
    else if(c==2) cout<<"1\n";
    else cout<<r-l<<endl; 
  }
}
