#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;

vector<int> x;

vector<vi> ans;

vector<ii> y;

vi path;

void sum(int id,int c,int t){
  if(t==0){
    ans.push_back(path);
    return;
  }
  if(id==y.size())
    return;
  if(y[id].second==c){
    sum(id+1,0,t);
    return;
  }

  sum(id+1,0,t);
  if(y[id].first<=t){
    path.push_back(y[id].first);
    sum(id,c+1,t-y[id].first);
    path.pop_back();
  }
  
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t,n;
  while(cin>>t>>n && t!=0 && n!=0){
    x.assign(n,0);
    path.clear();
    y.clear();
    for(auto &v:x) cin>>v;
    
    int j=0;
    for(int i=0;i<n;i++){
      if(x[i]!=x[j]){
	y.push_back(ii(x[j],i-j));
	j=i;
      }
    }
    y.push_back(ii(x[j],n-j));

    ans.clear();

    sum(0,0,t);

    cout<<"Sums of "<<t<<":\n";
      
    if(!ans.empty()){
      
      sort(ans.begin(),ans.end(),[&](vi a,vi b){
	return a>b;
      });
      
      for(auto &v:ans){
	for(int i=0;i<v.size();i++){
	  if(i==v.size()-1) cout<<v[i]<<endl;
	  else cout<<v[i]<<"+";
	}
      }
    } else{
      cout<<"NONE\n";
    }
    
    
  }
}
