#include<bits/stdc++.h>
using namespace std;

struct data {
	int id, point1, point2, point3;
	data() {
		id = 0;
		point1 = -1;
		point2 = -1;
		point3 = -1;
	}

	bool operator < (const data &a) const {
		if (point1 != a.point1) return point1 < a.point1;
		if (point2 != a.point2) return point2 < a.point2;
		return point3 < a.point3; 
	}

	bool operator <= (const data &a) const {
		if (point1 != a.point1) return point1 < a.point1;
		if (point2 != a.point2) return point2 < a.point2;
		return point3 <= a.point3; 
	}

	void reArrange() {
		if (point1 < point2) swap(point1, point2); 
		if (point1 < point3) swap(point1, point3);
		if (point2 < point3) swap(point2, point3);

		if (point2 == point3 && point3 != -1) point2++, point3 = -1;
		if (point2 == point1 && point2 != -1) point1++, point2 = -1;

		if (point1 < point2) swap(point1, point2); 
		if (point1 < point3) swap(point1, point3);
		if (point2 < point3) swap(point2, point3);
	}
};

const int N = 2004;
int n;
data a[N];
int bestAns[N], worstAns[N];

int bestRanking(int id) {
	data bestPoint = a[id];
	bestPoint.point3 = 1;

	int l = 0, r = n, bestId = -1;
	while (l <= r) {
		int mid = (l + r) / 2;
		bool ok = true;

		int currentPoint3 = n;
		for (int i = mid+1; i <= n; ++i) {
			if (i == id) continue;

			data tmpPoint = a[i];
			tmpPoint.point3 = currentPoint3;
			tmpPoint.reArrange();

			if (tmpPoint < bestPoint) {
				ok = false;
				break;
			}
			currentPoint3--;
		}

		if (ok) {
			bestId = mid;
			r = mid - 1;
		}
		else l = mid + 1;
 	} 

 	if (bestId >= id) return bestId;
 	return bestId + 1; 
} 

int worstRanking(int id) {
	data worstPoint = a[id];
	worstPoint.point3 = n;
	worstPoint.reArrange();

	int l = 0, r = n, bestId = -1; 
	while (l <= r) {
		int mid = (l + r) / 2;
		bool ok = true;

		int currentPoint3 = 1;
		for (int i = mid; i >= 1; --i) {
			if (i == id) continue;

			data tmpPoint = a[i];
			tmpPoint.point3 = currentPoint3;
			tmpPoint.reArrange();

			if (worstPoint <= tmpPoint) {
				ok = false;
				break;
			}
			currentPoint3++;
		}

		if (ok) {
			bestId = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}

	if (bestId >= id) return bestId;
 	return bestId + 1; 
}

void sol() {
	sort(a+1, a+n+1);

	for (int i = 1; i <= n; ++i) {
		cerr << a[i].id << " --> " << a[i].point1 << " " << a[i].point2 << " " << a[i].point3 << '\n';
	}

	for (int i = 1; i <= n; ++i) {
		bestAns[a[i].id] = bestRanking(i);
		worstAns[a[i].id] = worstRanking(i);
	}

	for (int i = 1; i <= n; ++i) {
		cout << bestAns[i] << " " << worstAns[i] << '\n';
	}
}	

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i].point1;
	for (int i = 1; i <= n; ++i) {
		a[i].id = i;
		cin >> a[i].point2;
		a[i].reArrange();
	}

	sol();

	return 0;
}