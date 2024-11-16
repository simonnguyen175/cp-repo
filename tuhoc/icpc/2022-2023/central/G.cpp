#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5;

string s;
int k, n;
ll add[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> s >> k;
    n = s.size();
    s = ' ' + s;

    for (int i = 1; i <= k; i ++){
        int v, x, y;
        cin >> v >> x >> y;
        add[x] += v, add[y+1] -= v;
    }

    for (int i = 1; i <= n; i ++)
        add[i] += add[i-1];

    for (int i = 1; i <= n; i ++){
        add[i] %= 26;
        int t = ( s[i] + add[i] );
        if ( t > (int) 'Z' ) t -= 26;
        cout << (char) t;
    }

    return 0;
}
