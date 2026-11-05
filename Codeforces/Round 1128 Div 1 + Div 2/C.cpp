#include <bits/stdc++.h>
using namespace std;
int main(){
  int t; cin>>t;
  while(t--){
    int n; cin>>n;
    int c0=0,c1=0;
    for(int i=0;i<n;i++){
      int a; cin>>a;
      if(a%2==0) c0++;
      else c1++;
    }
    if((c0==0 && c1==0) || (c0==1 && c1==1) || (c0==0 && c1==3)) cout<<"Larpity"<<endl;
    else cout<<"Moggity"<<endl;
  }
}
