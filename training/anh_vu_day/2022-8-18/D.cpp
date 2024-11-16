#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 3e5 + 5;

int n;
ll bit[N];
vector<int> r[N];
int c[N], d[N];

void update(int u, ll v){
    for (; u >= 1; u -= u&-u)
        bit[u] = max(bit[u], v);
}

ll get(int u){
    ll res = 0;
    for (; u <= N-5; u += u&-u)
        res = max(res, bit[u]);
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> c[i];
    for (int i = 1; i <= n; i ++)
        cin >> d[i];

    for (int i = n; i >= 1; i --){
        if ( c[i] == 1 ) continue;
        if ( i >= c[i] )
            r[i-c[i]+1].pb(i);
    }

    for (int i = 1; i <= n; i ++){
        for (int j : r[i])
            update(j-1, get(j)+d[j]);
        if ( c[i] == 1 )
            cout << d[i] + get(i) << ' ';
        else{
            cout << get(i) << ' ';
            if ( i + c[i] - 1 <= n )
                update(i+c[i]-1, get(i+c[i]-1)+d[i]);
        }
    }

    return 0;
}
