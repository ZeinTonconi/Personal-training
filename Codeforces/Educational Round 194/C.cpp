#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

int bitX[32],bitY[32];
ii dp[32][3][3];

ii makeAnswer(ii pa,int id,int actX,int actY,bool us){
  if(pa.first==-1) return pa;
  pa.first+=((actX^actY)<<id);
  pa.second+=(us?(1<<id):0);
  return pa;
}

ii join(ii a,ii b){
  if(a.first==-1) return b;
  if(b.first==-1) return a;
  
  if(a.first==b.first){
    return (a.second<b.second)?a:b;
  } 
  return (a.first>b.first)?a:b;
      
}

ii maxXor(int id,bool accP,bool accN){
  if(id==31){
    return (accN ? ii(-1,-1) : ii(0,0));
  }

  if(dp[id][accP][accN].first!=-2){
    return dp[id][accP][accN];
  }
  
  int actX=bitX[id], actY=bitY[id];
  int actN=accN, actP=accP;
  if(accN){
    actX^=1;
    if(bitX[id]) actN=0;
  }
  if(accP){
    actY^=1;
    if(!bitY[id]) actP=0;
  }
  ii ans=makeAnswer(
		    maxXor(id+1,actP,actN),
		    id,actX,actY,0);
  
  if(!actX)
    actN=1; 
  actX^=1;


  if(actY)
    actP=1;
  actY^=1;

  return dp[id][accP][accN]=join(ans,
				 makeAnswer(
					    maxXor(id+1,actP,actN)
					    ,id,actX,actY,1));
}


int main(){
  int t; cin>>t;
  while(t--){
    int x,y; cin>>x>>y;
    for(int i=0;i<31;i++){
      bitX[i]=x%2;
      x/=2;
      bitY[i]=y%2;
      y/=2;
    }
    for(int i=0;i<31;i++){
      for(int j=0;j<2;j++)
	for(int k=0;k<2;k++) dp[i][j][k]=ii(-2,-2);
    }
    ii ans=maxXor(0,0,0);
    cout<<ans.first<<" "<<ans.second<<endl;
  }
}
