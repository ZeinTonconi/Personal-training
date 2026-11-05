#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n,m,k;
  cin>>n>>m>>k;
  vector<int> init(n);
  for(auto &v:init) cin>>v;
  
  set<int> wins;
  vi count;
  vector<vi> bosses(m);
  int id=0;
  for(auto &boss:bosses){
    boss.resize(n);
    int c=0;
    for(int i=0;i<n;i++){
      cin>>boss[i];
      boss[i]-=init[i];
      if(boss[i]>0) c++;
    }
    if(c==0)
      wins.insert(id);
    id++;
    count.push_back(c);
  }
  vector<set<int> > ways(k);
  for(auto &w:ways){
    for(int i=0;i<m;i++) w.insert(i);
  }
  bool ok=1;
  while(k--){
    int op;
    cin>>op;
    if(op==1){
      int attr, x; cin>>attr>>x;
      attr--;
      for(int i=0;i<m;i++){
	bosses[i][attr]-=x;
	if(bosses[i][attr]+x>0 && bosses[i][attr]<=0) count[i]--;

	if(count[i]==0)
	  wins.insert(i);
      }
    } else{
      int j;
      string x; cin>>j>>x;
      j--;
      
      vector<int> era;
      if(x=="loss"){
	for(auto &v:ways[j]){
	  if(wins.find(v)!=wins.end()){
	    era.push_back(v);
	  }
	}
      } else{
	for(auto &v:ways[j]){
	  if(wins.find(v)==wins.end()){
	    era.push_back(v);
	  }
	}
      }
      for(auto &v:era){
	ways[j].erase(v);
      }
    }
  }
  for(auto &v:ways){
    if(v.size()==0){
      ok=0;
      break;
    }
  }
  cout<<(ok?"Yes\n":"No\n");
}
