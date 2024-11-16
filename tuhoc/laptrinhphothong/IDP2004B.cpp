#include <bits/stdc++.h>
using namespace std;

int n,q;
string s;
int f[100001][260];
int l[100001], r[100001];
char c[100001];

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> n >> q;
    cin >> s;
    s=' '+s;
    for (int i=1; i<=q; i++)
        cin >> l[i] >> r[i] >> c[i];
    for (int i=1; i<=260; i++)
        f[0][i]=0;
    for (int j='a'; j<='z'; j++)
        for (int i=1; i<=n; i++){
            if ( j == s[i])
                f[i][j]=f[i-1][j]+1;
            else f[i][j]=f[i-1][j];
        }
    for (int i=1; i<=q; i++){
        cout << f[r[i]][c[i]] - f[l[i]-1][c[i]] <<"\n";
    }
    return 0;
}
