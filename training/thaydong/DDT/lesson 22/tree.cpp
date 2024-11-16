#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    multiset<pi> cont;
    for (int i = 1, x; i <= n; i ++)
        cin >> x, cont.insert({x, i});

    while ( cont.size() ){
        pi mn = *cont.cbegin();
        pi mx = *cont.rbegin();
        cont.erase(cont.find(mn));
        cont.erase(cont.find(mx));

        cout << mx.se << ' ' << mn.se << '\n';
        mn.fi --, mx.fi --;

        if ( mn.fi ) cont.insert(mn);
        if ( mx.fi ) cont.insert(mx);
    }

    return 0;
}
