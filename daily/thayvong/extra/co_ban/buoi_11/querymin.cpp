#include <bits/stdc++.h>
using namespace std;

int n,q;
int a[100001], b[100001], MIN[100001];

int main(){
    cin >> n >>q ;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int i=1; i<=q; i++){
        cin >> b[i];
    }
    MIN[0]= INT_MAX;
    for (int i=1; i<=n; i++){
        MIN[i]= min(MIN[i-1],a[i]);
    }
    for (int i=1; i<=q; i++){
        cout << MIN[b[i]]<<"\n";
    }
    return 0;
}
