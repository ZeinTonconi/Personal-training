#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ll> il;

map<ii,ll> dp;
vector<int> num;
vector<il> comp;

ll maxSum(int id,int x){
  if(id==comp.size()) return 0;
  
  if(dp.find(ii(id,x))!=dp.end())
    return dp[ii(id,x)];

  ll ans=maxSum(id+1,x);
  if(__gcd(x,comp[id].first)!=1){
    ans=max(ans,maxSum(id+1,__gcd(x,comp[id].first))+comp[id].second);
  }
  return dp[ii(id,x)]=ans;
  
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t; cin>>t;
  while(t--){
    dp.clear();
    num.clear();
    comp.clear();
    int n,x; cin>>n>>x;
    num.resize(n);
    for(auto &v:num) cin>>v;

    map<int,ll>m;

    for(int i=0;i<n;i++){
      m[__gcd(num[i],x)]+=num[i];
    }
    for(auto &v:m){
      comp.push_back(v);
    }
    reverse(comp.begin(),comp.end());
    
    cout<<maxSum(0,x)<<'\n';
  }
}
