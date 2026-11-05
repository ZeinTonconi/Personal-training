#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_N=2e5+10;
const int MAX_P=4*MAX_N;

ll st[MAX_P];
ll st_inv[MAX_P];
ll val[MAX_N];
bool inv[MAX_P];

ll trans;

void init(int node,int a,int b){
  if(a==b){
    st_inv[node]=val[a]^trans;
    st[node]=val[a];
    inv[node]=0;
    return;
  }
  int mid=(a+b)/2,le=2*node+1,ri=2*node+2;
  init(le,a,mid);
  init(ri,mid+1,b);
  st[node]=st[le]+st[ri];
  st_inv[node]=st_inv[le]+st_inv[ri];
  inv[node]=0;
}

void propagate(int node,int a, int b){
  if(!inv[node]) return;

  swap(st[node],st_inv[node]);
  inv[node]=0;
  if(a==b) return;
  int le=2*node+1,ri=2*node+2;
  inv[le]^=1;
  inv[ri]^=1;
  
}

void update(int node,int a,int b,int id,int v){
  propagate(node,a,b);
  if(id<a || id>b) return;
  
  if(a==b){
    st[node]=v;
    st_inv[node]=v^trans;
    return;
  }
  
  int mid=(a+b)/2,le=2*node+1,ri=2*node+2;
  
  update(le,a,mid,id,v);
  update(ri,mid+1,b,id,v);
  
  st[node]=st[le]+st[ri];
  st_inv[node]=st_inv[le]+st_inv[ri];
}

void invert(int node,int a,int b,int l,int r){
  propagate(node,a,b);
  if(b<l || r<a) return;
  if(l<=a && b<=r) {
    inv[node]^=1;
    propagate(node,a,b);
    return;
  }
  int mid=(a+b)/2,le=2*node+1,ri=2*node+2;
  invert(le,a,mid,l,r);
  invert(ri,mid+1,b,l,r);
  
  st[node]=st[le]+st[ri];
  st_inv[node]=st_inv[le]+st_inv[ri];
}

ll query(int node,int a,int b,int l,int r){
  propagate(node,a,b);
  if(b<l || r<a) return 0;
  
  if(l<=a && b<=r) return st[node];
  
  int mid=(a+b)/2,le=2*node+1,ri=2*node+2;
  return query(le,a,mid,l,r)+query(ri,mid+1,b,l,r);
}



int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n,k; cin>>n>>k;
  trans=(1<<k)-1;
  for(int i=0;i<n;i++){
    cin>>val[i];
  }
  int q; cin>>q;
  init(0,0,n-1);
  while(q--){
    int op,a,b; cin>>op>>a>>b;
    if(op==1){
      a--;
      update(0,0,n-1,a,b);
    }
    if(op==2){
      a--; b--;
      invert(0,0,n-1,a,b);
    }
    if(op==3){
      a--; b--;
      cout<<query(0,0,n-1,a,b)<<'\n';
    }

  }
}
