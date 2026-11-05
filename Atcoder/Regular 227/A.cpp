#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> getPos(string x){
  vector<int> p;
  for(int i=0;i<x.size();i++){
    if(x[i]=='1') p.push_back(i);
  }
  return p;
} 

int main(){
  int n; cin>>n;
  string A,B,C; cin>>A>>B>>C;
  vector<int> pa=getPos(A), pb=getPos(B), pc=getPos(C);

  string ans="";
  for(int i=0;i<2*n;i++) ans+='0';
  ll sum=0;
  
  for(int i=0;i<n;i++){
    vector<int> aux={pa[i],pb[i],pc[i]};
    sort(aux.begin(),aux.end());
    sum+=abs(aux[0]-aux[1])+abs(aux[2]-aux[1]);
    ans[aux[1]]='1';
  }
  cout<<sum<<endl<<ans<<endl;
  
}
