#include<stdio.h>
#include<math.h>
#include<algorithm>
#define PI 3.14159265358979323846
#define eps 1e-9
#define zero(x) (fabs(x)<eps)
#define SGN(x) ((x)>eps?1:((x)>-eps?0:-1))
#define _sign(x) ((x)>eps?1:((x)<-eps?2:0))
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

//叉积 点击(传入向量) 
double cpr(const pt &a,const pt &b){return a.x*b.y-a.y*b.x;}
double dpr(const pt &a,const pt &b){return a.x*b.x+a.y*b.y;}

//两点距离 
double vlen(const pt &a){return sqrt(a.x*a.x+a.y*a.y);}
double dis(const pt &a, const pt &b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}


//求直线ab和直线cd的交点
pt its(pt a, pt b, pt c, pt d)
{
	double v1 = cpr(a, b, c), v2 = cpr(a, b, d);
	return (c * v2 - d * v1) / (v2 - v1);
}

//计算直线与圆的交点,保证直线与圆有交点
//计算线段与圆的交点可用这个函数后判点是否在线段上
void intersection_line_circle(pt c, double r, pt l1, pt l2, pt &p1, pt &p2)
{
	pt p = c;
	p.x += l1.y - l2.y;
	p.y += l2.x - l1.x;
	p = its(p, c, l1, l2);
	double d = dis(p,c), t = sqrt(r*r - d*d) / dis(l1,l2);
	p2.x = p.x + (l2.x-l1.x)*t;
	p2.y = p.y + (l2.y-l1.y)*t;
	p1.x = p.x - (l2.x-l1.x)*t;
	p1.y = p.y - (l2.y-l1.y)*t;
}

//点p到直线ab距离 
double disptoline(const pt &p, const pt &a, const pt &b)
{
	return fabs(cpr(p, a, b)) / dis(a, b);
}


/////////////////////////////////////////////////////////////////////////

pt p[200];
double lx, ly, h, a;
int n;

pt O;
double r;

double ca, cb, cc;

double tana2;


inline double ang(double a1, double a2)
{
	double tmp = fabs(a1 - a2);
	if (tmp > PI)
		tmp = 2 * PI - tmp;
	return tmp;	
}

double bottom_ans(pt a, pt b)
{
	double sgn = cpr(O, a, b) > 0 ? 1.0 : -1.0;
	pt X1, X2;

	double d1 = dis(O, a);
	double d2 = dis(O, b);
	if (d1 < r && d2 < r)
	{
		return cpr(O, a, b);
	}
	if (d1 > r && d2 > r)
	{
		if (disptoline(O, a, b) >= r - eps)
		{
			return sgn * r * r * ang(atan2(a.y - O.y, a.x - O.x), atan2(b.y - O.y, b.x - O.x));
		}
		if (dpr(b, O, a) < 0 || dpr(a, O, b) < 0)
		{
			return sgn * r * r * ang(atan2(a.y - O.y, a.x - O.x), atan2(b.y - O.y, b.x - O.x));
		}
		intersection_line_circle(O, r, a, b, X1, X2);
		return sgn * (r * r * ang(atan2(a.y - O.y, a.x - O.x), atan2(X1.y - O.y, X1.x - O.x)) + r * r * ang(atan2(b.y - O.y, b.x - O.x), atan2(X2.y - O.y, X2.x - O.x)) + fabs(cpr(O, X1, X2)));
	}
	
	if (d1 > d2)
	{
		swap(a, b);
	}
	intersection_line_circle(O, r, b, a, X1, X2);
	if (dpr(X1, a, b) > 0)while (1);
	return sgn * (r * r * ang(atan2(b.y - O.y, b.x - O.x), atan2(X1.y - O.y, X1.x - O.x)) + fabs(cpr(O, a, X1)));
}

double bottom_ans()
{
	double ans = 0.0;
	for (int i = 0; i < n; i++)
	{
		ans += bottom_ans(p[i], p[(i + 1) % n]);
	}
	return ans / 2.0;
}

