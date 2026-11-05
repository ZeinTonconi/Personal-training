#include <bits/stdc++.h>
using namespace std;

int getAns(vector<int> &x){
  int n=x.size();
  int ans=n;
  for(int i=1;i<n;i++){
    if(x[i]==x[i-1]){
      ans--;
    }
  }
  return ans;
}


int main(){
  int t; cin>>t;
  while(t--){
    int  n; cin>>n;
    vector<int> x(n);
    for(auto &v:x) cin>>v;
    vector<bool> bucket(n);
    int c=0;
    for(int i=0;i<n-1;i++){
      if(x[i]==x[i+1]){
	bucket[i]=bucket[i+1]=1;
      }
    }

    int ans=getAns(x);

    for(int i=0;i<n-1;i++){
      if(x[i]!=x[i+1] && bucket[i] && bucket[i+1]){
	swap(x[i],x[i+1]);
	ans=max(ans,getAns(x));
	swap(x[i],x[i+1]);
	break;
      }
    }
    
    for(int i=0;i<n;i++){

      if(bucket[i]){
	if(i-1>=0 && !bucket[i-1]){
	  if(i-2<0 || x[i-2]!=x[i]){
	    swap(x[i],x[i-1]);
	    ans=max(ans,getAns(x));
	    swap(x[i],x[i-1]);
	    break;
	  }
	}
	
	if(i+1<n && !bucket[i+1]){
	  if(i+2>=n || x[i]!=x[i+2]){
	    swap(x[i],x[i+1]);
	    ans=max(ans,getAns(x));
	    swap(x[i],x[i+1]);
	    break;
	  }
	}
      }
      
    }
    cout<<ans<<endl;
  }
}
