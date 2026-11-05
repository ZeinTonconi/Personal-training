#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int ma[4][4];

int encode(){
  int p=1;
  int en=0;
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      en+=ma[i][j]*p;
      p*=10;
    }
  }
  return en;
}

void decode(int mask){
  
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      ma[i][j]=mask%10;
      mask/=10;
    }
  }
}


int X[5]={-1,0,1,0};
int Y[5]={0,1,0,-1};



int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++)
      cin>>ma[i][j];
  }
  unordered_map<int,int> dis;
  queue<int> q;
  q.push(encode());

  while(!q.empty()){
    int mask=q.front();
    q.pop();
    decode(mask);
    
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
	if(ma[i][j]==0){
	  for(int k=0;k<4;k++){
	    int ik=X[k]+i;
	    int jk=Y[k]+j;
	    if(ik>=0 && ik<3 && jk>=0 && jk<3){
	      swap(ma[ik][jk],ma[i][j]);

	      if(dis.find(encode())==dis.end() ||dis[encode()]>dis[mask]+1){
		dis[encode()]=dis[mask]+1;
		q.push(encode());
	      }
      
	      swap(ma[ik][jk],ma[i][j]);
	    }
	  }
	}
      }
    }
  }

  int ma=0;
  for(auto &v:dis){
    ma=max(ma,v.second);
  }
  cout<<ma<<endl;
  
  cout<<dis[87654321]<<endl;
  
}
