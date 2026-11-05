#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef long long ll;

int main(){
  int n,w; cin>>n>>w;

  vector<ii> train;

  
  for(int i=0;i<n;i++){
    int a,b,c; cin>>a>>b>>c;
    train.push_back(make_pair(
			      make_pair(a-c,a),
			      i));
    train.push_back(make_pair(
			      make_pair(b+c,a),
			      -i));

  }
  sort(train.begin(),train.end(), [&](iii a, iii b){
    if(a.first.first==b.first.first){
      return a.first.second>b.first.second;
    }
    return a.first.first<b.first.first;
  });

  set<int> use;

  vector<int> ans;
  int start,end;
  ll sum=0;
  for(int i=0;i<n;i++){
    if(sum+train[i].first.first<=w && use.find(-train[i].second)==use.end()){
      sum+=tran[i].first.first;
      use.insert(train[i].second);
      if(use.size()==1) start=train[i].second;
      if(use.size()==2) end=train[i].second;
      if(use.size()==3) break;
    }
  }

  sort(train.begin(),train.end(),[&](iii a,iii b){
    return a.first.second<b.first.second;
  });

  for(int i=0;i<n;i++){
    if(sum+train[i].first.second<=w && use.find(train[i].second)==use.end() && use.find(-train[i].second)==use.end()){
      sum+=train[i].first.second;
      use.insert(train[i].second);
      ans.push_back(train[i].second);
    }
  }
  ans.insert(ans.begin(),start);
  ans.push_back(end);
  cout<<ans.size()<<endl;
  for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
    
  }
  cout<<endl;
}
