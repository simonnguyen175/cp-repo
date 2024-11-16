#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    cin >> n;
    double s=0;
    for (int i=1; i<=n; i++)
        s += (double)(2*i-1)/(2*i);
    cout << setprecision(6) << fixed << s;
    return 0;
}
