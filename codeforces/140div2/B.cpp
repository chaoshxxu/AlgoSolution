#include<stdio.h>
#include<math.h>
#include<algorithm>
#define MAXV 2000
#define PI 3.14159265358979323846
#define eps 1e-8
#define zero(x) (fabs(x)<eps)
#define SGN(x) ((x)>eps?1:((x)>-eps?0:-1))
#define _sign(x) ((x)>eps?1:((x)<-eps?2:0))
using namespace std;


int n;
int a[111111];

int m;
int b[111111];

int pos[111111];

long long ans1, ans2;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		pos[a[i]] = i;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &b[i]);
		ans1 += pos[b[i]] + 1;
		ans2 += n - pos[b[i]];
	}
	printf("%I64d %I64d\n", ans1, ans2);

	return 0;
}
