#include<bits/stdc++.h>
#define simon "training"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int N = 1e6 + 5;

struct ts{
    int id;
    long long val;
};

bool cmp1(ts a, ts b){
    return a.val < b.val;
}

bool cmp2(ts a, ts b){
    return a.id < b.id;
}

long long n, m, b[N];
ts a[N];

int main(){
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    FASTio
    cin >> n >> m;

    for (int i = 1; i <= n; i ++){
        cin >> a[i].val;
        a[i].id = i;
    }
    for (int i = 1; i <= m; i ++) cin >> b[i];

    sort(a + 1, a + 1 + n, cmp1);
    sort(b + 1, b + 1 + m);

    ll s = 0;
    int j = 1;
    for (int i = 1; i <= n; i ++){
        while ( a[i].val + s >= b[j] && j <= m ){
            s += b[j];
            j ++;
        }
        a[i].val += s;
    }

    sort(a + 1, a + 1 + n, cmp2);

    for (int i = 1; i <= n; i ++)
        cout << a[i].val << ' ';

    return 0;
}
