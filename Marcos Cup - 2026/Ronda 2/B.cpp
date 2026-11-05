#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

int main(){
  int n; cin>>n;
  vector<int> x(n);
  for(auto &v:x) cin>>v;

  int m; cin>>m;
  vector<int> y(m);
  for(auto &v:y) cin>>v;

  map<int,int> rel;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(y[j]%x[i]!=0) continue;
      rel[y[j]/x[i]]++;
    }
  }
  if(rel.empty()) cout<<"0\n";
  else {
    auto it=rel.end();
    it--;
    cout<<(*it).second<<endl;
  }
}
