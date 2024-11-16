#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n, t, a[25];
ll f[25][25][25][25];

ll calc(int id, int mn1, int mn2, int mx){
    if ( id > n ) return f[id][mn1][mn2][mx] = 1;
    if ( f[id][mn1][mn2][mx] != -1 ) return f[id][mn1][mn2][mx];
    ll res = 0;
    for (int c = 1; c <= n; c ++){
        int nmn1 = mn1, nmn2 = mn2, nmx = mx;
        if ( c > nmx ) nmx = c;
        if ( c < nmn1 ){
            nmn2 = nmn1; nmn1 = c;
        }
        else if ( c < nmn2 ) nmn2 = c;
        if ( nmn1 + nmn2 > nmx  ) res += calc(id+1, nmn1, nmn2, nmx);
    }
    f[id][mn1][mn2][mx] = res;
    return res;
}

void findseq(int id, int mn1, int mn2, int mx, ll cnt){
    if ( id > n ) return;
    ll res = 0;
    for (int c = 1; c <= n; c ++){
        int nmn1 = mn1, nmn2 = mn2, nmx = mx;
        if ( c > nmx ) nmx = c;
        if ( c < nmn1 ){
            nmn2 = nmn1; nmn1 = c;
        }
        else if ( c < nmn2 ) nmn2 = c;
        if ( nmn1 + nmn2 > nmx ) res += f[id+1][nmn1][nmn2][nmx];
        if ( res >= cnt ){
            cout << c << ' ';
            findseq(id+1, nmn1, nmn2, nmx, cnt - res + f[id+1][nmn1][nmn2][nmx]);
            break;
        }
    }
}

ll getseq(int id, int mn1, int mn2, int mx){
    if ( id > n ) return 1;
    ll res = 0;
    for (int c = 1; c <= a[id]; c ++){
        int nmn1 = mn1, nmn2 = mn2, nmx = mx;
        if ( c > nmx ) nmx = c;
        if ( c < nmn1 ){
            nmn2 = nmn1; nmn1 = c;
        }
        else if ( c < nmn2 ) nmn2 = c;
        if ( c == a[id] ) res += getseq(id+1, nmn1, nmn2, nmx);
        else if ( nmn1 + nmn2 > nmx ) res += f[id+1][nmn1][nmn2][nmx];
    }
    return res;
}

int main(){
    cin >> n >> t;
    memset(f, -1, sizeof f);
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    cout << calc(1, n + 1, n + 1, 0) << '\n';
    findseq(1, n + 1, n + 1, 0, t); cout << '\n';
    cout << getseq(1, n + 1, n + 1, 0);

    return 0;
}
