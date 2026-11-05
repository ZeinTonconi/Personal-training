#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

ii operator + (const ii &a, const ii &b){
  return ii(a.first+b.first,a.second+b.second);
}

ii operator - (const ii &a, const ii &b){
  return ii(a.first-b.first,a.second-b.first);
}

void countMaze(vector<string> &vs,int n, ii &s, int &w){
  s=ii(0,0);
  w=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(vs[i][j]=='#'){
	s=s+ii(i,j);
	s.first%=n; s.second%=n;
	w++;
      }
    }
  }
}

int gcd(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

int inv(int w,int n){
  int x,y;
  int g=gcd(w,n,x,y);
  return (x%n+n)%n;
}

int main(){
  string run; cin>>run;
  int t; cin>>t;
  while(t--){
    int n; cin>>n;
    vector<string> vs(n);
    for(auto &v:vs) cin>>v;
    
    if(run=="first"){
      ii x; cin>>x.first>>x.second;
      x=x-ii(1,1);
      ii s;
      int w;
      countMaze(vs,n,s,w);

      ii delta=ii(((w*x.first-s.first)%n+n)%n,((w*x.second-s.second)%n+n)%n);
      ii p,q;
      for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
	  if(vs[i][j]=='#' && vs[(i+delta.first)%n][(j+delta.second)%n]=='.'){
	    p=ii(i,j);
	    q=ii((i+delta.first)%n,(j+delta.second)%n);
	  }
	}
      }
      cout<<p.first+1<<" "<<p.second+1<<" "<<q.first+1<<" "<<q.second+1<<endl;
   
    }
    else{
      ii s; int w;
      countMaze(vs,n,s,w);
      ii x=ii((s.first*inv(w,n))%n,(s.second*inv(w,n))%n);
      cout<<x.first+1<<" "<<x.second+1<<endl;
    }
  }
}
