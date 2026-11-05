#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t; cin>>t;
  while(t--){
    int n; cin>>n;
    vector<int> freq(101);
    for(int i=0;i<n;i++){
      int a; cin>>a;
      freq[a]++;
    }
    vector<int> ans;
    while(true){
      vector<int> pa=ans;
      int lim,ma;
      for(int i=100;i>=0;i--){
	if(freq[i]!=0){
	  lim=freq[i];
	  ma=i;
	  break;
	}
      }
      
      for(int i=ma;i>=0;i--){
	for(int j=0;j<min(freq[i],lim);j++)
	  pa.push_back(i);
	freq[i]=max(0,freq[i]-lim);
      }
      if(pa.size()==ans.size()) break;
      ans=pa;
    }
    for(auto &v:ans) cout<<v<<" ";
    cout<<endl;
  }
  
}
