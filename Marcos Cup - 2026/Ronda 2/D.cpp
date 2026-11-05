#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,int> li;

map<int, ll> dis;

vector<int> getDiv(int n){
  vector<int> div;
  for(ll i=2;i*i<=n;i++){
    if(n%i==0){
      div.push_back(i);
      if(n/i!=i) div.push_back(n/i);
    }
  }
  return div;
}

int main(){
  int n; cin>>n;

  dis[n]=n;

  priority_queue<li> pq;
  pq.push(li(dis[n],n));
  
  while(!pq.empty()){
    auto [distance, u]=pq.top();
    pq.pop();

    if(distance<dis[u]) continue;
    
    vector<int> div=getDiv(u);
    for(auto &d:div){
      if(dis[d]<dis[u]+d){
	dis[d]=dis[u]+d;
	pq.push(li(dis[d],d));
      }
    }
  }
  ll ma=0;
  for(auto &v:dis){
    ma=max(ma,v.second);
  }
  cout<<ma+1<<endl;
  
}
