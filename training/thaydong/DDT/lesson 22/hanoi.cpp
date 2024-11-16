#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;

int n;
int pos[25];
char c[4];
vector<pi> ans;

void chuyen(int n, int f){
    if ( n == 1 ){
        ans.pb({c[pos[1]], c[f]});
        return;
    }

    if ( pos[n] == f ) chuyen(n-1, f);
    else{
        int g = 6 - f - pos[n];
        chuyen(n-1, g);
        for (int i = 1; i < n; i ++) pos[i] = g;
        ans.pb({c[pos[n]], c[f]});
        chuyen(n-1, f);
        for (int i = 1; i < n; i ++) pos[i] = f;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++){
        char x; cin >> x;
        if ( x == 'A' ) pos[i] = 1;
        if ( x == 'B' ) pos[i] = 2;
        if ( x == 'C' ) pos[i] = 3;
    }
    c[1] = 'A', c[2] = 'B', c[3] = 'C';

    chuyen(n, 3);

    cout << ans.size() << '\n';
    for (auto it : ans) cout << (char)it.fi << (char)it.se << '\n';

    return 0;
}
