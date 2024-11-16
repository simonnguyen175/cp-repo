#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, x;
int a[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> x;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    int j = 1, ans = 0;
    for (int i = n; i >= 1; i --){
        while ( a[j] + a[i] <= x && j < i ){
            ans = max(ans, a[i] + a[j]);
            j ++;
        }
    }
    cout << ans;

    return 0;
}
