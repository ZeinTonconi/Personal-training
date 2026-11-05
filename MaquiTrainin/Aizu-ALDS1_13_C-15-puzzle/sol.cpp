#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

struct Puzzle{
  array<array<int,4>,4 > ma;
  int cost;

  Puzzle(array<array<int,4>, 4> _ma, int _c): ma(_ma), cost(_c){ }

  int estimation() const{
    int est=0;
    for(int i=0;i<4;i++){
      for(int j=0;j<4;j++){
	if(ma[i][j]!=16) 
	  est+=abs((ma[i][j]-1)/4-i)+abs((ma[i][j]-1)%4-j);
      }
    }
    return est+cost;
  }
  

  bool operator > (const Puzzle &o) const {
    return estimation() > o.estimation();
  }

  bool isEnd(){
    int c=1;
    for(int i=0;i<4;i++){
      for(int j=0;j<4;j++){
	if(ma[i][j]!=c)
	  return 0;
	c++;
      }
    }
    return 1;
  }

  pair<int,int> find0(){
    int pi,pj;
    for(int i=0;i<4;i++){
      for(int j=0;j<4;j++){
	if(ma[i][j]==16) return make_pair(i,j);
      }
    }
  }
  
};

struct MinCompare{
  bool operator()(const Puzzle &a, const Puzzle &b){
    return a>b;
  }
};

int X[4]={-1,0,1,0};
int Y[4]={0,1,0,-1};

int bfs(Puzzle start){
  map<array<array<int, 4>, 4>, bool> dis;
  dis[start.ma]=1;

  priority_queue<Puzzle, vector<Puzzle>, MinCompare> pq;
  pq.push(start);
  while(!pq.empty()){
    Puzzle u = pq.top();
    
    pq.pop();
    if(u.isEnd()) return u.cost;
    if(u.cost>=45) continue;

    auto [pi, pj] = u.find0();
    
    for(int k=0;k<4;k++){
      int ik=X[k]+pi;
      int jk=Y[k]+pj;
      if(ik>=0 && ik<4 && jk>=0 && jk<4){
	 swap(u.ma[ik][jk],u.ma[pi][pj]);
	 if(dis.find(u.ma) == dis.end()){
	   dis[u.ma]=1;
	   Puzzle v(u.ma,u.cost+1);
	   pq.push(v);
	 }
	 
	 swap(u.ma[ik][jk],u.ma[pi][pj]);
      }
    }
    
  }
  
}


int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  array<array<int,4>,4> in;
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      cin>>in[i][j];
      if(in[i][j]==0) in[i][j]=16;
    }
  }

  cout<<bfs(Puzzle(in,0))<<endl;
  
}
