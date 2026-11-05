#include <bits/stdc++.h>
using namespace std;
int main(){
  int t; cin>>t;
  while(t--){
    int n,q; cin>>n>>q;
    vector<int> x(n);
    for(auto &v:x) cin>>v;

    int c=1;
    vector<int> col(n);
    col[0]=1;
    for(int i=1;i<n;i++){
      if(x[i]<x[i-1])
	c++;
      col[i]=c;
    }

    while(q--){
      int l,r; cin>>l>>r;
      r--; l--;
      cout<<((col[r]-col[l]<=1)?"YES\n":"NO\n");
    }
  }
		 
}
