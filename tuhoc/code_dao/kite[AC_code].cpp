/*
voi moi nut id se luu lai thong tin doan con tu l -> r
cach cai dat segment tree len vnoi
ta can cap nhat lai nut sau moi lan tha dieu
st[i] la so dieu da duoc tha nam truoc l duoc luu thong tin boi nut i
tu tuong: neu nut luu thong tin tu l...r duoc cap nhat thi tim den nut con cua no phai di qua nut do -> cap nhat khi di qua nut nay
*/
#include <bits/stdc++.h>
using namespace std;
const string Fname = "KITE";
const int N = 1e6 + 5;
int n, a[N], b[N], st[20 * N] = {};
map<int, int> q;
void update(int id, int l, int r, int k){	// update lai nut tu
	if(r < k) return; // neu nho hon thi k can cap nhat
	if(l >= k){ // neu doan l...r nam sau k thi ta tang len
		st[id]++;
		return;
	}
	if(l == r) return;
	int mid = (l + r) / 2;
	update(2 * id, l, mid, k);
	update(2 * id + 1, mid + 1, r, k);
}
int get(int id, int l, int r, int k){	// lay thong tin cua 1 nut, vnoi
	if(l == r) return st[id];
	int mid = (l + r) / 2;
	if(k <= mid) return get(2 * id, l, mid, k) + st[id];
	else return get(2 * id + 1, mid + 1, r, k) + st[id];
}
void solve(){
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		b[i] = a[i];
	}
	sort(a + 1, a + n + 1, greater<int>());
	for(int i = 1; i <= n; ++i)
		q[a[i]] = i;
	for(int i = 1; i <= n; ++i){
		update(1, 1, n, q[b[i]]);
		cout << get(1, 1, n, q[b[i]]) << endl;
	}
}
int main(){
	if(fopen((Fname + ".inp").c_str(), "r")){
		freopen((Fname + ".inp").c_str(), "r", stdin);
		freopen((Fname + ".out").c_str(), "w", stdout);
	}
	solve();
}
