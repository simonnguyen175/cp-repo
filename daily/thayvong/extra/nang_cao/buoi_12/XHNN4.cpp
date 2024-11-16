#include <bits/stdc++.h>
using namespace std;

int n, a[200001], b[200001];
map<int, int> d;

int main(){
    freopen("XHNN4.inp","r",stdin);
    freopen("XHNN4.out","w",stdout);
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        d[a[i]]++;
    }
    int MAX=0;
    for (int i=1; i<=n; i++)
        MAX=max(MAX, d[a[i]]);
    cout << MAX <<'\n';
    int tmp=0;
    for (int i=1; i<=n; i++)
        if ( d[a[i]] == MAX ){
            b[++tmp]=a[i];
            d[a[i]]=0;
        }
    sort(b+1,b+1+tmp);
    for (int i=1; i<=tmp; i++)
        cout << b[i] <<' ';
    return 0;
}
