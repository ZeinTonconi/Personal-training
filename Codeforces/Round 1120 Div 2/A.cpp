#include <bits/stdc++.h>
using namespace std;
int main(){
  int t; cin>>t;
  while(t--){
    int n; cin>>n;
    vector<int> x(n);
    for(auto &v:x) cin>>v;
    for(int i=0;i<n;i++){
      bool ok=0;
      for(int j=0;j<x.size()-1;j++){
	if(x[j]!=x[j+1]){
	  x.erase(x.begin()+j);
	  if(i%2==0) x[j]=1;
	  else x[j]=0;
	  ok=1;
	  break;
	}
      }
      if(!ok) x.pop_back();
    }
    cout<<(x[0]==1?"Bessie\n":"Elsie\n");
  }
  
}
