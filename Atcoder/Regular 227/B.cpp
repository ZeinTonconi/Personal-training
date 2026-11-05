#include <bits/stdc++.h>
using namespace std;
int main(){
  int n; cin>>n;
  vector<int> x(n);
  for(auto &v:x) cin>>v;
  sort(x.begin(),x.end());
  reverse(x.begin(),x.end());
  set<int> s;
  for(int i=0;i<n;i++) s.insert(i);

  bool ok=1;
  vector<int> ans(n);
  for(int i=0;i<n;i++){
    auto it=s.lower_bound(x[i]);
    if(it==s.end()){
      ok=0;
      break;
    }
    ans[*it]=x[i];
    s.erase(it);
  }
  if(ok){
    cout<<"Yes\n";
    for(auto &v:ans) cout<<v<<" ";
    cout<<endl;
  } else cout<<"No\n";
}
  
