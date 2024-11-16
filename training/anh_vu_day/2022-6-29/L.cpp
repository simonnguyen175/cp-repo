#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
const int base = 31;

int n;
string s, t;
ll hashU[N], hashD[N], pw[N];

int getU(int l, int r){
    return ( hashU[r] - hashU[l] * pw[r-l+1] + 1LL*MOD*MOD ) % MOD;
}

int getD(int l, int r){
    return ( hashD[r] - hashD[l] * pw[r-l+1] + 1LL*MOD*MOD ) % MOD;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    cin >> s;
    t = s, reverse(t.begin(), t.end());
    s = ' ' + s, t = ' ' + t;

    pw[0] = 1;
    for (int i = 1; i <= n; i ++) pw[i] = pw[i-1] * base % MOD;

    for (int i = 1; i <= n; i ++)
        hashU[i] = ( hashU[i-1] * base + s[i] - 'a' + 1 ) % MOD;

    for (int i = 1; i <= n/2; i ++){
        int lo = 1, hi = n-2*i+1, res = -1;
        while ( lo <= hi ){
            int mid = lo + hi >> 1;
            if ( getU(i, i+mid-1) == getD(i, i+mid-1))
                res = mid, lo = mid + 1;
            else hi = mid - 1;
        }
        cout << res << '\n';
    }

    return 0;
}
