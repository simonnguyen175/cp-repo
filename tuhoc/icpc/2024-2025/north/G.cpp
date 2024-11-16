#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;

int n;
string s;
int f1[N], f0[N], rig[N];

int get(int x, int l) {
    int lo = x, hi = n, res = 0;
    while ( lo <= hi ){
        int mid = (lo + hi) / 2;
        if ( f0[mid] - f0[x-1] >= l ){
            res = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }

    if ( res ) return rig[res] - 1;
    else return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("tmp.inp", "r") ){
        freopen("tmp.inp", "r", stdin);
        freopen("tmp.out", "w", stdout);
    }

    cin >> n >> s;
    s = ' ' + s;

    for (int i = 1; i <= n; i ++){
        f0[i] = f0[i-1];
        f1[i] = f1[i-1];
        if ( s[i] == '1' ) f1[i] ++;
        else f0[i] ++;
    }

    int pos = n+1;
    for (int i = n; i >= 1; i --){
        rig[i] = pos;
        if ( s[i] == '1' )
            pos = i;
//        cout << rig[i] << ' ';
    }
//    cout << '\n';

    int ans = n - f0[n];
    for (int i = 1; i <= n; i ++){
        int l = 1, del = 0;

        while ( l <= n ){
            int r = get(l, i);
            if ( r == -1 ){
                del += f1[n] - f1[l-1];
                break;
            }
            del += f1[r] - f1[l-1];
            l = r + 2;
        }

        if ( s[l-1] == '1' ) del += 1;

        if ( f1[n] - del > 0 )
            ans = max(ans, (f1[n] - del + 1) * i + f1[n] - del);
    }

    cout << ans;

    return 0;
}
