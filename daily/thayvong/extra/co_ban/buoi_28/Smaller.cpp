#include<bits/stdc++.h>
#define ll long long
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define simon "Smaller"
using namespace std;
const int N=1e5+5;

int n, q, a[N], b[N];
map<int, int> f;

int main(){
    FASTio
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }

    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        b[i]=a[i];
    }
    sort(a+1, a+1+n);

    f[a[1]]=0;
    for (int i=2; i<=n; i++){
        if ( a[i] > a[i-1] )
            f[a[i]]=i-1;
    }
    cin >> q;
    for (int i=1; i<=q; i++){
        int id;
        cin >> id;
        cout << f[b[id]] <<'\n';
    }
    return 0;
}
