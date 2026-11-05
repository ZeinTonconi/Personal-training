#include <bits/stdc++.h>
using namespace std;

vector<string> board;


bool row[10],col[10],di1[15],di2[15];
int diag1[10][10], diag2[10][10];

int countQueens(int i,int j,int n){

  if(j==8)
    return countQueens(i+1,0,n);
  if(i==8)
    return n==8;

  int d1=diag1[i][j];
  int d2=diag2[i][j];
  int ans=0;
  if(!row[i] && !col[j] && !di1[d1] && !di2[d2] && board[i][j]=='.'){
    row[i]=col[j]=di1[d1]=di2[d2]=1;
    ans+=countQueens(i,j+1,n+1);
    row[i]=col[j]=di1[d1]=di2[d2]=0;
  }
  ans+=countQueens(i,j+1,n);
  return ans;
}

int main(){
  for(int i=0;i<8;i++){
    string row; cin>>row;
    board.push_back(row);
  }

  int c=0;
  
  for(int i=7;i>=0;i--){
    int j=0;
    for(int row=i;row>=0;row--){
      diag1[row][j]=c;
      diag2[row][7-j]=c;
      j++;
    }
    c++;
  }

  for(int i=1;i<8;i++){
    int j=7;
    for(int col=i;col<8;col++){
      diag1[j][col]=c;
      diag2[j][7-col]=c;
      j--;
    }
    c++;
  }

  cout<<countQueens(0,0,0)<<endl;
}
