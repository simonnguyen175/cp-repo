#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define DOW(i,a,b) for(int i = (a); i >= (b); i--)
#define RESET(c,val) memset(c,val,sizeof(c))
#define sz(a) int(a.size())
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;

/*---------------------------*/

const int maxn = 1e3 + 2;
int m, n, res, tt;
ll a[maxn][maxn];
bool b[maxn][maxn];

void input() {
    scanf("%d %d", &m, &n);
    RESET(a,0);
    FOR(i,1,m)
    FOR(j,1,n)
    scanf("%lld", &a[i][j]);
}

void solve() {
    FOR(i,1,m-1)
    FOR(j,1,n-1)
    b[i][j]=((a[i][j]<=a[i+1][j]) && (a[i][j]<=a[i][j+1])
             && (a[i+1][j]<=a[i+1][j+1]) && (a[i][j+1]<=a[i+1][j+1]));

    FOR(i, 1, m){
        FOR(j, 1, n)
            cout << b[i][j] << ' ';
        cout << '\n';
    }
    res=1;
    // search row
    FOR(i,1,m) {
        tt=1;
        FOR(j,2,n)
        if ( a[i][j]>=a[i][j-1] ) {
            tt++;
            res=max(res,tt);
        } else tt=1;
    }

    // search col
    FOR(j,1,n) {
        tt=1;
        FOR(i,2,m)
        if ( a[i][j]>=a[i-1][j] ) {
            tt++;
            res=max(res,tt);
        } else tt=1;
    }

    int h[maxn], l[maxn], r[maxn];
    RESET(h,0);
    RESET(l,0);
    RESET(r,0);
    FOR(i,1,m-1) {
        FOR(j,1,n-1)
        if ( b[i][j] ) h[j]++;
        else h[j]=0;

        //deque
        int d[maxn];
        int top=0;
        d[0]=0;
        FOR(j,1,n-1) {
            while(top && h[j]<=h[d[top]])
                r[d[top--]]=j-1;
            l[j]=d[top]+1;
            d[++top]=j;
        }
        while(top) r[d[top--]]=n-1;

        FOR(j,1,n-1)
        if ( h[j]>0 ) {
            res=max(res,(h[j]+1)*(r[j]-l[j]+2));
        }
    }
}

void output() {
    printf("%d", res);
}

int main() {
    input();
    solve();
    output();

    return 0;
}
