#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;

int n, ans = 0;
int a[25];
map<int, int> cnt[25];

int reduce(int x){
    while ( x >= 10 ){
        int tmp = x, nx = 1;
        while ( tmp ){
            nx *= tmp % 10;
            tmp /= 10;
        }
        x = nx;
    }
    return x;
}

void calc(int id, int ok, int ok1, int pre){
    if ( ok && ok1 ){
        for (auto it : cnt[id]){
            ans += reduce(pre*it.fi) * it.se;
        }
    }
    else{
        if ( id == 0 ){
            if ( ok1 ){
                ans += reduce(pre);
            }
        }
        else{
            for (int c = 0; c <= max(ok*9, a[id]); c ++){
                if ( !ok1 ){
                    if ( c == 0 ){
                        calc(id-1, ok|(c<a[id]), 0, pre);
                    }
                    else{
                        calc(id-1, ok|(c<a[id]), 1, pre*c);
                    }
                }
                else{
                    calc(id-1, ok|(c<a[id]), 1, pre*c);
                }
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cnt[0][1] = 1;
    for (int i = 1; i <= 19; i ++)
    for (auto it : cnt[i-1])
    for (int c = 0; c <= 9; c ++)
        cnt[i][it.fi*c] += it.se;

    cin >> n;
    for (int i = 1; i <= 19; i ++)
        a[i] = n % 10, n /= 10;

    calc(19, 0, 0, 1);

    cout << ans << '\n';

    return 0;
}
