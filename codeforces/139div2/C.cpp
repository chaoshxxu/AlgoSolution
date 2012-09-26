#include<algorithm>
#include<stdio.h>
#include<string.h>
using namespace std;

int n, m;
int x, y;

char b[1111][1111];
int cnt[1111];
int dp[1111][1111][2];

int main() {
	scanf("%d %d %d %d", &n, &m, &x, &y);
	for (int i = 0; i < n; i++) {
		scanf("%s", b[i]);
	}
	for (int c = 0; c < m; c++) {
		for (int r = 0; r < n; r++) {
			cnt[c] += b[r][c] == '#';
		}
	}

	memset(dp, 0x7f, sizeof dp);
	for (int i = 0; i < m; i++) {
		if (i == 0) {
			dp[i][1][0] = cnt[i];
			dp[i][1][1] = n - cnt[i];
			continue;
		}
		for (int k = x; k <= y; k++) {
			dp[i][1][0] = min(dp[i][1][0], dp[i - 1][k][1] + cnt[i]);
			dp[i][1][1] = min(dp[i][1][1], dp[i - 1][k][0] + n - cnt[i]);
		}
		for (int j = 2; j <= y && j <= i + 1; j++) {
			dp[i][j][0] = dp[i - 1][j - 1][0] + cnt[i];
			dp[i][j][1] = dp[i - 1][j - 1][1] + n - cnt[i];
		}
	}

	int ans = 99999999;
	for (int j = x; j <= y; j++) {
		ans = min(ans, dp[m - 1][j][0]);
		ans = min(ans, dp[m - 1][j][1]);
	}

	printf("%d\n", ans);

	return 0;
}
