#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;

int n, m, k;
int mx[N];

int sqr(int x){ return x*x; }

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 1, x, y; i <= n; i ++){
        cin >> x >> y;
        mx[x] = max(mx[x], y);
        mx[y] = max(mx[y], x);
    }

    int st = 0, ed = 0, ans = 0;

    for (int i = 1; i <= m; i ++){
        if ( !mx[i] ) continue;
        if ( !st )
            ans = sqr(mx[i]-i+1), st = i, ed = mx[i], k --;
        else{
            if ( ed >= mx[i] ) continue;
            if ( k ){
                ans += sqr(mx[i]-i+1);
                if ( ed >= i ) ans -= sqr(ed-i+1);
                st = i;
                k --;
            }
            else
                ans += sqr(mx[i]-st+1) - sqr(ed-st+1);
            ed = mx[i];
        }
    }

    cout << ans;

    return 0;
}

