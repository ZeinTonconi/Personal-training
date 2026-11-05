#include <bits/stdc++.h>
using namespace std;
int main(){
  int n; cin>>n;
  vector<int> x(n);
  for(auto &v:x)
    cin>>v;

  vector<vector<int> > perm;
  vector<int> p=x;
  sort(p.begin(),p.end());
  do{
    perm.push_back(p);
  }while(next_permutation(p.begin(),p.end()));


  auto it=lower_bound(perm.begin(),perm.end(),x);
  int id=it-perm.begin();
  for(int i=id-1;i<=id+1;i++){
    if(i>=0 && i<perm.size()){
      for(int j=0;j<n;j++){
	if(j==n-1) cout<<perm[i][j]<<endl;
	else cout<<perm[i][j]<<" ";
      }
    }
  }
}
