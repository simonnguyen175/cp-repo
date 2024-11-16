#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

int n;
int a[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    int c = 1, ans = 1, id = 1;
    for (int i = 2; i <= n; i ++){
        if ( a[i] > a[i-1] ){
            c ++; // do dai day tang lien tiep dai nhat den i theo chieu tu 1->n
        }
        else{
            if ( ans < c ){
                ans = max(ans, c);
                id = i - 1;
            }
            c = 1; // reset lai do dai = 1
        }
    }

    if ( ans < c ){
        ans = max(ans, c);
        id = n;
    }

    cout << ans << '\n';
    for (int i = id - ans + 1; i <= id; i ++)
        cout << a[i] << ' ';

    return 0;
}
