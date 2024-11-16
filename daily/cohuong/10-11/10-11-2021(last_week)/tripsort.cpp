#include<bits/stdc++.h>
#define simon "tripsort"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
using namespace std;
const int N = 1e5 + 5;

int t, n;
int a[N];

void sub1(){
    bool ck = 0;
    while ( !ck ){
        ck = 1;
        for (int i = 1; i <= n - 2; i ++)
            if ( a[i] > a[i+2] ){
                ck = 0;
                swap(a[i], a[i+2]);
            }
    }

    for (int i = 1; i <= n - 1; i ++)
        if ( a[i] > a[i+1] ) {cout << i << '\n'; return;}
    cout << "OK" << '\n';
}

void sub2(){
    vector<int> cont1, cont2, cont;
    for (int i = 1; i <= n; i += 2)
        if ( i <= n ) cont1.pb(a[i]);
    for (int i = 2; i <= n; i += 2)
        if ( i <= n ) cont2.pb(a[i]);

    sort(cont1.begin(), cont1.end());
    sort(cont2.begin(), cont2.end());

    for (int i = 0; i < cont2.size(); i ++)
        cont.pb(cont1[i]), cont.pb(cont2[i]);

    if ( n % 2 ) cont.pb(cont1[cont1.size()-1]);

    for (int i = 0; i < cont.size() - 1; i ++)
        if ( cont[i] > cont[i+1] ){
            cout << i + 1 << '\n';
            return;
        }

    cout << "OK" << '\n';
}

int main(){
    FASTio
    if ( fopen(simon".in", "r") ){
        freopen(simon".in", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> t;

    while ( t -- ){
        cin >> n;
        for (int i = 1; i <= n; i ++)
            cin >> a[i];
        if ( n <= 100 ) sub1();
        else
            sub2();
    }

    return 0;
}
