#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MAX_P=1e7;

vector<ll> decompose(ll s){

  vector<ll> d;
  for(ll i=1;i*i<=s;i++){
    if(s%i==0){
      d.push_back(i);
      if(i!=s/i) d.push_back(s/i);
    }
  }
  sort(d.begin(),d.end());
  return d;
}

ll comp(vector<ll> &d, vector<ll> &pref, ll q,ll s){
  

  int l=0,r=d.size();
  while(r-l>1){
    int mid=(l+r)/2;
    if(s/d[mid]>=q)
      l=mid;
    else
      r=mid;
  }
  
  int pos=l;
  
  return pref[pos]-d[pos]*q;
  
}

int main(){
  int t; cin>>t;
  while(t--){
    ll s; int q; cin>>s>>q;
    
    vector<ll> d=decompose(s);

    int t=d.size();
    vector<ll> pref(t);
    pref[0]=s;
    for(int i=1;i<t;i++){
      pref[i]=pref[i-1]+s-(s/d[i])*d[i-1];
    }
   while(q--){
      ll a,b; cin>>a>>b;
      if(a>b) swap(a,b);
      auto it=lower_bound(d.begin(),d.end(),a);

      if(s/(*it)>=b){
	cout<<a*b<<endl;
	continue;
      }

      ll ans=pref[t-1]-comp(d,pref,a,s)-comp(d,pref,b,s);
      cout<<ans<<endl;
    }
  }

}
