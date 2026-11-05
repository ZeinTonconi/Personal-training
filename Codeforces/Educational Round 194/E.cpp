#include <bits/stdc++.h>
using namespace std;
bool check(int k,int c00,int c01,int c11){
  c01+=k;
  int d=max(c00-c01,0);
  k-=d; c00-=d;
  c11-=k;
  
  return c00<=c01 && c11<=c01 && k>=0;
}
int main(){
  int n,q; cin>>n>>q;
  string x; cin>>x;
  vector<int> p00,p01,p10,p11;

  p00.push_back(0);
  p01.push_back(0);
  p10.push_back(0);
  p11.push_back(0);
  
  int c00=0,c01=0,c10=0,c11=0;
  for(int i=0;i<n-1;i++){
    if(x[i]=='0' && x[i+1]=='0') c00++;
    if(x[i]=='0' && x[i+1]=='1') c01++;
    if(x[i]=='1' && x[i+1]=='0') c10++;
    if(x[i]=='1' && x[i+1]=='1') c11++;
    p00.push_back(c00);
    p01.push_back(c01);
    p10.push_back(c10);
    p11.push_back(c11);
  }

  while(q--){
    int l,r; cin>>l>>r;
    l--; r--;

    c00=p00[r]-p00[l];
    c01=p01[r]-p01[l];
    c10=p10[r]-p10[l];
    c11=p11[r]-p11[l];
    
    if(x[l]=='0' && x[r]=='0') c00++;
    if(x[l]=='0' && x[r]=='1') c10++;
    if(x[l]=='1' && x[r]=='0') c01++;
    if(x[l]=='1' && x[r]=='1') c11++;
    //cout<<"L: "<<l<<" R: "<<r<<" "<<c00<<" "<<c01<<" "<<c11<<endl;

    int le=-1,ri=c00+c11;
    while(ri-le>1){
      int mid=(le+ri)/2;
      if(check(mid,c00,c01,c11))
	ri=mid;
      else
	le=mid;
    }
    //cout<<"K: "<<ri<<endl;
    int op=ri;
    c01+=op;
    int d=max(0,c00-c01);
    c00-=d;
    op-=d;
    c11-=op;
    cout<<(abs(c01-c00)+abs(c01-c11))+ri<<endl;
  }
}
