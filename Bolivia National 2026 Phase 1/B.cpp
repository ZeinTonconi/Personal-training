#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef long long ll;

const int MAX=1e9+10;
const ll mod=1e9+7;

ll pot(ll b,ll e){
  ll ans=1;
  ll pow=b;
 
  while(e!=0){
    if(e%2==1)
      ans=(ans*pow)%mod;
    pow=(pow*pow)%mod;
    e/=2;
  }
  return ans;
}

int main(){
  int n; cin>>n;
  vector<ii> ranges(n);
  for(auto &v:ranges){
    cin>>v.first>>v.second;
    v.second++;
  }

  int maxL=0,minR=MAX;
  for(int i=n-1;i>=0;i--){
    minR=min(minR,ranges[i].second);
    ranges[i].second=minR;
  }

  for(int i=0;i<n;i++){
    maxL=max(maxL,ranges[i].first);
    ranges[i].first=maxL;
  }

  vector<int> ends;
  for(auto &v:ranges){
    ends.push_back(v.first);
    ends.push_back(v.second);
  }
  sort(ends.begin(),ends.end());
  ends.erase(unique(ends.begin(),ends.end()),ends.end());

  int t=ends.size();
  vector<int> pref(t);
  vector<int> open(t);
  vector<int> close(t);
  for(auto &v:ranges){
    auto it=lower_bound(ends.begin(),ends.end(),v.first);
    pref[it-ends.begin()]++;
    open[it-ends.begin()]++;
    it=lower_bound(ends.begin(),ends.end(),v.second);
    pref[it-ends.begin()]--;
    close[it-ends.begin()]++;
  }
  for(int i=1;i<t;i++){
    pref[i]+=pref[i-1];
    open[i]+=open[i-1];
    close[i]+=close[i-1];
  }

  vector<vector<ll> > combi;
  combi.assign(t,vector<ll> (n+1,0));

  vector<int> dis;
  for(int i=0;i<t-1;i++){
    int d=ends[i+1]-ends[i];
    combi[i][0]=1;
    for(int j=1;j<=min(d,n);j++){
      combi[i][j]=(((combi[i][j-1]*(ll)(d-j+1))%mod)*pot(j,mod-2))%mod;
    }
    dis.push_back(d);
  }


  vector<ll> dp(n+1),prev(n+1,0);
  prev[0]=1;

  for(int i=0;i<t-1;i++){
    for(int j=0;j<=n;j++){
      ll sum=0;

      for(int k=close[i];k<=j;k++){
	int rest=j-k;
	if(rest<=min({pref[i],dis[i],open[i]-k}))
	  sum=(sum+(prev[k]*combi[i][rest])%mod)%mod;
      }
      
      dp[j]=sum;
    }
    prev=dp;
  }
  cout<<prev[n]<<endl;
  
}
