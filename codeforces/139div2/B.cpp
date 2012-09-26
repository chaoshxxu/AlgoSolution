#include<stdio.h>
#include<vector>
#define ll long long
#define N 50


using namespace std;


ll f[N];
int I;
bool v[N];
int s, k;


int main() {

	scanf("%d %d", &s, &k);

	for (int n = k; ; n++) {
		if (n == k) {
			f[n - k] = 1;
		} else {
			for (int i = max(n - k, k); i <= n - 1; i++) {
				f[n - k] += f[i - k];
			}
		}
		if (f[n - k] > s)break;
		I = n - k;
//		printf("%d -> %I64d\n", n, f[n - k]);
	}
//	while (1);

	vector<int> ans;
	while (s) {
//		printf("s = %d\n", s);
		for (int i = I; i >= 0; i--) {
			if (!v[i] && f[i] <= s) {
				v[i] = 1;
				s -= f[i];
				ans.push_back(f[i]);
				break;
			}
		}
	}
	printf("%d\n", ans.size() + 1);
	for (int i = 0; i < ans.size(); i++){
		printf("%d ", ans[i]);
	}
	puts("0");

//	while (1);

	return 0;
}
