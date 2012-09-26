#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#define ll long long
using namespace std;


int n, m;
ll a[111111];

ll solve(int k) {
	priority_queue<ll, vector<ll>, greater<ll> > q;
	for (int i = 0; i < n; i++) {
		q.push(a[i]);
	}

	ll s = 0;
	while (q.size() > 1) {
		ll sum = 0;
		ll tmp;
		for (int i = 0; i <= k && q.size() > 0; i++) {
			tmp = q.top();
			s += q.top();
			sum += q.top();
			q.pop();
		}
		s -= tmp;
		q.push(sum);
	}
	return s;
}


int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int k;
		scanf("%d", &k);
		printf("%I64d%c", solve(k), i < m - 1 ? ' ' : '\n');
	}

	return 0;
}
