#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> ans;

bool expo(int a,int b){
  if(a==0)
    return b==0;

  ll base=a%10;
  ll num=1;
  int exp=0;
  while(num<=b){
    if(b%10==num%10){
      ans.push_back(exp);
      if(expo(a/10,(b-num)/10))
	return true;
      ans.pop_back();
    }
    num*=base;
    exp++;
  }
  return false;
  
}


int main(){
  int a,b; cin>>a>>b;
  expo(a,b);
  reverse(ans.begin(),ans.end());
  for(auto &v:ans) cout<<v<<" ";
  cout<<endl;
}
