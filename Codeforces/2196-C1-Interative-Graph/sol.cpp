#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;

vi query(int k){
  cout<<"? "<<k<<endl;
  cout.flush();
  int n; cin>>n;
  vector<int> x(n);
  for(auto &v:x) cin>>v;
  return x;
}

bool check(int k,vi &pref){
  vi q=query(k);
  if(q.empty()) return false;
  return (pref[0]==q[0] && pref[1]==q[1]);
}

int main(){

  int t; cin>>t;
  while(t--){
    int n; cin>>n;

    set<ii> ans;
    
    int last=1;
    for(int i=1;i<=n;i++){

      last++;
      while(true){
	vi path = query(last);
	if(path.empty() || path[0]!=i) break;
	ans.insert(ii(i,path[1]));
	int l=last,r=15;
	while(r-l>1){
	  int mid=(l+r)/2;
	  if(check(mid,path))
	    l=mid;
	  else
	    r=mid;
	}
	
	last=r;	   
      }
    }
    cout<<"! "<<ans.size()<<endl;
    cout.flush();
    for(auto &v:ans){
      cout<<v.first<<" "<<v.second<<endl;
      cout.flush();
    }
  }
}
