#include <bits/stdc++.h>
using namespace std;

long long a[5];

int main(){
    freopen("FourSeg.inp","r",stdin);
    freopen("FourSeg.out","w",stdout);
    for (int i=1; i<=4; i++)
        cin >> a[i];
    sort(a+1,a+1+4);
    long long cd=min(a[3],a[4]);
    long long cr=min(a[1],a[2]);
    cout << cd*cr;
    return 0;
}
