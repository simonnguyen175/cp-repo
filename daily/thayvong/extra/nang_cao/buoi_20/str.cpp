#include <bits/stdc++.h>
#define simon "str"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define fi first
#define se second
#define ii pair<int, int>
#define cc pair<char, char>
using namespace std;
const int N=1e3+1;
const ll oo=1e15;

string s;
int n, f[N][N], g[N][N];

int main(){
    FASTio
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }
    cin >> n;
    cin >> s;
    s=' '+s;
    memset(f, 0, sizeof f);
    memset(g, 0, sizeof g);

    /// dp
    for (int i=n; i>=1; i--)
    for (int j=i+1; j<=n; j++){
        if ( s[i] == s[j] ){
            f[i][j]=2+g[i+1][j-1];
            g[i][j]=max(g[i+1][j], g[i][j-1]);
        }
        else{
            f[i][j]=max(f[i+1][j], f[i][j-1]);
            g[i][j]=2+f[i+1][j-1];
        }
    }

    /// truy vet
    int i=1, j=n, id=0 ;
    string d="", c="";
    while ( i < j ){
        if ( !id ){
            if ( s[i] == s[j] ){
                d+=s[i]; c+=s[j];
                i++; j--; id=(id+1)%2;
            }
            else{
                if ( f[i][j] == f[i+1][j] ) i++;
                else j--;
            }
        }
        else{
            if ( s[i] != s[j] ){
                d+=s[i]; c+=s[j];
                i++; j--; id=(id+1)%2;
            }
            else{
                if ( g[i][j] == g[i+1][j] ) i++;
                else j--;
            }
        }
    }
    reverse(c.begin(), c.end());
    cout << f[1][n] <<'\n';
    cout << d << c;
    return 0;
}

