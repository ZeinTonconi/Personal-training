#include <bits/stdc++.h>
using namespace std;

/* Si se tienen restricciones se deben hacer respetar en todo el codigo
   En este caso si por filas o columnas solo se pueden usar cierta cantidad
   en todo el flujo solo se puede usar eso y se debe asegurar que siempre se
   respete eso. Siempre se deben respetar las restricciones en todo el flujo
   del codigo
*/

typedef long long ll;

const int MAX_N=2e5+10;

int both[MAX_N];

ll take(int n,int t,int x,int y){
  int c=0;
  int a=0,b=0;
  ll s=0;
  for(ll i=n;i>=0;i--){
    if(both[i]==0) continue;

    if(both[i]==3)
      c++;

    if(both[i]==1 || both[i]==3){
      if(a!=x)
	a++;
      else{
	if(c!=0 && b!=y){
	  b++;
	  c--;
	} else
	  continue;
      }
    }

    if(both[i]==2){
      if(b!=y){
	b++;
      } else
	continue;
    }
    t--;
    s+=i;
    if(t==0) break;
    
  }
  return s;
}

int main(){
  int t; cin>>t;
  while(t--){
    int n,m,x,y; cin>>n>>m>>x>>y;
    for(int i=0;i<=n+m;i++) both[i]=0;
    
    for(int i=0;i<x;i++){
      int a; cin>>a;
      both[a]|=1;
    }
    for(int i=0;i<y;i++){
      int a; cin>>a;
      both[a]|=2;
    }
      
    cout<<take(n+m,min(
		       min(n,x)+min(m,y),
		       n+m-1),
	       min(n,x),min(m,y))<<endl;
    
  }
}
