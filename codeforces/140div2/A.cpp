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



pt A, B, C;

int main()  {
	A.read();
	B.read();
	C.read();
	if (cpr(A, B, C) > 0.01) {
		puts("LEFT");
	} else if (cpr(A, B, C) < -0.01) {
		puts("RIGHT");
	} else {
		puts("TOWARDS");
	}
	return 0;
}
