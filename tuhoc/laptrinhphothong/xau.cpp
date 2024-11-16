#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int base = 31;
const ll MOD = 1000000003;
const ll maxn = 1000111;

string T;
int n;
long long a[1000000];
ll POW[maxn], hashT[maxn];

ll getHashT(int i,int j)
{
    return (hashT[j] - hashT[i - 1] * POW[j - i + 1] + MOD * MOD) % MOD;
}

ll  check(int k)
{
    for (int i=1; i <= n; i++)
        a[i] = getHashT(i,i+k-1);

    sort (a+1,a+1+n);

    for (int i=2; i <= n; i++)
        if ( a[i] == a[i-1] ) return true;
    return false;
}
int main()
{
    freopen("xau.inp","r",stdin);
    freopen("xau.out","w",stdout);

    //Input
    cin >> n;
    cin >> T;

    //Initialize
    T = " " + T;
    POW[0] = 1;
    for (int i = 1; i <= n; i++)
    	POW[i] = (POW[i - 1] * base) % MOD;
    for (int i = 1; i <= n; i++)
    	hashT[i] = (hashT[i - 1] * base + T[i] - 'a' + 1) % MOD;

    //Solve
    int l = 1, r = n-1, mid ;
    int res=0;

    while (l <= r)
    {
        mid = (l+r)/2;
        if ( check(mid) ) {
                l = mid + 1;
                res = mid;
        }
        else r = mid -1;
    }
    cout << res;

    return 0;
}
