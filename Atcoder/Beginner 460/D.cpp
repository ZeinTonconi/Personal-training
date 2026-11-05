#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;

const int MAX=1e9;

int X[10]={-1,-1,0,1,1,1,0,-1};
int Y[10]={0,1,1,1,0,-1,-1,-1};

int main(){
  int h,w; cin>>h>>w;
  vector<string> vs(h);
  for(auto &v:vs) cin>>v;

  vector<vi> dis;
  dis.assign(h,vi(w,MAX));

  queue<ii> q;
  
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(vs[i][j]=='#'){
	for(int k=0;k<8;k++){
	  int xk=i+X[k];
	  int yk=j+Y[k];
	  if(xk>=0 && xk<h && yk>=0 && yk<w && vs[xk][yk]=='.'){
	    q.push(ii(i,j));
	    dis[i][j]=0;
	    break;
	  }
	}
      }
    }
  }
  if(q.size()==h*w || q.size()==0){
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
	cout<<".";
      }
      cout<<"\n";
    }
    return 0;
  }
  
  while(!q.empty()){
    auto [x, y]=q.front();
    q.pop();

    for(int i=0;i<8;i++){
      int xk=x+X[i];
      int yk=y+Y[i];
      if(xk>=0 && xk<h && yk>=0 && yk<w && dis[xk][yk]>dis[x][y]+1){
	dis[xk][yk]=dis[x][y]+1;
	q.push(ii(xk,yk));
      }
    }
  }

  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(dis[i][j]%2==0)
	cout<<"#";
      else cout<<".";
    }
    cout<<"\n";
  }
  
}
