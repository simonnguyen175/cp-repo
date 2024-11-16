#include<bits/stdc++.h>
#define pi pair<int, int>
using namespace std;

int n, m;
map<pi, int> g;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i ++){
        cin >> u >> v;
        g[{u, v}] = g[{v, u}] = 1;
    }

    /// dq0 day co canh noi, dq1 day ko co canh noi
    deque<int> dq1, dq2;
    int cur = 0;
    dq1.push_back(1);
    for (int i = 2; i <= n; i ++)
        if ( !cur ){
            if ( g[{dq1.back(), i}] ){
                dq1.push_back(i);
                if ( dq2.size() && g[{i, dq2.back()}] ){
                    dq1.push_back(dq2.back());
                    dq2.pop_back();
                }
            }
            else{
                if ( !dq2.size() ) { dq2.push_back(i); continue; }
                if ( !g[{i, dq2.back()}] ) dq2.push_back(i);
                else{
                    dq2.push_back(dq1.back());
                    dq1.pop_back();
                    if ( !dq1.size() ) { dq1.push_back(i); cur ^= 1; }
                    else if ( g[{i, dq1.back()}] ) dq1.push_back(i);
                    else dq2.push_back(i);
                }
            }
        }
        else{
            if ( g[{dq1.front(), i}] ){
                dq1.push_front(i);
                if ( dq2.size() && g[{i, dq2.front()}] ){
                    dq1.push_front(dq2.front());
                    dq2.pop_front();
                    if ( !dq2.size() ) cur ^= 1;
                }
            }
            else{
                if ( !dq2.size() ) { dq2.push_front(i); continue; }
                if ( !g[{i, dq2.front()}] ) dq2.push_front(i);
                else{
                    dq2.push_front(dq1.front());
                    dq1.pop_front();
                    if ( !dq1.size() ) dq1.push_front(i);
                    else if ( g[{i, dq1.front()}] ) dq1.push_front(i);
                    else dq2.push_front(i);
                }
            }
        }

    if ( !cur ){
        while ( dq1.size() ) { cout << dq1.front() << ' '; dq1.pop_front(); }
        while ( dq2.size() ) { cout << dq2.back() << ' '; dq2.pop_back(); }
    }
    else{
        while ( dq2.size() ) { cout << dq2.back() << ' '; dq2.pop_back(); }
        while ( dq1.size() ) { cout << dq1.front() << ' '; dq1.pop_front(); }
    }

    return 0;
}
