#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int MAX_C=2e5+10;

ii ft[MAX_C];

int lsone(int s){
  return s&(-s);
}

void init(int c){
  for(int i=0;i<c;i++)
    ft[i]=ii(0,-1);
}

ii query(int id){
  if(id==0) return ii(0,-1);
  ii res=ii(0,-1);
  for(;id;id-=lsone(id))
    res=max(res,ft[id]);
  
  return res;
}

void update(int id,ii v,int c){
  for(;id<c;id+=lsone(id))
    ft[id]=max(ft[id],v);
  
}

int main(){

  freopen("people.in", "r", stdin);
  freopen("people.out", "w", stdout);
  
  int n; cin>>n;
  set<int> s;
  vector<ii> x;
  for(int i=0;i<n;i++){
    int a,b; cin>>a>>b;
    s.insert(a);
    s.insert(b);
    x.push_back(ii(a,b));
  }

  map<int,int> comp;
  int c=1;
  for(auto &v:s){
    comp[v]=c++;
  }
  for(auto &v:x){
    v.first=comp[v.first];
    v.second=comp[v.second];
  }

  vector<vector<ii> > gro(c);
  for(int i=0;i<n;i++){
    auto [a,b] = x[i];
    gro[a].push_back(ii(b,i));
  }

  init(c);

  vector<int> mem(n);
  int ans=0;
  int end;
  for(auto &g:gro){
    vector<ii> que;
    for(auto &p: g){
      ii q=query(p.first-1);
      q.first++;
      mem[p.second]=q.second;
      q.second=p.second;
      que.push_back(q);
      if(ans<q.first){
	ans=q.first;
	end=p.second;
      }
      //cout<<p.second<<": "<<q.first<<", "<<q.second<<endl;
    }

    for(int i=0;i<que.size();i++)
      update(g[i].first,que[i],c);
    
  }
  
  vector<int> vans;
  while(end!=-1){
    vans.push_back(end);
    end=mem[end];
  }
  cout<<ans<<"\n";
  for(auto v:vans) cout<<v+1<<" ";
  cout<<"\n";
  
}
