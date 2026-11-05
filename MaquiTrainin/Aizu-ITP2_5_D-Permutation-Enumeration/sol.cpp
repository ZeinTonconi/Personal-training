#include <bits/stdc++.h>
using namespace std;
int main(){

  int n; cin>>n;
  vector<int> x(n);
  iota(x.begin(),x.end(),1);

  vector<vector<int> > perm;
  
  do{
    perm.push_back(x);
  }while(next_permutation(x.begin(),x.end()));

  for(auto &v:perm){
    for(int i=0;i<n;i++){
      if(i==n-1) cout<<v[i]<<endl;
      else cout<<v[i]<<" ";
    }
  }
  
}
