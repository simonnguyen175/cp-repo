#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

int n;
int a[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    int i = 1;
    while ( i <= n && a[i] < 0 ){
        i ++;
    }
//    for (int i = 1; i <= n; i ++)
//        cout << a[i] << ' ';
//    cout << '\n';
    int ans = a[i] + 1;
    a[n+1] = (int)2e9;
    while ( i <= n ){
        if ( a[i+1] > a[i] + 1 ){
            ans = a[i] + 1;
            break;
        }
        i ++;
    }
    cout << ans;
}
