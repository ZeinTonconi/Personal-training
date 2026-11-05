#include <bits/stdc++.h>
using namespace std;
int main(){
  int t; cin>>t;
  while(t--){
    int n; cin>>n;
    vector<int> x(n);
    for(int &v:x) cin>>v;

    set<int> s;
    for(auto &v:x) s.insert(v);
    if(s.size()==1) cout<<(*s.begin())<<endl;
    else{
      int ma=*prev(s.end());

      for(int i=29;i>=0;i--){
	for(int j=0;j<n;j++){
	  if((ma&(1<<i)) && !(x[j]&(1<<i))){
	    ma|=((1<<i)-1);
	    break;
	  }
	}
      }
      cout<<ma<<endl;
    }
  }
}
