#include <bits/stdc++.h>
using namespace std;

int ma[15][15];
int pos[15][15];
int n;

int col[15][15];
int row[15][15];
int sub[15][15];

bool solve(int i,int j){
  if(i>=n*n) return true;
  
  if(ma[i][j]==0){

    bool ok=0;
    
    for(int k=1;k<=n*n;k++){
      if(!col[j][k] && !row[i][k] && !sub[pos[i][j]][k]){
	ma[i][j]=k;
	col[j][k]=1;
	row[i][k]=1;
	sub[pos[i][j]][k]=1;
	if(j+1<n*n){
	  if(solve(i,j+1)) return true;
	}
	else
	  if(solve(i+1,0)) return true;
	ma[i][j]=0;
	col[j][k]=0;
	row[i][k]=0;
	sub[pos[i][j]][k]=0;
      }
    }

    
    return false;
    
  }
  else{
    if(j+1<n*n) return solve(i,j+1);
    else return solve(i+1,0);
  }
  
  
}


int main(){
  bool first=0;

  while(cin>>n){
    if(first)
    cout<<'\n';
    first=1;

    memset(ma,0,sizeof ma);
    memset(pos,0,sizeof pos);
    memset(row,0,sizeof row);
    memset(col,0,sizeof col);
    memset(sub,0,sizeof sub);
    
    
    for(int i=0;i<n*n;i++){
      for(int j=0;j<n*n;j++){
	cin>>ma[i][j];
      }
    }
    
    int c=-1;
    for(int i=0;i<n*n;i+=n){
      for(int j=0;j<n*n;j+=n){
	c++;
	for(int k=i;k<i+n;k++){
	  for(int l=j;l<j+n;l++){
	    pos[k][l]=c;
	  }
	}
      }
    }
    
    
    for(int i=0;i<n*n;i++){
      for(int j=0;j<n*n;j++){
	if(ma[i][j]!=0){
	  col[j][ma[i][j]]++;
	  row[i][ma[i][j]]++;
	  sub[pos[i][j]][ma[i][j]]++;
	}
      }
    }

    bool ok=1;
    for(int i=0;i<n*n;i++){
      for(int j=1;j<=n*n;j++){
	if(col[i][j]>1 || row[i][j]>1 || sub[i][j]>1){
	  ok=0;
	  break;
	}
      }
      if(!ok) break;
    }

    if(ok && solve(0,0)){
      for(int i=0;i<n*n;i++){
	for(int j=0;j<n*n;j++){
	  if(j==n*n-1) cout<<ma[i][j]<<"\n";
	  else cout<<ma[i][j]<<" ";
	}
      }
    }
    else{
      cout<<"NO SOLUTION\n";
    }
  }
  
}
