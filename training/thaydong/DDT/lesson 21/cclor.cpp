#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int MOD = 1e9 + 7;

int n;
ll b[10][40];
int t[10], f[41][41][41][41][41];

void xuli(int id){
    int cnt = 0;
    while ( b[id][cnt] ){
        cnt ++;
        if ( b[id][cnt] % 2 ) b[id][cnt] = ( b[id][cnt-1] - 1 ) / 2;
        else b[id][cnt] = b[id][cnt-1] / 2;
    }
    t[id] = cnt;

    for (int i = 0; i <= cnt/2; i ++) swap(b[id][i], b[id][cnt-i]);

//    cerr << id << " : \n";
//    for (int i = 0; i <= cnt; i ++) cerr << b[id][i] << ' ';
//    cerr << '\n';
}

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    return a;
}

int calc(int t0, int t1, int t2, int t3, int t4){
    if ( f[t0][t1][t2][t3][t4] != -1 ) return f[t0][t1][t2][t3][t4];
    t[0] = t0, t[1] = t1, t[2] = t2, t[3] = t3, t[4] = t4;

    int res = 0;
    for (int i = 0; i < n; i ++) if ( t[i] ){
        int j = ( i + 1 ) % n;
        if ( b[i][t[i]] % 2 == 0 ){
            t[i] --;
            res = add(res, calc(t[0], t[1], t[2], t[3], t[4]));
            t[i] ++;
        }
        else if ( b[j][t[j]] % 2 && j != i ){
            t[i] --, t[j] --;
            res = add(res, calc(t[0], t[1], t[2], t[3], t[4]));
            t[i] ++, t[j] ++;
        }
    }
    f[t0][t1][t2][t3][t4] = res;

    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i ++)
        cin >> b[i][0], xuli(i);

    memset(f, -1, sizeof f);

    f[0][0][0][0][0] = 1;
    cout << calc(t[0], t[1], t[2], t[3], t[4]);

    return 0;
}
