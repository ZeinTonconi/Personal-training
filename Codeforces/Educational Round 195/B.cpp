#include <bits/stdc++.h>
using namespace std;
int main(){
  int t; cin>>t;
  while(t--){
    string x; cin>>x;
    int c=0;
    int ans=1;
    bool sz3=0,sz1=0;
    for(int i=0;i<x.size();i++){ 
      c++;
      if(x[i]!=x[i+1]){
	if(c==1 && i!=0 && i!=x.size()-1) sz1=1;
	if(c>=3) sz3=1;
	c=0;
      }
    }
    
    if(c>=3) sz3=1;

    cout<<1+sz3+sz1<<endl;
  }
}
