#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 2e3 + 5;

int n;
int a[N], t[N], bit[N];
int ans = 0;

void update(int u, int v){
    for (; u >= 1; u -= u&(-u)) bit[u] = max(bit[u], v);
}

int get(int u){
    int res = 0;
    for (; u <= n; u += u&(-u)) res = max(res, bit[u]);
    return res;
}

bool check(vector<int> &b){
    if ( b.size() <= 1 ) return false;


    for (int i = 1; i <= n; i ++) bit[i] = 0;

    update(b[0], 1);

    int res = 0;
    for (int i = 1; i < b.size(); i ++){
        int tmp = get(b[i]) + 1;
        update(b[i], tmp);
        res = max(res, tmp);
    }



    return res <= 2;
}

void gen(int id){
    for (int i = 0; i <= 1; i ++){
        t[id] = i;
        if ( id == n ){
            vector<int> b;
            for (int j = 1; j <= n; j ++)
                if ( t[j] ) b.pb(a[j]);
            ans += check(b);
        }
        else gen(id + 1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("2.inp", "r") ){
        freopen("2.inp", "r", stdin);
        freopen("2.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];

    if ( n <= 20 ){
        gen(1);
        cout << ans;
    }

    return 0;
}

