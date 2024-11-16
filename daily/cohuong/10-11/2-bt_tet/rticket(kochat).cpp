#include <bits/stdc++.h>
using namespace std;

int l[4], c[4], n, s, t;
long long a[10001], len[10001], oo=1000000000000000001;

int main(){
    cin >> l1 >> l2 >> l3;
    cin >> c1 >> c2 >> c3;
    cin >> n >> s >> t;
    if ( s > t ) swap(s,t);
    for (int i=2; i<= n; i++)
        cin >> a[i];
    int i1=s, i2=s, i3=s;
    len[s]=0;
    for (int i=s+1; i<=t; i++){
        len[i]=oo;
        while (a[i]-a[i1]>l[1]) i1++; len[i]=min(len[i],len[i1]+c1);
        while (a[i]-a[i2]>l[2]) i2++; len[i]=min(len[i],len[i2]+c2);
        while (a[i]-a[i3]>l[3]) i3++; len[i]=min(len[i],len[i3]+c3);
    }
    cout << len[t];
    return 0;
}
