#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t; cin>>t;
  while(t--){
    int n; cin>>n;
    if(n%2==0){
      cout<<"-1\n";
      continue;
    }
    ll pot=1;
    int c=0;
    while(pot<n){
      pot*=2LL;
      c++;
    }
    ll y=pot-n;

    vector<int> ans;
    for(int i=c-1;i>=1;i--){
      if(y&(1<<i)){
	ans.push_back(1);
      }
      else ans.push_back(2);
    }
    cout<<ans.size()<<endl;
    for(auto &v:ans) cout<<v<<" ";;;
    cout<<endl;
  }
}
