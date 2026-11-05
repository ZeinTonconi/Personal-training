#include <bits/stdc++.h>
using namespace std;
int main(){
  string s,x; cin>>s>>x;

  vector<int> count[10];
  
  for(int i=0;i<x.size();i++){
    count[x[i]-'0']++;
  }

  int id=9;

  for(int i=0;i<s.size();i++){

    while(id-1>=0 && count[id]
    
  }
  
  for(int i=0;i<s.size();i++){
    if(!q.empty() && q.top()>s[i]-'0'){
      s[i]=q.top()+'0';
      q.pop();
    }
  }
  cout<<s<<endl;
}
