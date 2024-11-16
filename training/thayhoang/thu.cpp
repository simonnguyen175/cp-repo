#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    int a[10];
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    sort(a + 2, a + 6 + 1);

    for (int i = 1; i <= n; i ++)
        cout << a[i] << ' ';

    return 0;
}
