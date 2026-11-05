#include <bits/stdc++.h>
using namespace std;

const int MAX_N=4e5+10;

bool name[MAX_N];

int main(){
  string x; cin>>x;

  vector<int> points;
  for(int i=0;i<n;i++){
    if(x[i]=='.'){
      for(int j=i-1;j>=max(0,i-8);j--){
	if(j-1>=0 && x[j-1]=='.') break;
	name[j]=1;
      }
    }
  }

  vector<string> ans;
  for(int i=0;i<n;i++){
    
  }
  
  
}
