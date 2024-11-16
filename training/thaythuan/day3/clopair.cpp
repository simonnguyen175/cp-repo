#include<bits/stdc++.h>
using namespace std;
const int N = 5e4 + 5;
const int oo = 1e9;

int n;
struct point{
    int x, y, id;
} a[N];
float ans;
int it1, it2;

float dis(int i, int j){
    return sqrt(1LL*(a[i].x-a[j].x)*(a[i].x-a[j].x) + 1LL*(a[i].y-a[j].y)*(a[i].y-a[j].y));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].x >> a[i].y, a[i].id = i;
    sort(a+1, a+1+n, [](point b, point c){
        if ( b.x != c.x ) return b.x < c.x;
        else return b.y > c.y;
    });

    ans = oo;

    for (int i = 2; i <= n; i ++)
    for (int j = i-1; j >= 1; j --){
        if ( a[i].x - a[j].x > ans ) break;
        float tmp = dis(i, j);
        if ( tmp < ans ){
            ans = tmp;
            it1 = a[j].id, it2 = a[i].id;
        }
    }

    if ( it1 > it2 ) swap(it1, it2);
    cout << --it1 << ' ' << --it2 << ' ' << fixed << setprecision(6) << ans;

    return 0;
}
