#include <bits/stdc++.h>
using namespace std;

int getMex(vector<int> &x,int k){
  int n=x.size();

  vector<bool> act(n+1,0);
  vector<int> mex(n);

  int m=0;

  for(int i=0;i<n;i++){
    act[x[i]]=1;
    while(act[m])
      m++;
    
    mex[i]=m;
  }
  
  sort(mex.begin(),mex.end());
  reverse(mex.begin(),mex.end());
  return mex[k-1];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t; cin>>t;
  while(t--){
    int n,k; cin>>n>>k;
    vector<int> x(n);
    for(auto &v:x) cin>>v;

    int ma=getMex(x,k);
    int l=-1,r=-1;
    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
	swap(x[i],x[j]);
	int pa=getMex(x,k);
	if(ma<pa){
	  ma=pa;
	  l=i; r=j;
	}
	swap(x[i],x[j]);
      }
    }
    if(l==-1) cout<<"-1\n";
    else cout<<l+1<<" "<<r+1<<'\n';
  }
}
