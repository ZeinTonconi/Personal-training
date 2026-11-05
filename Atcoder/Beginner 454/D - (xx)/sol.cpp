#include <bits/stdc++.h>
using namespace std;

const int MAX_N=2e6+10;

bool vis[MAX_N];

string erase(string x){

  int n=x.size();
  for(int i=0;i<n;i++)
    vis[i]=0;

  for(int i=0;i<n-1;i++){
    if(x[i]=='x' && x[i+1]=='x'){
      int l=i-1,r=i+2;
      while(l>=0 && r<n && !vis[l] && !vis[r] && x[l]=='(' && x[r]==')'){
	vis[l]=vis[r]=1;
	l--; r++;
      }
    }
  }
  string ans="";
  for(int i=0;i<n;i++){
    if(!vis[i]) ans+=x[i];
  }
  return ans;
}

int main(){
  int t; cin>>t;
  while(t--){
    string a,b; cin>>a>>b;
    string ax=erase(a);
    string bx=erase(b);
    cout<<((ax==bx)?"Yes\n":"No\n");
  }
}
