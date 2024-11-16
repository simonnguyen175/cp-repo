#include<bits/stdc++.h>
#define simon "las3"
#define ll long long
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 1e4 + 5;

int t, n;
ll a[N];

int lenghtOfLongestAP(ll set[], int n)
{
    if (n <= 2)  return n;

    int L[n][n];
    int llap = 2;

    for (int i = 0; i < n; i++)
        L[i][n-1] = 2;

    for (int j=n-2; j>=1; j--)
    {

        int i = j-1, k = j+1;
        while (i >= 0 && k <= n-1)
        {
           if (set[i] + set[k] < 2*set[j])
               k++;
           else if (set[i] + set[k] > 2*set[j])
           {   L[i][j] = 2, i--;   }

           else
           {
               L[i][j] = L[j][k] + 1;

               llap = max(llap, L[i][j]);

               i--; k++;
           }
        }
        while (i >= 0)
        {
            L[i][j] = 2;
            i--;
        }
    }
    return llap;
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
    cin >> t;
    while ( t -- ){
        cin >> n;
        for (int i = 0; i < n; i ++)
            cin >> a[i];
        cout << lenghtOfLongestAP(a, n) << '\n';
    }

    return 0;
}

