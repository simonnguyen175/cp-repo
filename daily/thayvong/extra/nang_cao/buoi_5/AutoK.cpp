#include<bits/stdc++.h>
using namespace std;
long long n,k,a[200001],h[200001];
int main(){
	freopen("autok.inp","r",stdin);
	freopen("autok.out","w",stdout);
	cin>>n>>k;
	memset(h,-1,sizeof(h));
	for (int i=1; i<=n; i++)
        cin >> a[i];
    long long s=1, t=0, e, x;
    for (int i=1; i<=k; i++){
        s=a[s];
        if (h[s]==-1) h[s]=i;
        else{
            e=i-h[s];
            x=k-i;
            t=x%e;
            break;
        }
    }
    for (int i=1; i<=t; i++)
        s=a[s];
    cout << s ;
    return 0;
}

