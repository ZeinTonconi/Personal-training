#include <bits/stdc++.h>
using namespace std;

const int MAX_N=3e5+10;

int pa[MAX_N];
int ns;

void init(int n){
  for(int i=0;i<=n;i++){
    pa[i]=i;
  }
  ns=n;
}

int findset(int i){
  return pa[i]==i?i:pa[i]=findset(pa[i]);
}

bool issameset(int i,int j){
  return findset(i)==findset(j);
}

void unionset(int i,int j){
  if(!issameset(i,j)){
    int u=findset(i),v=findset(j);
    pa[u]=v;
    ns--;
  }
}

int main(){
  int t; cin>>t;
  while(t--){
    int n,m; cin>>n>>m;
    vector<int> edges(n+1,0);
    init(n);
    for(int i=0;i<m;i++){
      int a,b; cin>>a>>b;
      unionset(a,b);
      edges[a]++; edges[b]++;
    }
    int c=0;
    bool alone=0;
    for(int i=1;i<=n;i++){
      if(edges[i]>1) c++;
      if(edges[i]==0) alone=1;
    }
    if(alone) cout<<"Brain Melt\n";
    else if(c<=1 && ns==1) cout<<"2\n";
    else  cout<<"Many\n";
    
  }
}
