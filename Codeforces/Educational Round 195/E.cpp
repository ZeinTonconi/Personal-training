/* We can put a linear function into a range offline, mainting two arrays
   the actual value and how much should i substract for the next position
   even if they are multiple linear functions in a range.
   For example here we need to add c, c-1, c-2, ..., 0 so we add c to one
   array and +1 to the other array and in each step we are decreasing by
   one the c, so if we acumulate this the actual value and how much we
   decrease we can update the range with linear functions
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
  int t; cin>>t;
  while(t--){
    int n; cin>>n;

    string x; cin>>x;
    vector<int> p2,p0,p5,p6;
    for(int i=0;i<n;i++){
      if(x[i]=='2') p2.push_back(i);
      if(x[i]=='0') p0.push_back(i);
      if(x[i]=='5') p5.push_back(i);
      if(x[i]=='6') p6.push_back(i);
    }
    p2.push_back(n);
    p0.push_back(n);
    p5.push_back(n);
    p6.push_back(n);

    vector<ll> ctte(n+1);
    vector<ll> decr(n+1);
    vector<ll> numf(n+1);
    
    for(int i=0;i<n;i++){

      auto it=lower_bound(p2.begin(),p2.end(),i);

      it=lower_bound(p0.begin(),p0.end(),*it);

      it=lower_bound(p2.begin(),p2.end(),*it);

      int i5=(*lower_bound(p5.begin(),p5.end(),*it));

      int i6=(*lower_bound(p6.begin(),p6.end(),*it));

      if(i5<i6){
	int c=i6-i5;
	ctte[i]+=c;
	ctte[i5]-=c;
	decr[i5]+=c;
	numf[i5]++;
	numf[i6]--;
      }
      
    }

    ll sumCtte=0;
    ll sumDecr=0;
    ll sumNumf=0;

    for(int i=0;i<n;i++){
      sumCtte+=ctte[i];
      sumDecr+=decr[i];
      sumNumf+=numf[i];

      ll bad=sumCtte+sumDecr;
      sumDecr-=sumNumf;

      ll ans=1LL*(i+1)*(n-i);
      cout<<ans-bad<<" ";
      
    }
    cout<<endl;
  }

}
