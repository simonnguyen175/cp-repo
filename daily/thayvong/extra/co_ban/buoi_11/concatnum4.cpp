#include <bits/stdc++.h>
using namespace std;

string a[100];


int main(){
    for (int i=1; i<=3; i++)
        cin >> a[i];
    for (int i=1; i<=3; i++){
        for (int j=i+1; j<=3; j++)
            if ( a[i]+a[j] < a[j] + a[i]){
                swap(a[i],a[j]);
            }
    }
    for (int i=1; i<=3; i++) cout <<a[i];
}
