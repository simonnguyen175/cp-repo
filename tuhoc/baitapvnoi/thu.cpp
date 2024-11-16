#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[] = {0, 4, 2, 1, 5, 3, 7, 6};
    sort(a + 2, a + 1 + 3);
    for (int i = 0; i < 8; i ++)
        cout << a[i] << ' ';
    return 0;
}

