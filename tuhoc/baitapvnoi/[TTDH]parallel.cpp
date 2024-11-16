#include<bits/stdc++.h>
using namespace std;

int n;

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        int loop, branch;
        cin >> loop >> branch;
        if ( (loop <= 1 && branch <= 2) || (loop <= 2 && branch <= 1) )
            cout << "Yes" <<'\n';
        else cout << "No" <<'\n';
    }
    return 0;
}
