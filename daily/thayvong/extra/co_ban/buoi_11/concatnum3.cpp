#include <bits/stdc++.h>
using namespace std;

string a[100];
int n;

int main(){
    cin >> n ;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int i=1; i<=n; i++){
        for (int j=i+1; j<=n; j++)
            if (a[i]+a[j] < a[j] + a[i]){
                swap(a[i],a[j]);
            }
    }
    for (int i=1; i<=n; i++) cout <<a[i];
}
