#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int ma[110][110];

bool taken[110][110];

int main(){
  int n; cin>>n;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>ma[i][j];
    }
  }
  ll sum=0;
  for(int i=0;i<n;i++){
    if(!taken[i][i])
    sum+=ma[i][i];
    taken[i][i]=1;
    if(!taken[n/2][i])
    sum+=ma[n/2][i];
    taken[n/2][i]=1;
    if(!taken[i][n/2])
    sum+=ma[i][n/2];
    taken[i][n/2]=1;
    if(!taken[i][n-i-1])
    sum+=ma[i][n-i-1];
    taken[i][n-i-1]=1;
  }
  cout<<sum<<endl;
}
