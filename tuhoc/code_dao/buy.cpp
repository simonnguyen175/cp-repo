#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

struct com{
    int a, b, id;
};

int m, n;
com c[N];

bool compare(com x, com y){
    return (x.b < y.b);
}

int main(){
    cin >> m >> n;
    for (int i = 1; i <= n; i ++){
        cin >> c[i].a >> c[i].b;
        c[i].id = i;
    }
    sort(c + 1, c + 1 + n, compare);
    cout << '\n';
    for (int i = 1; i <= n; i ++){
        cout << c[i].a << ' ' << c[i].b << ' ' << c[i].id << '\n';
    }

    return 0;
}
