#include<stdio.h>
#include<math.h>
#include<algorithm>
#define MAXV 2000
#define PI 3.14159265358979323846
#define eps 1e-8
#define zero(x) (fabs(x)<eps)
#define SGN(x) ((x)>eps?1:((x)>-eps?0:-1))
#define _sign(x) ((x)>eps?1:((x)<-eps?2:0))
#define ll long long
using namespace std;

ll n, m;

int main() {
	scanf("%I64d %I64d", &n, &m);

	ll res = 1;
	ll mul = 3;
	while (n) {
		if (n & 1) {
			res *= mul;
			res %= m;
		}
		n >>= 1LL;
		mul *= mul;
		mul %= m;
	}
	printf("%I64d\n", (res + m - 1) % m);

	return 0;
}
