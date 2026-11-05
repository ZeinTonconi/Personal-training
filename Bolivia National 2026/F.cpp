#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

template <int B = 61>
struct XorBasis {

  ull basis[B]{};
  int source[B];
  int rank = 0;
  bool signature[B][100010];

  XorBasis() {
    fill(source, source + B, -1);
  }

  ull coeff[B]{};

  bool insert(ull x, int idx) {
    ull used = 1ULL << idx;

    for (int i = B - 1; i >= 0; --i) {
      if (((x >> i) & 1ULL) == 0) continue;

      if (basis[i]) {
	x ^= basis[i];
	used ^= coeff[i];
      } else {
	basis[i] = x;
	coeff[i] = used;
	++rank;
	return true;
      }
    }
    return false;
  }
  
};

typedef pair<int,int> ii;

template <int B = 61>
void mark(ull x, XorBasis<B>& b, int j) {
  ull used = 0;

  for (int i = B - 1; i >= 0; --i) {
    if (((x >> i) & 1ULL) == 0) continue;

    x ^= b.basis[i];
    used ^= b.coeff[i];
  }

  for (int i = 0; i < b.rank; ++i) {
    if ((used >> i) & 1ULL) {
      b.signature[i][j] = 1;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n,b; cin>>n>>b;
  XorBasis xorBasis;
  vector<ll> x;
  for(int i=0;i<n;i++){
    ll a; cin>>a;
    if(!xorBasis.insert(a, xorBasis.rank))
      x.push_back(a);
  }

  int t=x.size();
  for(int i=0;i<t;i++){
    mark(x[i],xorBasis,i);
  }

  map<vector<bool>,ii> g;
  for(int r=0;r<xorBasis.rank;r++){
    vector<bool> sig;
    int c=0;
    for(int i=0;i<t;i++){
      sig.push_back(xorBasis.signature[r][i]);
      c+=xorBasis.signature[r][i];
    } 
    g[sig].first++;
    g[sig].second=c;
  }
  
  int ans=0;
  for(int i=0;i<8;i++){
    bool ok=1;
    for(auto &v:g){
      int labels=(1<<i);
      
      if(v.second.second==0)
	labels-=(i+1);
      else if(v.second.second==1)
	labels-=1;
      if(labels<v.second.first){
	ok=0;
	break;
      }
    }
    if(ok){
      ans=i;
      break;
    }
  }
  cout<<ans<<'\n';
}
