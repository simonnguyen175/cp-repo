#include <bits/stdc++.h>
using namespace std;
long long i,a,b,s;
bool ktra(long long n)
	{
    	int s=0;
        for (long long i=1; i<=(int)sqrt(n);i++)
        {
            if (n%i==0)
            {
				s+=i;
            	if (i*i != n) s+=(n/i);
            }
        }
    	if (s>2*n) return true;
    	else return false;
    }
int main()
{
    cin>>a>>b;
    for (i=a; i<=b; i++)
        if (ktra(i)) s+=i;
    cout<<s;
}
