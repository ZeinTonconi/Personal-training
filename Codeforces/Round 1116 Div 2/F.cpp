#include <bits/stdc++.h>

using namespace std;

const int MAX=1e9;

bool check(int k,vector<int> &x){
  priority_queue<int> q;
  for(auto &v:x) q.push(v);
  for(int i=k-1;i>=0;i--){
    if(q.empty()) break;
    int a=q.top();
    q.pop();
    int msb=31-__builtin_clz(a);
    if(msb==i){
      if(a-(1<<msb)!=0)
	q.push(a-(1<<msb));
    } else{
      if(msb>i) return 0;
    }
  }
  return q.empty();
}


int main(){
  int t; cin>>t;
  while(t--){
    int n; cin>>n;
    vector<int> x(n);
    for(auto &v:x) cin>>v;
    int l=0,r=MAX;
    while(r-l>1){
      int mid=(l+r)/2;
      if(check(mid,x))
	r=mid;
      else
	l=mid;
    }
    cout<<r<<endl;
  }
  
}
