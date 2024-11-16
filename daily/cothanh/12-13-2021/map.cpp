#include<bits/stdc++.h>
#define pi pair<int, int>
#define x first
#define y second
#define pb push_back
using namespace std;
const int N = 2e2 + 5;

int n, w, h;
pi a[N];
char cell[N][N];
vector<int> rows[N], cols[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> w >> h;
    int mxy;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].x >> a[i].y;
    a[n+1] = a[1];

    for (int i = 1; i <= n; i ++)
        if ( a[i].x == a[i+1].x ){
            int l = min(a[i].y, a[i+1].y) + 1;
            int r = max(a[i].y, a[i+1].y);
        }

    return 0;
}
