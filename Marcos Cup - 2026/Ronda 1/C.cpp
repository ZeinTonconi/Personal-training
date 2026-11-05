#include <bits/stdc++.h>
using namespace std;

typedef pair<double,double> dd;

int main(){
  int n; cin>>n;
  vector<dd> points(n);
  for(auto &v:points){
    cin>>v.first>>v.second;
  }

  sort(points.begin(),points.end());

  int c=0;
  
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){

      if(i==j) continue;
      
      dd p=dd((points[i].first+points[j].first)/2,
	      (points[i].second+points[j].second)/2);
      if(binary_search(points.begin(),points.end(),p)){
	c++;
      }
    }
  }
  cout<<c/2<<endl;
}
