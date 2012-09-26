#include<stdio.h>
#include<math.h>
#include<algorithm>
#define ll long long
using namespace std;

ll MOD;
ll l, r, k;

ll cnt(ll x) {
	ll a = l % x == 0 ? l / x : l / x + 1;
	ll b = r / x;
//	printf("%I64d -- > %I64d\n", x, max(b - a + 1, 0LL));

	return max(b - a + 1, 0LL);
}

struct Matrax {
    ll m[3][3];
};
Matrax A , per;
void Init() {                   //≥ı ºªØ
    for(ll i = 0 ; i < 2 ; i ++) {
        for (ll j = 0 ; j < 2 ; j ++) {
            per.m[i][j] = (i == j);
            if(i==1&&j==1) A.m[i][j] = 0;
            else A.m[i][j] = 1;
        }
    }
}
Matrax multi(Matrax a , Matrax b) {
    ll i , j , k;
    Matrax c;
    for(i = 0 ; i < 2 ; i ++)
        for(j = 0 ; j < 2 ; j ++) {
            c.m[i][j] = 0;
            for(k = 0 ; k < 2 ; k ++) {
                c.m[i][j] += a.m[i][k]*b.m[k][j];
                c.m[i][j]%=MOD;
                //printf("%d\n",c.m[i][j]);
            }
        }
        return c;
}
Matrax power(ll k) {
    Matrax ans , p;
    ans = per;
    p = A;
    while (k) {
        if(k&1) {
            ans = multi(ans , p);
        }
        k/=2;
        p = multi(p , p);
    }
    return ans;
}


int main() {
	scanf("%I64d %I64d %I64d %I64d", &MOD, &l, &r, &k);

	ll gcd = 0;
	ll sqrtt = sqrt(r);
	for (ll i = 1; i < sqrtt + 0.5; i++) {
		if (cnt(i) >= k) {
			gcd = max(gcd, i);
		}
		if (cnt(r / i) >= k) {
			gcd = max(gcd, r / i);
		}
	}

	Init();
	Matrax ans = power(gcd);
	printf("%I64d\n", ans.m[1][0] % MOD);
	return 0;
}
