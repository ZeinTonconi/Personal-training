#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MAX=1e16;

int main(){
  int t; cin>>t;
  while(t--){
    int n; cin>>n;
    if(n<=5){
      for(int i=0;i<n;i++){
	cout<<(i%2==0);
      }
      cout<<endl;
    } else{
      int bl=n/3;
      int a=bl,b=2*bl,c=3*bl;
      int aa,ab,ac;
      ll mi=MAX;
      for(int i=max(0,a-2);i<=a+2;i++){
	for(int j=b-2;j<=b+2;j++){
	  for(int k=c-2;k<=min(n-1,c+2);k++){
	    if(i>=j || j>=k) continue;
	    ll di=i;
	    ll dij=j-i-1;
	    ll djk=k-j-1;
	    ll dk=n-k-1;
	    ll pa=di*(di+1)/2+dij*(dij+1)/2+djk*(djk+1)/2+dk*(dk+1)/2;

	    if(i%2!=j%2 && j%2!=k%2){
	      pa+=(di+1)*(djk+1);
	      pa+=(dk+1)*(dij+1);
	    } else if(i%2==j%2 && j%2!=k%2){
	      pa+=(dk+1)*(dij+1);
	    } else if(i%2!=j%2 && j%2==k%2){
	      pa+=(di+1)*(djk+1);
	    } else{
	      pa+=(di+1)*(dk+1);
	    
	    }
	    
	    if(pa<mi){
	      aa=i; ab=j; ac=k;
	      mi=pa;
	    }
	  }
	}
      }
      string x;
      for(int i=0;i<n;i++)
	x+='0';
      x[aa]=x[ab]=x[ac]='1';
      cout<<x<<endl;
    }
  }
}
