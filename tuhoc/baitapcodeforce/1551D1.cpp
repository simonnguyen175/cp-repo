#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m, kh;
		cin >> n >> m >> kh;
		int kv = n * m / 2 - kh;
		if (n & 1)
		{
			kh -= m / 2;
			if (kh < 0)
			{
				cout << "NO\n";
				continue;
			}
		}
		else if (m & 1)
		{
			kv -= n / 2;
			if (kv < 0)
			{
				cout << "NO\n";
				continue;
			}
		}

		if ((kh & 1) || (kv & 1))
		{
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
	}
	return 0;
}
