#include<stdio.h>
#include<math.h>
#include<algorithm>
#define eps 1e-8
#define SGN(x) ((x)>eps?1:((x)>-eps?0:-1))
using namespace std;

//二维点
struct pt
{
	double x, y;
	pt(){}
	pt(double _x, double _y):x(_x), y(_y){}
	pt operator - (const pt p1){return pt(x - p1.x, y - p1.y);}
	pt operator + (const pt p1){return pt(x + p1.x, y + p1.y);}
	pt operator * (double s){return pt(x * s, y * s);}
	pt operator / (double s){return pt(x / s, y / s);}
	bool operator < (const pt p1)const{return y < p1.y-eps || y < p1.y+eps && x < p1.x;}
	bool operator == (const pt p1)const{return !SGN(y - p1.y) && !SGN(x - p1.x);}
	bool operator != (const pt p1)const{return SGN(y - p1.y) || SGN(x - p1.x);}
	void read(){scanf("%lf %lf", &x, &y);}
};

//叉积 点击(传入点)
double cpr(const pt &a,const pt &b,const pt &c){return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);}
double dpr(const pt &a,const pt &b,const pt &c){return (b.x-a.x)*(c.x-a.x)+(b.y-a.y)*(c.y-a.y);}

//两点距离
double vlen(const pt &a){return sqrt(a.x*a.x+a.y*a.y);}
double dis(const pt &a, const pt &b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}


////////////////////////////////////////////////////

int n;
pt p[111];
int v[111];

int check(int a, int b) {
	int cnt1 = 0;
	int cnt2 = 0;
	int cnt3 = 0;
	int cnt4 = 0;
	for (int i = 0; i < n; i++) {
		double cross = cpr(p[a], p[b], p[i]);
		if (cross > eps) {
			cnt1 += v[i];
		} else if (cross < -eps) {
			cnt2 += v[i];
		} else if (dpr(p[i], p[a], p[b]) < 0) {
			return 0;
		} else if (dis(p[i], p[a]) < dis(p[i], p[b])) {
			cnt3 += v[i];
		} else {
			cnt4 += v[i];
		}
	}
	int A, B;

	A = cnt1 + cnt3;
	B = cnt2 + cnt4;
	int min1 = min(A, B);

	A = cnt1 + cnt4;
	B = cnt2 + cnt3;
	int min2 = min(A, B);

	return max(min1, min2);
}

int solve() {
	if (n < 2) {
		return 0;
	}

	int maxMin = -1;
	for (int i = 0; i < n ;i++) {
		for (int j = 0; j < i ;j++) {
			maxMin = max(maxMin, check(i, j));
		}
	}
	return maxMin;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		p[i].read();
		scanf("%d", &v[i]);
	}
	printf("%d\n", solve());

	return 0;
}
