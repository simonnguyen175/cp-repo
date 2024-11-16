#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

long long n, k, a[N], d[505];

int main(){
    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    int ans = 0; // ket qua
    for (int i = 1; i <= n; i ++){

        if ( k >= a[i] * a[i] ){
            ans += d[k - a[i] * a[i]];
            // a[j] + a[i] * a[i] = k => a[j] = k - a[i] * a[i]
            // => dem nhung thang a[j] co gia tri la k - a[i] * a[i]
            // de dem ta dung mang danh dau d[x] danh giau nhung phan tu co gia tri la x
        }

        d[a[i]] ++;
        // + mang danh giau d[a[i]] de tang so luong phan tu co gia tri la a[i]
        // de phuc vu cho viec ghep cap a[i] voi nhung phan tu duoc duyet sau do
    }

    cout << ans;

    return 0;
}
