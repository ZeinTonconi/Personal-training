#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

const int MAX_N=1e6+10;

const ll MOD = 998244353;
const ll ROOT = 3;

ll mod_pow(ll a, ll e) {
    ll r = 1;
    while (e) {
        if (e & 1)
            r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

void ntt(vector<ll>& a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        ll wlen = mod_pow(
            ROOT,
            (MOD - 1) / len
        );
        if (invert)
            wlen = mod_pow(wlen, MOD - 2);
        for (int i = 0; i < n; i += len) {
            ll w = 1;
            for (int j = 0; j < len / 2; j++) {
                ll u = a[i + j];
                ll v = a[i + j + len / 2] * w % MOD;

                a[i + j] = u + v < MOD
                    ? u + v
                    : u + v - MOD;

                a[i + j + len / 2] = u - v >= 0
                    ? u - v
                    : u - v + MOD;

                w = w * wlen % MOD;
            }
        }
    }

    if (invert) {
        ll inv_n = mod_pow(n, MOD - 2);
        for (ll& x : a)
            x = x * inv_n % MOD;
    }
}

vector<ll> multiply_ntt(const vector<ll>& a, const vector<ll>& b) {
    if (a.empty() || b.empty())
        return {};

    int need = a.size() + b.size() - 1;
    int n = 1;

    while (n < need)
        n <<= 1;

    vector<ll> fa(a.begin(), a.end());
    vector<ll> fb(b.begin(), b.end());

    fa.resize(n);
    fb.resize(n);

    ntt(fa, false);
    ntt(fb, false);

    for (int i = 0; i < n; i++)
        fa[i] = fa[i] * fb[i] % MOD;

    ntt(fa, true);

    fa.resize(need);

    return fa;
}

vector<vi> G;

int pa[MAX_N];
int dp[MAX_N];

void dfs(int u,int p, vector<int> &dis){
  pa[u]=p;
  dp[u]=0;
  for(auto &v:G[u]){
    if(v!=p){
      dis[v]=dis[u]+1;
      dfs(v,u,dis);
      dp[u]=max(dp[v]+1,dp[u]);
    }
  }
}

int getDepth(int u,vector<int> &dis){
  dis[u]=0;
  dfs(u,u,dis);
  return *max_element(dis.begin(),dis.end());
}

void mark(int u,int p,vector<ll> &d, vector<int> &dis){
  int c=0;
  for(auto &v:G[u]){
    if(v!=p && dp[u]==dp[v]+1) {
	c++;
	mark(v,u,d,dis);
    }
  }
  if(c>=2) d[dis[u]]=1;
}

int getTwice(int s,vector<ll> &d){
  vector<int> dis(d.size(),0);
  int m=getDepth(s,dis);
  mark(s,s,d,dis);
  return m;
}

void erase(vector<int> &v,int x){
  for(int i=0;i<v.size();i++){
    if(v[i]==x){
      v.erase(v.begin()+i);
      i--;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t; cin>>t;
  while(t--){
    int n; cin>>n;
    G.clear(); G.resize(n+1);
    for(int i=0;i<n-1;i++){
      int a,b; cin>>a>>b;
      G[a].push_back(b);
      G[b].push_back(a);
    }
    vector<int> dis(n+1);
    int maxDepth=getDepth(1,dis);
    int e=1,ma=0;
    for(int i=1;i<=n;i++){
      if(maxDepth==dis[i]){
	e=i;
	break;
      }
    }
    dis.assign(n+1,0);
    maxDepth=getDepth(e,dis);

    int u,v;
    for(int i=1;i<=n;i++){
      if(dis[i]-1==maxDepth/2 && dis[i]+dp[i]==maxDepth){
	u=i; v=pa[i];
	erase(G[u],v);
	erase(G[v],u);
	break;
      }
    }
    
    vector<ll> d1(n+1),d2(n+1);
    int m1=getTwice(u,d1);

    int m2=getTwice(v,d2);
    vector<ll> mul=multiply_ntt(d1,d2);

    
    set<int> ans;
    for(int i=0;i<=n;i++){
      if(mul[i]) ans.insert(i+1);
      if(d1[i]) ans.insert(i+m2+1);
      if(d2[i]) ans.insert(i+m1+1);
    }
    ans.insert(maxDepth);
    cout<<ans.size()<<" ";
    for(auto &v:ans) cout<<v<<" ";
    cout<<'\n';
  }
}
