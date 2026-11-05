/* it is more easy to join rather than separate things and also an endpoint
   will only be deleted once, so the complexity will reduce, even if you
   have to delete several elements, you are going to delete them just once
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Fenwick{
  int N;
  vector<ll> tr;
  Fenwick(int n): N(n){
    tr.assign(n+1,0);
  }

  int lsone(int s){
    return s&(-s);
  }

  void add(int id,int v){
    for(;id<=N;id+=lsone(id))
      tr[id]+=v;
  }

  ll sum(int k){
    ll s=0;
    for(;k;k-=lsone(k))
      s+=tr[k];
    return s;
  }

  ll sumLR(int l,int r){
    return sum(r)-sum(l);
  }
  
};

int main(){
  int t; cin>>t;
  while(t--){
    int n; cin>>n;
    vector<int> x(n);
    for(int &v:x) cin>>v;
    vector<int> p(n);
    for(int &v:p) cin>>v;
    for(int &v:p) v--;
    
    reverse(p.begin(),p.end());

    set<int> starts;

    Fenwick ft(n);

    vector<int> ans;
    
    for(int pi:p){
      auto it=starts.lower_bound(pi);

      int curr;
      
      if(it==starts.begin() || ft.sumLR(*prev(it),pi)<x[pi]){
	starts.insert(pi);
	curr=pi;
      } else{
	curr=*prev(it);
      }

      ft.add(pi+1,x[pi]);
      while(true){
	auto it=starts.upper_bound(curr);
        
	if(it==starts.end() || ft.sumLR(curr,*it)<x[*it])
	  break;
	
	
	starts.erase(it);
      }
      ans.push_back(starts.size()-1);
    }
    reverse(ans.begin(),ans.end());
    for(int v:ans) cout<<v<<" ";
    cout<<"\n";
  }
}
