#include<bits/stdc++.h>
using namespace std;
int n;
pair <int,int> a[500001];
stack <pair <int,int>> st;
int main(){
	freopen("ShorterFront.inp","r",stdin);
	freopen("ShorterFront.out","w",stdout);
	ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].first;
	for(int i=1;i<=n;i++)
		a[i].second=i;
	cout<<0<<"\n";
	st.push(a[1]);
	for(int i=2;i<=n;i++){
		if(st.top().first>=a[i].first)
			while(st.top().first>=a[i].first){
				st.pop();
				if(st.size()==0) break;
			}
		if(st.size()==0) cout<<0<<"\n";
        else cout<<st.top().second<<"\n";
		st.push(a[i]);
	}
	return 0;
}
