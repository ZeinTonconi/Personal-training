#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MAX=1e18;

int main(){
  int t; cin>>t;
  while(t--){
    int n,m; cin>>n>>m;
    vector<int> x(n);
    for(auto &v:x) cin>>v;
    ll sum=0;
    priority_queue<int> pq;
    ll ans=-MAX;
    for(auto &v:x){

      if(pq.size()==m-1){
	ans=max(ans,1LL*v*m-sum);
      }
      
      if(pq.size()<m-1 || (!pq.empty() && pq.top()>v)){
	if(pq.size()==m-1) {
	  sum-=pq.top();
	  pq.pop();
	}
	pq.push(v);
	sum+=v;
      }
    }
    cout<<ans<<endl;
  }
}
