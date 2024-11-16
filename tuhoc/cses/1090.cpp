#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, x;
int a[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> x;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);

    int i = 1, j = n, ans = 0;
    while ( i < j ){
        while ( j > i + 1 && a[j] + a[i] > x ){
            j --;
            ans ++;
        }

        if ( a[i] + a[j] <= x ){
            ans ++;
            i ++; j --;
        }
        else{
            ans += 2;
            i ++, j --;
        }
    }

    if ( i == j ) ans ++;

    cout << ans;

    return 0;
}
