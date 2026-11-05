#include <bits/stdc++.h>
using namespace std;
int main(){
  int t; cin>>t;
  while(t--){
    int n,k; cin>>n>>k;
    string x; cin>>x;
    x+=x[0];

    int red=0,blue=0;
    for(int i=0;i<2*n;i++){
      if(x[i]=='1' && x[i+1]=='0'){
	if(i%2==0)blue++;
	else red++;
      }
      if(x[i]=='1' && x[i+1]=='1'){
	if(i%2==0) red++;
	else blue++;
      }
    }
    cout<<blue<<" "<<red<<endl;
  }
}
