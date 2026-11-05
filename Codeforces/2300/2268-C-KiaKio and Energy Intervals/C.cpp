#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int MAX_A=(1<<18)+10;

int last[MAX_A];

struct Query{
  int l,r,x;
};

bool check(vector<int> &x,int m){
  int n=x.size();
  vector<int> pref(n+2,0);
  
  for(int i=0;i<n;i++){
    pref[i+1]=pref[i]^(x[i]&m);
  }

  vector<ii> ranges(n);
  
  stack<int> st;
  for(int i=0;i<n;i++){
    while(!st.empty() && ii(x[st.top()],st.top())<=ii(x[i],i))
      st.pop();
    ranges[i].first=st.empty()?-1:st.top();
    ranges[i].first++;
    st.push(i);
  }

  while(!st.empty()) st.pop();
  for(int i=n-1;i>=0;i--){
    while(!st.empty() && ii(x[st.top()],st.top())<=ii(x[i],i))
      st.pop();
    ranges[i].second=st.empty()?n:st.top();
    st.push(i);
  }
  
  vector<vector<Query> > query(n+2);

  //cout<<m<<endl;
  
  for(int i=0;i<n;i++){
    if((x[i]&m)!=m) continue;
    int L=ranges[i].first;
    int R=ranges[i].second;
    int sl=i-L+1;
    int sr=R-i;
    // cout<<sl<<" "<<sr<<endl;
    if(sl>sr){
      for(int r=i+2;r<=R;r++){
	int ql=L;
	int qr=i+1;
	query[qr].push_back({ql,qr,pref[r]^m});
      }
      if(L<i){
	int ql=L;
	int qr=i;
	query[qr].push_back({ql,qr,pref[i+1]^m});
      }  
    } else{
      for(int l=L;l<i;l++){
	int ql=i+1;
	int qr=R+1;
	query[qr].push_back({ql,qr,pref[l]^m});
      }

      if(i+2<=R){
	int ql=i+2;
	int qr=R+1;
	query[qr].push_back({ql,qr,pref[i]^m});
      }
      
    }
    
  }

  bool ok=0;
  
  for(int i=0;i<=n+1;i++){

    for(auto &q:query[i]){
      if(last[q.x]>=q.l){
	ok=1;
      }
    }
    
    last[pref[i]]=i;
  }
  
  for(int i=0;i<=n+1;i++) last[pref[i]]=-1;
  
  return ok;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  memset(last,-1,sizeof last);
  int t; cin>>t;
  while(t--){
    int n; cin>>n;
    vector<int> x(n);
    for(auto &v:x) cin>>v;

    int ans=0;
    for(int i=17;i>=0;i--){
      if(check(x,ans|(1<<i)))
	 ans|=(1<<i);
    }
    cout<<ans<<endl;
    
  }
}
