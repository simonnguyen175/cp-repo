#include <bits/stdc++.h>
using namespace std;

int a,b,c,d,e,f;

int main(){
    cin >> a >> b >> c >> d >> e >> f;
    cout << max (a+d,max(b+e,c+f));
    return 0;
}
