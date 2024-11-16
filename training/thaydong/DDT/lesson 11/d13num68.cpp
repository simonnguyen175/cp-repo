#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll N;
int n[20];
ll f[20][2][2][2];

bool check68(ll a){
    while ( a > 0 ){
        if ( a%10 == 6 || a%10 == 8 ) return true;
        a /= 10;
    }
    return false;
}

ll solve(){
    int cnt = 0;
    ll tmp = N;
    while ( N > 0 ){
        n[++cnt] = N % 10;
        N /= 10;
    }

    memset(f, 0, sizeof f);
    f[0][0][0][0] = 1;

    for (int i = 1; i <= cnt; i ++)
    for (int nho = 0; nho <= 1; nho ++)
        for (int oka = 0; oka <= 1; oka ++)
        for (int okb = 0; okb <= 1; okb ++)
            for (int a = 0; a <= 9; a ++)
            for (int b = 0; b <= 9; b ++)
                if ( (a + b + nho) % 10 == n[i] ){
                    int nnho = (a + b + nho) / 10;
                    f[i][nnho][oka|(a==6)|(a==8)][okb|(b==6)|(b==8)] += f[i-1][nho][oka][okb];
                }

    ll res = f[cnt][0][1][1] + f[cnt][0][1][0] + f[cnt][0][0][1];

    res /= 2;
    if ( check68(tmp) ) res --;
    if ( tmp%2==0 && check68(tmp/2) ) res ++;

    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    while ( cin >> N )
        cout << solve() << '\n';

    return 0;
}
