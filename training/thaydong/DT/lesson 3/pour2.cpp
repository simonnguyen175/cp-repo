#include<bits/stdc++.h>
#define fi first
#define se second
#define BIT(x, k) ((x>>k)&1)
using namespace std;

pair<int, int> v[5];
vector<pair<int, int>> pours;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> v[1].fi >> v[2].fi >> v[3].fi;
    for (int i = 1; i <= 3; i ++) v[i].se = i;

    sort(v + 1, v + 4);

    while ( v[1].fi != 0 ){
        int d = v[2].fi / v[1].fi;
        int r = v[2].fi % v[1].fi;
        int id = 0;

        while ( d != 0 ){
            while ( !BIT(d, id) ){
                pours.push_back({v[3].se, v[1].se});
                v[3].fi -= v[1].fi; v[1].fi *= 2; id ++;
            }
            pours.push_back({v[2].se, v[1].se});
            v[1].fi *= 2;
            d -= (1<<id);
            id ++;
        }

        v[2].fi = r;
        sort(v + 1, v + 4);
    }

    cout << pours.size() << '\n';
    for (auto pour : pours)
        cout << pour.fi << ' ' << pour.se << '\n';

    return 0;
}
