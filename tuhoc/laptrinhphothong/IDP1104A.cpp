#include <bits/stdc++.h>
using namespace std;

int n,q;
int a[100001],r[100001];
int s[100001];

int main(){
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    s[0]=0;
    for (int i=1; i<=n; i++)
        s[i]=s[i-1]+a[i];
    cin >> q;
    for (int i=1; i<=q; i++)
        cin >> r[i];
    for (int i=1; i<=q; i++)
        cout << s[r[i]]<<"\n";
    return 0;
}
