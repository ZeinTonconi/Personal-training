#include <bits/stdc++.h>
using namespace std;

const int MAX_N=2e5+10;
int pa[MAX_N];

void init(int n){
  for(int i=0;i<=n;i++){
    pa[i]=i;
  }  
}

int findset(int i){
  return (i==pa[i])?i:pa[i]=findset(pa[i]);
}

bool issameset(int i,int j){
  return findset(i)==findset(j);
}


void unionset(int i,int j){
  if(!issameset(i,j)){
    int u=findset(i);
    int v=findset(j);
    pa[u]=v;
  }
}

int main(){
  int n,m; cin>>n>>m;
  init(n);
  int ans=0;
  for(int i=0;i<m;i++){
    int a,b; cin>>a>>b;
    if(!issameset(a,b)){
      ans++;
      unionset(a,b);
    }
  }
  cout<<ans<<endl;
}



