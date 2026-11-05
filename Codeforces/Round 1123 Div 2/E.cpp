#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(){
  int t; cin>>t;
  while(t--){
    int n,q; cin>>n>>q;
    string x; cin>>x;

    vector<int> b(n);
    
    ll ans=0;

    int c0=0,c1=0;
    
    for(int i=0;i<n;i++){
      if(x[i]=='0') c0++;
      else c1++;

      if(x[i]!=x[i+1]){
	b[i]=1;
	ans+=1LL*(i+1)*(n-i-1);
      }
      
    }

    cout<<(ans+1LL*c0*c1)/2<<" ";
    while(q--){
      int a; cin>>a;
      a--;
      
      if(x[a]=='0'){
	c0--; c1++;
	x[a]='1';
      } else{
	c0++; c1--;
	x[a]='0';
      }
      
      if(a-1>=0)
	ans-=(1LL*b[a-1]*a*(n-a));

      ans-=(1LL*b[a]*(a+1)*(n-a-1));
      
      if(a-1>=0 && x[a]!=x[a-1])
	b[a-1]=1;
      else
	if(a-1>=0)
	  b[a-1]=0;
      
      if(a+1<n && x[a]!=x[a+1])
	b[a]=1;
      else
	b[a]=0;

      ans+=(1LL*b[a]*(a+1)*(n-a-1));
      if(a-1>=0)
	ans+=(1LL*b[a-1]*a*(n-a));
      
      cout<<(ans+1LL*c0*c1)/2<<" ";
    }
    cout<<endl;
    
  }
}
