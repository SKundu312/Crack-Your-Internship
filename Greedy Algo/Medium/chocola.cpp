#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector<int> x(n-1,0);
		vector<int> y(m-1,0);
		for(int i=0;i<x.size();i++){
			int t;
			cin>>t;
			x[i]=t;
		}
		for(int i=0;i<y.size();i++){
			int t;
			cin>>t;
			y[i]=t;
		}
		int hz=1,vr=1;
		sort(x.begin(),x.end(),greater<int>());
		sort(y.begin(),y.end(),greater<int>());
		int i=0,j=0,ans=0;
		while(i<x.size() && j<y.size()){
			if(x[i]<=y[j]){
				ans+=x[i]*vr;
				i++;
				hz++;
			}
			else{
				ans+=y[j]*hz;
				j++;
				vr++;
			}
		}
		while(i<x.size()){
			ans+=x[i]*vr;
				i++;
		}
		while(j<y.size()){
			ans+=y[j]*hz;
				j++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
