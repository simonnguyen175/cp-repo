#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int m, n, k;
int h[305][305];
pair<int, int> a[305], horAcr[305], verAcr[305];


int maxLen(int n){
    int l = 1, res = 0;
    deque<int> dq_max, dq_min;
    for (int i = 1; i <= n; i ++){
        while ( !dq_max.empty() && a[dq_max.back()].fi < a[i].fi )
            dq_max.pop_back();
        while ( !dq_min.empty() && a[dq_min.back()].se > a[i].se )
            dq_min.pop_back();
        dq_max.push_back(i);
        dq_min.push_back(i);
        while ( l <= i && a[dq_max.front()].fi - a[dq_min.front()].se > k ){
            if ( dq_max.front() == l ) dq_max.pop_front();
            if ( dq_min.front() == l ) dq_min.pop_front();
            l ++;
        }
        res = max(res, i - l + 1);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> m >> n >> k;
    for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j ++)
            cin >> h[i][j];

    // ke ngang
    for (int i = 1; i <= m; i ++){
        for (int j = 1; j <= n; j ++)
            a[j].fi = INT_MIN, a[j].se = INT_MAX;
        horAcr[i].fi = horAcr[i-1].fi;
        for (int j = i; j >= 1; j --){
            for (int k = 1; k <= n; k ++){
                a[k].fi = max(a[k].fi, h[j][k]);
                a[k].se = min(a[k].se, h[j][k]);
            }
            horAcr[i].fi = max(horAcr[i].fi, maxLen(n) * (i-j+1));
        }
    }
    for (int i = m; i >= 1; i --){
        for (int j = 1; j <= n; j ++)
            a[j].fi = INT_MIN, a[j].se = INT_MAX;
        horAcr[i].se = horAcr[i+1].se;
        for (int j = i; j <= m; j ++){
            for (int k = 1; k <= n; k ++){
                a[k].fi = max(a[k].fi, h[j][k]);
                a[k].se = min(a[k].se, h[j][k]);
            }
            horAcr[i].se = max(horAcr[i].se, maxLen(n) * (j-i+1));
        }
    }

    // ke doc
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++)
            a[j].fi = INT_MIN, a[j].se = INT_MAX;
        verAcr[i].fi = verAcr[i-1].fi;
        for (int j = i; j >= 1; j --){
            for (int k = 1; k <= m; k ++){
                a[k].fi = max(a[k].fi, h[k][j]);
                a[k].se = min(a[k].se, h[k][j]);
            }
            verAcr[i].fi = max(verAcr[i].fi, maxLen(m) * (i-j+1));
        }
    }
    for (int i = n; i >= 1; i --){
        for (int j = 1; j <= m; j ++)
            a[j].fi = INT_MIN, a[j].se = INT_MAX;
        verAcr[i].se = verAcr[i+1].se;
        for (int j = i; j <= n; j ++){
            for (int k = 1; k <= m; k ++){
                a[k].fi = max(a[k].fi, h[k][j]);
                a[k].se = min(a[k].se, h[k][j]);
            }
            verAcr[i].se = max(verAcr[i].se, maxLen(m) * (j-i+1));
        }
    }

    int ans = 0;
    for (int i = 1; i < m; i ++)
        ans = max(ans, horAcr[i].fi + horAcr[i+1].se);
    for (int i = 1; i < n; i ++)
        ans = max(ans, verAcr[i].fi + verAcr[i+1].se);

    cout << ans;

    return 0;
}
