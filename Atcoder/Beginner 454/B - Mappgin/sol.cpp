#include <bits/stdc++.h>
using namespace std;
int main(){

  int n,m; cin>>n>>m;
  set<int> s;
  for(int i=0;i<n;i++){
    int a; cin>>a;
    s.insert(a);
  }
  cout<<((s.size()==n)?"Yes\n":"No\n");
  cout<<((s.size()==m)?"Yes\n":"No\n");
  
}
