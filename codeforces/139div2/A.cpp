#include<stdio.h>

int main() {

	bool suc = true;

	int n, x;
	int a[111];
	int b[111];

	scanf("%d %d", &n, &x);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i], &b[i]);
		if (x == a[i] || x + a[i] == 7 || x == b[i] || x + b[i] == 7) {
			suc = false;
		}
	}

	puts(suc ? "YES" : "NO");

	while (1);





	return 0;
}
