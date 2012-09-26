//Solution by lukasP (Lukáš Poláček)
#include <iostream>
#include <cstdio>
#include <cmath>
#include <complex>
using namespace std;

#define rep(i,a,b) for(__typeof(b) i=a; i<(b); ++i)

typedef complex<double> point;
double dp(const point &a, const point &b) {//dot product
    return real(conj(a)*b);
}
double dist_line(point s, point t, point l)
{
    double a = -imag(t - s);
    double b = real(t - s);
    double c = -(a * real(s) + b * imag(s));
    return abs(a * real(l) + b * imag(l) + c) / hypot(a, b);
}
double angle(const point& x, const point& y)
{
    double r = acos( dp(x, y)/sqrt(dp(x, x))/sqrt(dp(y, y)) );
    if (r < 0) r += M_PI;
    return r;
}
double third_side(double c, double a)
{
    if (c * c - a * a <= 0)
        return 0;
    return sqrt(c * c - a * a);
}

double F(double x, double g)
{
    return (x * sqrt(x / g * x / g + 1) + g * asinh(x / g)) / 2;
}

double integrate(double a, double b, double h, double g)
{
    return g * (F(b, h) - F(a, h));
}

point rotate_around(point a, point b, point rot)
{
    return (b - a) * rot + a;
}

double cap(double x, double maxx)
{
    if (x > maxx) return maxx;
    if (x < -maxx) return -maxx;
    return x;
}

double square(double x) { return x * x; }
void solve()
{
    double lx, ly, lz, langle;
    cin >> lx >> ly >> lz >> langle;
    langle = langle / 360 * M_PI;
    int n; cin >> n;
    point a[n];
    rep(i,0,n)
    {
        double x, y; cin >> x >> y;
        a[i] = point(x, y);
    }

    point lamp(lx, ly);
    double res = 0;
    double r = tan(langle) * lz;
    double circular = 0;
    rep(i,0,n)
    {
        int j = (i + 1) % n;
        point q = a[j] - a[i];
        q = conj(q) / abs(q);

        point ai = a[i], aj = rotate_around(a[i], a[j], q), l = rotate_around(a[i], lamp, q);
        double dist = abs(imag(l) - imag(ai));
        if (dist * (1 + 1e-8) > r)
        {
            circular += angle(a[i] - lamp, a[j] - lamp);
            continue;
        }
        double max_hyper = third_side(r, dist);
        double x = cap(real(ai - l), max_hyper),
               y = cap(real(aj - l), max_hyper);

        double hb = lz * dist / r;
        double ha = max_hyper / sqrt(square(r / dist) - 1);
        res += (y - x) * lz - integrate(x, y, ha, hb) + (y - x) * dist / 2;

        double angl = atan(y / dist) - atan(x / dist);
        circular += angle(a[i] - lamp, a[j] - lamp) - angl;
    }
    printf("%.9lf\n", res + circular * r * r / 2);
}

int main()
{
    int tests; cin >> tests;
    rep(i,0,tests)
        solve();
}
