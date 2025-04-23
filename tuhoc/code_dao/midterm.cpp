#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, m;
int a[N], t[N], d[N], thi[N];

bool check(int mid){
    for (int i = 1; i <= m; i ++)
        d[i] = 0; // reset mang d
    for (int i = 1; i <= n; i ++)
        thi[i] = 0; // reset mang thi

    for (int i = mid; i >= 1; i --){
        if ( d[a[i]] == 0 ){
            d[a[i]] = 1;
            thi[i] = 1; // ngay i thi mon a[i];
        }
    }

    int on = 0; // so luong ngay hien tai on duoc
    int mon = 0; // so luong mon thi duoc
    for (int i = 1; i <= mid; i ++){
        if ( thi[i] ){ // ngay i thi mon a[i];
            if ( on >= t[a[i]] ){
                on -= t[a[i]];
                mon ++;
            }
            else{
                break;
            }
        }
        else{
            on ++;
        }
    }

    if ( mon == m ) return true; // voi 1->mid ngay dau thi duoc het m mon
    else return false; // nguoc lai thi khong
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("midterm.inp", "r", stdin);
    freopen("midterm.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }

    for (int i = 1; i <= m; i ++){
        cin >> t[i];
    }

    int lo = 1, hi = n, ans = -1;
    while ( lo <= hi ){
        int mid = (lo + hi)/2;
        if ( check(mid) ){
            // kiem tra voi mid ngay dau tien
            // lieu co the vua hoc vua thi het
            // tat ca m mon khong
            // lo -- mid -- hi
            hi = mid - 1;
            ans = mid;
        }
        else{
            lo = mid + 1;
        }
    }

    cout << ans;

    return 0;
}
