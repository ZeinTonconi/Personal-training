#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

struct Sit{
  ii cor;
  int x,y,w;
  Sit(int _x,int _y, int _w): x(_x),y(_y),w(_w){
    cor=ii(x,y);
  }

  bool operator < (Sit &o) const {
    if(w==o.w) return ii(x,y)<ii(o.x,o.y);
    return w<o.w;
  }
};

void generateSits(int x,int y,vector<Sit> &sits){
  sits.push_back(Sit(x,y,x+y));
  sits.push_back(Sit(x,y+1,x+y+1));
  sits.push_back(Sit(x+1,y,x+y+1));
  sits.push_back(Sit(x+1,y+1,x+y+2+2));
}

void generateTable(int n, vector<Sit> &sits, vector<Sit> &table){
  int col=0;
  while(true){
    int i=0;
    for(int j=col;j>=0;j--){
      int x=3*i+1;
      int y=3*j+1;
      table.push_back(Sit(x, y, x+y));
      generateSits(x,y,sits);
      i++;
      if(table.size()>=n) return;
    }
    col++;
  }
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t; cin>>t;

  while(t--){
    int n; cin>>n;
    vector<int> x(n);
    for(auto &v:x) cin>>v;

    vector<Sit> sits;
    vector<Sit> table;

    generateTable(n, sits, table);

    sort(sits.begin(),sits.end());
    
    reverse(sits.begin(),sits.end());
    
    sort(table.begin(),table.end());
    reverse(table.begin(),table.end());

    map<ii,int> vis;
    for(int i=0;i<n;i++){
      int a,b;
      if(x[i]){
	while(vis[sits.back().cor]){
	  sits.pop_back();
	}
	a=sits.back().x;
	b=sits.back().y;
	vis[sits.back().cor]=1;
	sits.pop_back();
      }
      else{
	while(vis[table.back().cor]){
	  table.pop_back();
	}
	a=table.back().x;
	b=table.back().y;
	vis[table.back().cor]=1;
	table.pop_back();
      }
      cout<<a<<" "<<b<<endl;
    }
    
  }
  
}
