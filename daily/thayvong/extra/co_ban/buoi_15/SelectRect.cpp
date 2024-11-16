#include <bits/stdc++.h>
using namespace std;

struct hcn{
    int dai;
    int rong;
    int dt;
};

bool compair(hcn a, hcn b){
    if (a.dt < b.dt) return true;
    else return false;
}

int n, s, t;
hcn a[1001];

int main(){
    freopen("SelectRect.inp","r",stdin);
    freopen("SelectRect.out","w",stdout);
    cin >> n >> s >> t;
    for (int i=1; i<=n; i++)
        cin >> a[i].dai;
    for (int i=1; i<=n; i++)
        cin >> a[i].rong;
    for (int i=1; i<=n; i++)
        a[i].dt=a[i].dai*a[i].rong;
    sort (a+1,a+1+n,compair);
    int i=1;
    int ans=1;
    int b[1001];
    for (int k=2; k <=n; k++){
        // soạt diện tích
        while ( a[k].dt - a[i].dt > s )
            i++;
        // khởi tạo chiều dài
        int l=0;
        for (int j=i; j<=k; j++){
            l++;
            b[l]=a[j].dai;
        }
        sort (b+1,b+1+l);
        // soạt chiều dài
        int m=1;
        for (int j=1; j<=l; j++){
            while ( b[j] - b[m] > t )
                m++;
            ans = max (ans, j-m+1);
        }
    }
    cout << ans;
    return 0;
}
