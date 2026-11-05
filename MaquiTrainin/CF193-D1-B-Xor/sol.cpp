#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MIN = -1e18;

int n,u,r;
vector<ll> a,b,k,p;

struct State{
  vector<ll> curr;
  int c;

  State(vector<ll> &_v, int _c):curr(_v),c(_c){}
  
  ll cost(){
    ll ans=0;
    for(int i=0;i<n;i++){
      ans+=curr[i]*k[i];
    }
    return ans;
  }

  void doXor(int step){
    for(int i=0;i<n;i++){
      curr[i]^=b[i];
    }
    c+=step;
  }

  void doSum(){
    vector<ll> aux=curr;

    for(int i=0;i<n;i++){
      curr[i]=aux[p[i]]+r;
    }
    c++; 
  }
  
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin>>n>>u>>r;
  a.resize(n); b.resize(n); k.resize(n); p.resize(n);
  for(auto &v:a) cin>>v;
  for(auto &v:b) cin>>v;
  for(auto &v:k) cin>>v;
  for(auto &v:p) {
    cin>>v;
    v--;
  }

  queue<State> q;
  ll ans=MIN;
  q.push(State(a, 0));

  State initXor = State(a,0);
  initXor.doXor(1);
  q.push(initXor);
  
  while(!q.empty()){
    State tp=q.front();
    q.pop();
    if((u-tp.c)%2==0){
      ans=max(ans,tp.cost());
    }
    if(tp.c!=u){
      int c=u-tp.c;
      for(int i=0;i<c;i++){
        
	tp.doSum();

	if((u-tp.c)%2==0)
	  ans=max(ans,tp.cost());
	
	tp.doXor(1);
	q.push(tp);

	tp.doXor(-1);
	
      }
    }
    
  }
  cout<<ans<<endl;
  
}
