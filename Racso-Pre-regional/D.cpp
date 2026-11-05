#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;

const int MAX_N=1e5+10;

vector<vi> G;

int pa[MAX_N];

int ns=0;
void init(int n){
  ns=0;
  for(int i=0;i<=n;i++)
    pa[i]=i;
}

int findset(int i){
  return (i==pa[i])?i:pa[i]=findset(pa[i]);
}
bool issameset(int i,int j){
  return findset(i)==findset(j);
}
void unionset(int i,int j){
  if(!issameset(i,j)){
    int u=findset(i);
    int v=findset(j);
    pa[u]=v;
    ns--;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t; cin>>t;
  while(t--){
    int n,m,q; cin>>n>>m>>q;
    G.assign(n+1,vi());

    set<int> s;
    
    vector<ii> x(n);
    for(int i=0;i<n;i++){
      cin>>x[i].first;
      s.insert(x[i].first);
      x[i].second=i+1;
    }
    
    for(int i=0;i<n;i++){
      int a; cin>>a;
    }
    for(int i=0;i<m;i++){
      int a,b; cin>>a>>b;
      G[a].push_back(b);
      G[b].push_back(a);
    }
    vector<ii> line(q);
    for(int i=0;i<q;i++){
      cin>>line[i].first;
      s.insert(line[i].first);
      line[i].second=i;
    }

    map<int,int> coord;
    int c=0;
    for(auto &v:s){
      coord[v]=c++;
    }
    for(ii &xi:x) xi.first=coord[xi.first];
    for(ii &li:line) li.first=coord[li.first];

    vector<int> ans(q);

    sort(line.begin(),line.end());
    sort(x.begin(),x.end());
    int i=0;

    vector<bool> act(n+1,0);
    init(n);
    for(int j=0;j<q;j++){
      while(i<n && x[i].first<line[j].first){
	act[x[i].second]=1;
	ns++;
	
	for(auto &u:G[x[i].second]){
	  if(act[u]){
	    unionset(x[i].second,u);
	  }
	}
	i++;
      }
      ans[line[j].second]=ns;
    }


    init(n);
    act.assign(n+1,0);
    i=n-1;
    for(int j=q-1;j>=0;j--){
      while(i>=0 && x[i].first>line[j].first){
	act[x[i].second]=1;
	ns++;

	for(auto &u:G[x[i].second]){
	  if(act[u]){
	    unionset(x[i].second,u);
	  }
	}
	i--;
      }
      ans[line[j].second]+=ns;
    }
    for(int a:ans) cout<<a<<" ";
    cout<<'\n';
  }
}
