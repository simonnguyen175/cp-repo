#include<bits/stdc++.h>
using namespace std;
int s[1000001]={0},a[100000],t,kq=0,n;
int main(){
	freopen("NoDivisible.inp","r",stdin);
	freopen("NoDivisible.out","w",stdout);
	ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		if(s[a[i]]>=1){
			s[a[i]]++;
			continue;
		}
		else{
			t=1;
			while(t*a[i]<=1000000){
				s[t*a[i]]++; t++;
			}
		}
	}
	for(int i=1;i<=n;i++)
		if(s[a[i]]==1) kq++;
	cout<<kq;
}

