#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  int n; cin>>n;
  vector<vector<ll> > x(n);
  for(int i=0;i<n;i++){
    x[i].resize(n);
    for(auto &v:x[i]) cin>>v;
  }

  vector<ll> row(n),col(n);
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){\
      row[i]+=x[i][j];
      col[j]+=x[i][j];
    }
  }
  int ans=0;
  for(int i=0;i<n;i++){
     for(int j=0;j<n;j++){
       if(col[j]>row[i]) ans++;
     } 
  }
  cout<<ans<<endl;
  
}
