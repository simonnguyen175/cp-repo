#include<bits/stdc++.h>
using namespace std;
int main()
    {
        int dem = 0;
        int n;
        int a[10000];
        cin>>n;
        for(int i = 1; i <= n; i++)
            a[i] = i;
        do
        {
            dem++;
            for(int i = 1; i <= n; i++)
                cout<<a[i]<<' ';
                cout<<'\n';
                if(dem == 2021) break;
        }
        while(next_permutation(a + 1, a + 1 + n));
    }
