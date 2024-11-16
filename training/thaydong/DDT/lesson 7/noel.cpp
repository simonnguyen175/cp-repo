#include<bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;

int n, d, na, nb, ans = 0;
int c[N], a[N], b[11*N], f[N][N];
int dp[11*N], p[11*N];

int Get(){
    for (int i = 1; i <= na; i ++)
        for (int j = 1; j <= nb; j ++)
            f[i][j] = 0;
    for (int i = 1; i <= na; i ++)
        for (int j = 1; j <= nb; j ++){
            f[i][j] = max(f[i-1][j], f[i][j-1]);
            if ( abs(a[i] - b[j]) <= d )
                f[i][j] = max(f[i][j], f[i-1][j-1] + 1);
        }
    return f[na][nb];
}

int tknp(int p[], int l, int r, int x){
    int d = l, c = r, mid, res = 0;
    while ( d <= c ){
        mid = (d+c)/2;
        if ( p[mid] < x ){
            res = mid;
            d = mid + 1;
        }
        else
            c = mid - 1;
    }
    return res;
}

void sub2(){

    for (int i = 1; i <= 2*n; i ++)
        a[c[i]] = i;

    for (int k = 1; k < 2*n; k ++){
        nb = 0;
        for (int i = k+1; i <= 2*n; i ++){
            vector<int> tmp;
            for (int j = -d; j <= d; j ++)
                if ( c[i] + j > 0 && c[i] + j <= 2*n && a[c[i]+j] < k )
                    tmp.push_back(a[c[i]+j]);
            sort(tmp.begin(), tmp.end(), greater<int>());
            for (auto it : tmp) b[++nb] = it;
        }

        for (int i = 1; i <= nb; i ++)
            p[i] = 0, dp[i] = 0;
        int m = 0;
        for (int i=1; i<=nb; i++){
            int temp = tknp(p, 1, m, b[i]);
            dp[i]= temp + 1;
            m = max(m, dp[i]);
            p[dp[i]] = b[i];
        }
        ans = max(ans, m);
    }

    cout << ans;
}

int main(){
    cin >> n >> d;
    for (int i = 1; i <= 2*n; i ++)
        cin >> c[i];

    if ( n <= 100 ){
        for (int i = 1; i <= 2*n-1; i ++){
            na = 0; nb = 0;
            for (int j = 1; j <= i; j ++) a[++na] = c[j];
            for (int j = i + 1; j <= 2*n; j ++) b[++nb] = c[j];
            ans = max(ans, Get());
        }

        cout << ans;
    }
    else sub2();

    return 0;
}
