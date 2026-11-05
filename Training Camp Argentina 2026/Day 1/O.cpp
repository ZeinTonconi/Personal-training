#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;

ll norm(ii a){
    return a.first*a.first + a.second*a.second;
}

bool solve(vector<int> ord,vector<ii> &v, vector<int> &ans ){
  ii cur = {0,0};
  for(int id : ord){
    ii add = {cur.first+v[id].first,
	      cur.second+v[id].second};

    ii sub = {cur.first-v[id].first,
	      cur.second-v[id].second};

    if(norm(add)<=norm(sub)){
      ans[id]=1;
      cur=add;
    }else{
      ans[id]=-1;
      cur=sub;
    }
  }

  return norm(cur)<=1500000LL*1500000LL;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;

    vector<pair<ll,ll>> v(n);
    vector<int> ans(n);

    for(int i= 0;i<n;i++)
        cin>>v[i].first>>v[i].second;


    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);

    if(!solve(ord,v,ans)){
        sort(ord.begin(), ord.end(), [&](int a, int b){
            return norm(v[a])<norm(v[b]);
        });
        solve(ord,v,ans);
    }

    for(int x:ans)
        cout<<x<< ' ';
    cout<<'\n';
}
