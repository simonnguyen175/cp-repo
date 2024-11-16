#include <bits/stdc++.h>
using namespace  std;
long long n,s=0,p=0;
int main()
{
    cin >> n;
    long long dem;
    for (int i=2; i<= sqrt(n); i++)
    {
            dem=0;
            if (n % i==0 )
                while (n % i==0)
                {
                    n /=i ;
                    dem++;
                }
            if (dem % 2 ==0) s+=dem;
            else p+=dem;
    }
    if (n !=1 ) p++;
    cout << s  << "\n" << p;
}
