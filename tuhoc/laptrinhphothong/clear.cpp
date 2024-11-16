#include <bits/stdc++.h>
using namespace std;
int t,i,j,n[100],m[100],a[10]={0,1,0,0,0,0,0,1,0,0};
int somoi (int n)
{
    int s=0,x;
    while (n>0)
    {
        x=n%10;
        s+=(x*x);
        n/=10;
    }
    return s;
}
bool kt(int n)
{
	while (n>9) n=somoi(n);
	return a[n];
}
int main()
{
	freopen("clear.inp","r",stdin);
	freopen("clear.out","w",stdout);
	ios::sync_with_stdio(0);
		cin.tie(0);
	cin >> t;
	int dem=0;
	for (i=1; i<=t; i++)
		cin >> n[i]>> m[i];
	for (i=1; i<=t; i++)
		{
			dem=0;
			j=n[i];
			while (dem <m[i])
				{
					j++;
					if (kt(j)) dem++;
				}
			cout << j <<"\n";
		} 
	return 0;
}

