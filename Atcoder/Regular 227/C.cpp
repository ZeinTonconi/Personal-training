#include <bits/stdc++.h>
using namespace std;
int main(){
  int n; cin>>n;
  string x; cin>>x;
  int k=n;
  for(int i=1;i<n;i++){
    bool ok=1;
    for(int j=0;j<n;j++){
      if(x[(i+j)%n]!=x[j]){
	ok=0;
	break;
      }
    }
    if(ok){
      k=i;
      break;
    }
  }
  int rep=n/k;
  cout<<rep<<endl<<n*n<<endl;
  for(int i=0;i<n;i++) cout<<x;
  cout<<endl;
}
