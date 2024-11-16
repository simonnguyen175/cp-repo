#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    string s;
    int n;

    while ( true ){
        cin >> s;
        if ( s == "[END]" ) break;

        cin >> n;

        double c55n = 1.0;
        for (int i = 0; i < 5; i++) {
            c55n *= (5 * n - i) / (i + 1.0) * 1.0;
            cout << i << ' ' << i + 1.0 << '\n';
        }
        double c35 = n * 5 * (5 * n - 5) * (5 * n - 6) * 1.0;
        double c45 = n * 5 * (5 * n - 5) * 1.0;
        double c55 = n * 1.0;

        cout << fixed << setprecision(9) << ( c35 + c45 + c55 )/c55n << '\n';
    }

    return 0;
}
