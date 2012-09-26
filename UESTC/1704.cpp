#include<stdio.h>
#include<math.h>
#include<algorithm>
#define PI 3.14159265358979323846
#define eps 1e-8
using namespace std;

//二维点
struct pt {
	double x, y;
	void read(){scanf("%lf %lf", &x, &y);}
};

//叉积 点击(传入点)
double cpr(const pt &a,const pt &b,const pt &c){return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);}
double dpr(const pt &a,const pt &b,const pt &c){return (b.x-a.x)*(c.x-a.x)+(b.y-a.y)*(c.y-a.y);}

//两点距离
double dis(const pt &a, const pt &b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}

//点到线段距离
double disptoseg(pt p, pt a, pt b) {
	if (dpr(a, p, b) < eps) {
		return dis(p, a);
	} else if (dpr(b, p, a) < eps) {
		return dis(p, b);
	} else {
		return fabs(cpr(b, p, a)) / dis(a, b);
	}
}

//////////////////////////////////////

pt o1, o2, m;
double r, R;

//span angle
double span(double a, double b) {
	double dif = a - b;
	while (dif > 2 * PI - eps) {
		dif -= 2 * PI;
	}
	while (dif < -eps) {
		dif += 2 * PI;
	}
	return dif < PI ? dif : 2 * PI - dif;
}

double solve() {
	//distance of monitor to seg O1-O2
	double dmoo = disptoseg(m, o1, o2);
	if (dmoo < r - R - eps) {
		return 2 * PI * R;
	} else if (dmoo > r + R + eps) {
		double polor1 = atan2(o1.y - m.y, o1.x - m.x);
		double halfViewAngle1 = asin(r / dis(m, o1));
		double ang1 = polor1 - halfViewAngle1;
		double ang2 = polor1 + halfViewAngle1;
		double polor2 = atan2(o2.y - m.y, o2.x - m.x);
		double halfViewAngle2 = asin(r / dis(m, o2));
		double ang3 = polor2 - halfViewAngle2;
		double ang4 = polor2 + halfViewAngle2;
		double res = -1.0;
		res = max(res, span(ang1, ang2));
		res = max(res, span(ang1, ang3));
		res = max(res, span(ang1, ang4));
		res = max(res, span(ang2, ang3));
		res = max(res, span(ang2, ang4));
		res = max(res, span(ang3, ang4));
		return 2 * res * R;
	} else {
		return -1.0;
	}
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		o1.read();
		o2.read();
		m.read();
		scanf("%lf %lf", &r, &R);

		double ans = solve();
		if (ans < 0.0) {
			puts("It is life.");
		} else {
			printf("%.2f\n", ans);
		}
	}
	return 0;
}
