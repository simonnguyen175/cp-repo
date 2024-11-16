#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 3e3 + 5;

int n;
pi a[N];

bool ss1(int i, int ran, int x){
    int tmp1[] = {a[i].fi, a[i].se, ran};
    sort(tmp1, tmp1+2);
    int tmp2[] = {a[x].fi, a[x].se, 1};
    sort(tmp2, tmp2+2);

    if ( tmp1[2] != tmp2[2] ) return tmp1[2] > tmp2[2];
    else if ( tmp1[1] != tmp2[1] ) return tmp1[1] > tmp2[1];
    else return tmp1[0] >= tmp2[0];
}

bool ss2(int i, int ran, int x){
    int tmp1[] = {a[i].fi, a[i].se, ran};
    sort(tmp1, tmp1+2);
    int tmp2[] = {a[x].fi, a[x].se, 3};
    sort(tmp2, tmp2+2);

    if ( tmp1[2] != tmp2[2] ) return tmp1[2] < tmp2[2];
    else if ( tmp1[1] != tmp2[1] ) return tmp1[1] < tmp2[1];
    else return tmp1[0] < tmp2[0];
}

void anal(int x){
//    cout << x << " : \n";
    int ran = 1, i;
    // ss1 la >= x
    for (i = n; i >= 1; i --) if ( i != x ){
        ran ++;
        while ( !ss1(i, ran, x) && ran <= n )
            ran ++;
//        cout << i << ' ' << ran << '\n';
        if ( ran > n ) break;
    }
    cout << i + 1 << ' ';

//    cout << '\n';

    // ss2 la < x
    ran = n;
    for (i = 1; i <= n; i ++) if ( i != x ){
        ran --;
        while ( !ss2(i, ran, x) && ran >= 1 )
            ran --;
//        cout << i << ' ' << ran << '\n';
        if ( ran < 1 ) break;
    }
    cout << ( i < x ? i : i - 1 ) << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("ranking.inp", "r") ){
        freopen("ranking.inp", "r", stdin);
        freopen("ranking.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i].fi;
    for (int i = 1; i <= n; i ++) cin >> a[i].se;
    for (int i = 1; i <= n; i ++)
        if ( a[i].fi < a[i].se ) swap(a[i].fi, a[i].se);
    sort(a+1, a+1+n);

    for (int i = 1; i <= n; i ++)
        cout << '(' << a[i].fi << ',' << a[i].se << ')';
    cout << '\n';

    for (int x = 1; x <= n; x ++)
        anal(x);

    return 0;
}
