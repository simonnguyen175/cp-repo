#include<bits/stdc++.h>
#define int long long
using namespace std;

int C, D, B, M;
map<int, set<int>> cont;

int get(int x){
    int res = 0;
    while ( x ){
        res += x % B;
        x /= B;
    }
    return res;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("baseB.inp", "r", stdin);
    freopen("baseB.out", "w", stdout);

    cin >> C >> D >> B >> M;

    int x = 1, tcs;
    while ( 1 ){
        tcs = get(x*C+D);
        cont[tcs].insert(x);
        if ( cont[tcs].size() == M ) break;
        x += B-1;
    }

    for (int it : cont[tcs]) cout << it << ' ';

    return 0;
}
