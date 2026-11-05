#include <bits/stdc++.h>
using namespace std;
const int MAX_N=1001;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n; cin>>n;

  vector<bitset<MAX_N> > G(n);
  
  for(int i=0;i<n;i++){
    string x; cin>>x;
    G[i].set();
    for(int j=0;j<n;j++){
      if(x[j]=='0') G[i][j]=0;
    }
    G[i].flip();
  }
  int ans=0;
  for(int i=0;i<n;i++){
    bitset<MAX_N> g=G[i];
    for(int j=0;j<n;j++){
      if(g[j])
	g&=G[j];
      
    }
    ans=max(ans,(int)g.count());
  }
  cout<<ans<<'\n';
}
