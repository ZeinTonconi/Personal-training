#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_N=1e5+10;
const ll mod=1e9+7;

ll pot(ll b,ll e){
  if(e==0) return 1;
  if(e==1) return b;
  ll aux=pot(b,e/2);
  aux=(aux*aux)%mod;
  if(e%2!=0) aux=(aux*b)%mod;
  return aux;
}

ll one(ll a){
  return (pot(2,a)-1+mod)%mod;
}


vector<int> p;
ll range(int l,int r){
  if(r==0) return 0;
  if(l==0) return p[r-1];
  return p[r-1]-p[l-1];
}

int main(){
  int t; cin>>t;
  while(t--){
    p.clear();
    int n; cin>>n;
    vector<int> m(n);
    for(auto &v:m) cin>>v;
    m.insert(m.begin(),0);
    vector<int> rang(n+1);
    
    for(int i=1;i<=n;i++){
      int l=i*m[i];
      rang[min(n,l)]++;
      rang[min(n,l+i)]--;
    }
    int acum=0;
    
    for(int i=0;i<=n;i++){
      acum+=rang[i];
      if(p.empty())
	p.push_back(0);
      else
	p.push_back(p.back());
      if(!acum) p.back()++;
    }

    // for(auto v:p) cout<<v<<" ";
    // cout<<endl;
    
    int r=0,l=-1;
    ll ans=1;
    for(int i=1;i<=n;i++){
      
      int lp=(r/i)*i;

      if(lp<l || lp>=m[i]*i) continue;
      
      if(l<=lp && lp<r){
	ans=(ans*pot(one(range(l,r)),mod-2))%mod;
      
	int a=lp-l;
	
	l=min(n,lp);
	r=min(n,lp+i);
	
	int b=r-lp;
	int c=(r-l)-b;
	ll pa=((one(range(l,l+a))*one(range(lp,lp+b+c)))%mod+
	       (one(range(lp,lp+b))*(one(range(r,r+c))+1))%mod)%mod;
	ans=(ans*pa)%mod;
	//cout<<i<<": "<<a<<" "<<b<<" "<<c<<endl;
      }
      for(int j=(l==-1?lp:lp+i);j<min(n,m[i]*i);j+=i){
	l=j;
	r=min(n,l+i);
	ans=(ans*one(range(l,r)))%mod;
	//cout<<"Jumps: "<<j<<": "<<range(l,r)<<" "<<l<<" "<<r<<endl;
      }
      //cout<<"Answer for: "<<i<<": "<<l<<" "<<r<<" "<<ans<<endl;
    }
    cout<<ans<<endl;
    
  }
}
