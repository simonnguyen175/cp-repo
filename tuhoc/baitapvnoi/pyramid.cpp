#include<bits/stdc++.h>
using namespace std;

struct opt{
    int x, y, val;
};

int m, n, a, b, c, d;
int h[1005][1005], sh[1005][1005];
int acr[1005], col[1005];
opt f[1005][1005];

int getsum(int li, int lj, int ri, int rj){
    return sh[ri][rj] - sh[li-1][rj] - sh[ri][lj-1] + sh[li-1][lj-1];
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> n >> m >> a >> b >> c >> d;
    for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j ++)
            cin >> h[i][j];

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j ++)
            sh[i][j] = h[i][j] + sh[i-1][j] + sh[i][j-1] - sh[i-1][j-1];

    for (int i = 2; i <= n - 1; i ++){
        int k = b - d - 1;
        for (int j = 2; j <= m - d; j ++)
            acr[j] = getsum(j, i, j + d - 1, i + c - 1);
        deque<int> dq;
        for (int j = 2; j <= m - d; j ++){
            while ( dq.size() && acr[dq.back()] > acr[j] ) dq.pop_back();
            dq.push_back(j);
            while ( dq.size() && dq.front() + k <= j ) dq.pop_front();
            if ( j - 1 >= k  ){
                f[j+d-1][i].val = acr[dq.front()];
                f[j+d-1][i].x = dq.front();
                f[j+d-1][i].y = i;
            }
        }
    }

    /*
    for (int i = 1; i <= m; i ++){
        for (int j = 1; j <= n; j ++)
            cout << f[i][j].val << ' ';
        cout << '\n';
    }
    */



    int ans = 0;
    pair<int, int> tower, monu;
    for (int i = 1; i <= m - b + 1; i ++){
        int k = a - c - 1, hc = i + b - 2;
        deque<int> dq;
        //cout << k << ' ' << hc << '\n';
        //for (int j = 2; j <= n - c; j ++)
            //cout << f[hc][j].val << ' '; cout << '\n';
        for (int j = 2; j <= n - c; j ++){
            while ( dq.size() && f[hc][dq.back()].val > f[hc][j].val ) dq.pop_back();
            dq.push_back(j);
            while ( dq.size() && dq.front() + k <= j ) dq.pop_front();
            if ( j - 1 >= k ){
                //cout << dq.front() << ' ' << i << ' ' << j - k << ' ' << i + b - 1 << ' ' << j + c << '\n';
                int res = getsum(i, j - k, i + b - 1, j + c) - f[hc][dq.front()].val;
                //cout << res << '\n';
                if ( res > ans ){
                    ans = res;
                    tower.first = i; tower.second = j - k;
                    monu.first = f[hc][dq.front()].x; monu.second = f[hc][dq.front()].y;
                }
            }
        }
    }

    cout << tower.second << ' ' << tower.first << '\n';
    cout << monu.second << ' ' << monu.first;

    return 0;
}

