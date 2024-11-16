#include <bits/stdc++.h>
using namespace std;

int n, a[200001];
map <int, int> d;

int main(){
    freopen("DDNOSORT.inp","r",stdin);
    freopen("DDNOSORT.out","w",stdout);
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        d[a[i]]++;
    }
    for (int i=1; i<=n; i++)
        if ( d[a[i]] > 0 ){
            cout << a[i] <<' ';
            d[a[i]]=0;
        }
    return 0;
}
