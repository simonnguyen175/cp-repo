#include <bits/stdc++.h>
using namespace std;

string a, b;
int f[5001][5001], nextPos[1000001][27];

void solve(string a, string b){
    int m = a.size(), n = b.size();
    a=' '+a; b=' '+b;
    memset(nextPos, 0, sizeof nextPos);
    for (int c = 0; c < 26; ++c)
        for (int i = m-1; i >= 0; --i)
            if ( a[i+1] - 'A' == c ) nextPos[i][c]=i+1;
            else nextPos[i][c]=nextPos[i+1][c];
    int maxLength=min(m,n);
    memset(f, -1, sizeof f);
    f[0][0]=0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            if ( f[i-1][j-1] >= 0 ){
                f[i][j]=f[i-1][j];
                int k = nextPos[f[i-1][j-1]][b[i]-'A'];
                if ( k > 0 ) f[i][j]=k;
            }
    int ans=0;
    for (int j=maxLength; j>0; --j){
        for (int i=j; i<=n; ++i)
            if ( f[i][j] >= 0 ) ans=j;
        if ( ans !=0 ) break;
    }
    cout << ans <<'\n';
}

int main(){
    cin >> a >> b;
    solve(a,b);
    return 0;
}
