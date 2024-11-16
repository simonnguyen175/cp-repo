#include<bits/stdc++.h>
using namespace std;
const int N = 5e2 + 5;
const int oo = 1e9;
const int row[] = {0, 0, 1, -1};
const int col[] = {1, -1, 0, 0};

int m, n;
struct ct2{
    int c2, c5;
    bool operator < (const ct2 &a) const{
        return c2 < a.c2;
    }
    bool operator > (const ct2 &a) const{
        return c2 > a.c2;
    }
    ct2 operator + (const ct2 &a) const{
        return {c2+a.c2, c5+a.c5};
    }
} a[N][N], d[N][N];

struct node{
    ct2 du;
    int xu, yu;
    bool operator > (const node &a) const{
        return du > a.du;
    }
};


struct ct5{
    int c2, c5;
    bool operator < (const ct5 &a) const{
        return c5 < a.c5;
    }
    bool operator > (const ct5 &a) const{
        return c5 > a.c5;
    }
    ct5 operator + (const ct5 &a) const{
        return {c2+a.c2, c5+a.c5};
    }
} b[N][N], d1[N][N];

struct node1{
    ct5 du;
    int xu, yu;
    bool operator > (const node1 &a) const{
        return du > a.du;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("SC.inp", "r") ){
        freopen("SC.inp", "r", stdin);
        freopen("SC.out", "w", stdout);
    }

    cin >> m >> n;
    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++){
        int x; cin >> x;
        int c2 = 0, c5 = 0;
        while ( x % 2 == 0 ) x /= 2, c2 ++;
        while ( x % 5 == 0 ) x /= 5, c5 ++;
        a[i][j] = {c2, c5};
        b[i][j] = {c2, c5};
    }

    priority_queue<node, vector<node>, greater<node>> heap;

    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++)
        d[i][j] = {oo, oo};

    d[1][1] = a[1][1]; heap.push({d[1][1], 1, 1});

    while ( heap.size() ){
        ct2 du = heap.top().du;
        int xu = heap.top().xu, yu = heap.top().yu;
        heap.pop();

        if ( du > d[xu][yu] ) continue;

        for (int i = 0; i < 4; i ++){
            int xv = xu + row[i], yv = yu + col[i];
            if ( xv < 1 || xv > m || yv < 1 || yv > n ) continue;
            if ( d[xv][yv] > du + a[xv][yv] ){
                d[xv][yv] = du + a[xv][yv];
                heap.push({d[xv][yv], xv, yv});
            }
        }
    }

    priority_queue<node1, vector<node1>, greater<node1>> heap1;

    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++)
        d1[i][j] = {oo, oo};

    d1[1][1] = b[1][1]; heap1.push({d1[1][1], 1, 1});

    while ( heap1.size() ){
        ct5 du = heap1.top().du;
        int xu = heap1.top().xu, yu = heap1.top().yu;
        heap1.pop();

        if ( du > d1[xu][yu] ) continue;

        for (int i = 0; i < 4; i ++){
            int xv = xu + row[i], yv = yu + col[i];
            if ( xv < 1 || xv > m || yv < 1 || yv > n ) continue;
            if ( d1[xv][yv] > du + b[xv][yv] ){
                d1[xv][yv] = du + b[xv][yv];
                heap1.push({d1[xv][yv], xv, yv});
            }
        }
    }

    cout << min(min(d[m][n].c2, d[m][n].c5), min(d1[m][n].c2, d1[m][n].c5));

    return 0;
}