double fx(double x)
{
	double dx = x - lx;
	double dy = (-ca * x - cc) / cb - ly;
	double res = h - sqrt(dx * dx + dy * dy) / tana2;
//	if (res < 0)
//	{
//		printf("%lf -> %lf\n", x, res);
//	}
	return res;
}

double simpson_x(double x1, double x2)
{
//	printf("%lf -- %lf\n", (fx(x1) + fx(x2) + 4 * fx((x1 + x2) / 2.0)), (6.0 * (x2 - x1)));
	return (fx(x1) + fx(x2) + 4 * fx((x1 + x2) / 2.0)) / 6.0 * (x2 - x1);
}

double rsimpson_x(double x1, double x2)
{
	if (x1 > x2)swap(x1, x2);
	
	double v = simpson_x(x1, x2);
	double v1 = simpson_x(x1, (x1 + x2) / 2.0);
	double v2 = simpson_x((x1 + x2) / 2.0, x2);
//	printf("%lf\n", v - v1 - v2);
	
	if (fabs(v - v1 - v2) < eps)
	{
		return v;
	} else
	{
		return rsimpson_x(x1, (x1 + x2) / 2.0) + rsimpson_x((x1 + x2) / 2.0, x2);
	}
}




double fy(double y)
{
	double dx = (-cb * y - cc) / ca - lx;
	double dy = y - ly;
	return h - sqrt(dx * dx + dy * dy) / tana2;
}

double simpson_y(double y1, double y2)
{
	return (fy(y1) + fy(y2) + 4 * fy((y1 + y2) / 2.0)) / 6.0 * (y2 - y1);
}

double rsimpson_y(double y1, double y2)
{
	if (y1 > y2)swap(y1, y2);
	
	double v = simpson_y(y1, y2);
	double v1 = simpson_y(y1, (y1 + y2) / 2.0);
	double v2 = simpson_y((y1 + y2) / 2.0, y2);
//	printf("%lf\n", v - v1 - v2);
	
	if (fabs(v - v1 - v2) < eps)
	{
		return v;
	} else
	{
		return rsimpson_y(y1, (y1 + y2) / 2.0) + rsimpson_y((y1 + y2) / 2.0, y2);
	}
}

double wall_ans(pt p1, pt p2)
{
	pt X1, X2;
	if (disptoline(O, p1, p2) >= r - eps)
	{
		return 0.0;
	}
	
	intersection_line_circle(O, r, p1, p2, X1, X2);
	pt Y1 = X1;
	pt Y2 = X2;
	
	if (dpr(Y1, p1, Y2) > 0)
	{
		X1 = p1;
	}
	if (dpr(Y2, p2, Y1) > 0)
	{
		X2 = p2;
	}
	if (dpr(X2 - X1, p2 - p1) < 0)
	{
		return 0.0;
	}
	if (dpr(X1, Y1, Y2) > 0 || dpr(X2, Y1, Y2) > 0)puts("!");
	
	double dx = fabs(X1.x - X2.x);
	double dy = fabs(X1.y - X2.y);
	
	ca = X2.y - X1.y;
	cb = X1.x - X2.x;
	cc = X2.x * X1.y - X1.x * X2.y;
	
	if (dx > dy)
	{
//		printf("%lf %lf\n", fx(X1.x), fx(X2.x));
		return rsimpson_x(X1.x, X2.x);
	} else
	{
//		printf("%lf %lf\n", fy(X1.y), fy(X2.y));
		return rsimpson_y(X1.y, X2.y);
	}
}

double solve()
{
	scanf("%lf %lf %lf %lf", &lx, &ly, &h, &a);
	a *= PI / 180.0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		p[i].read();
	}
	
	O = pt(lx, ly);
	r = h * tan(a / 2.0);
	tana2 = tan(a / 2);
	
	double ans = bottom_ans();
	for (int i = 0; i < n; i++)
	{
		ans += wall_ans(p[i], p[(i + 1) % n]);
	}
	return ans;
}


int main()
{
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		printf("%.10lf\n", solve());
	}
	return 0;
}


/*

5 5 5 91
4
-100 -100
100 -100
100 100
-100 100

5 5 5 91
4
0 0
10 0
10 10
0 10


*/
