#include <bits/stdc++.h>
using namespace std;

vector<int> solve(string &s, string &t){
  int n=s.size();
  int m=t.size();

  vector<int> w;
  for(int i=0;i<m;i++){
    if(t[i]=='W') w.push_back(i+1);
  }

  vector<int> gaps;
  for(int i=1;i<w.size();i++){
    gaps.push_back(w[i]-w[i-1]);
  }

  sort(gaps.begin(),gaps.end());
  vector<int> pref(gaps.size()+1,0);

  for(int i=0;i<gaps.size();i++){
    pref[i+1]=pref[i]+gaps[i];
  }

  vector<int> ans;
  int lw=0;

  for(int i=1;i<=n;i++){
    if(s[i-1]=='W'){
      lw=i;
      continue;
    }

    int res;
    if(lw>0){
      int low=w.empty()?0:w.back();
      int right=max(lw+m,low+i-1);
      res=right-lw+1;
    } else{
      res=1;
      if(!w.empty()){
	res+=i;
	int j=lower_bound(gaps.begin(),gaps.end(),i)-gaps.begin();
	res+=pref[j]+(gaps.size()-j)*i;
      }
    }
    ans.push_back(res);
  }
  return ans;
}

int main(){
  int t; cin>>t;
  while(t--){
    int n,m; cin>>n>>m;
    string s,t; cin>>s>>t;

    vector<int> a=solve(s,t);
    vector<int> b=solve(t,s);

    for(auto &v:a) cout<<v<<" ";
    cout<<"\n";

    for(auto &v:b) cout<<v<<" ";
    cout<<"\n";
    
  }
}
