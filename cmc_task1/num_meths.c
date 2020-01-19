#include "decls.h"

#define h(x) (f(x) - g(x))
#define dh(x) (df(x) - dg(x))

double root(
        double (*f)(double),
        double (*g)(double),
        double (*df)(double),
        double (*dg)(double),
        double a,
        double b,
        double eps1)
{
    cnt = 0;
    if ((h(a) < 0) == (h((a + b) / 2) < (h(a) + h(b)) / 2)) {
        while (b - a > eps1) {
            a = (a * h(b) - b * h(a)) / (h(b) - h(a));
            b = b - h(b) / dh(b);
            cnt++;
        }
    }
    else {
        while (b - a > eps1) {
            b = (a * h(b) - b * h(a)) / (h(b) - h(a));
            a = a - h(a) / dh(a);
            cnt++;
        }
    }
    return (a + b) / 2;
}

double integral(
        double (*f)(double),
        double a,
        double b,
        double eps2)
{
    int n = 1;
    double h = b - a;
    double s_prev, s_cur;
    s_cur = f((a + b) / 2) * h;
    do {
        n *= 2;
        h /= 2;
        s_prev = s_cur;
        s_cur = 0;
        for (int i = 0; i < n; i++) {
            s_cur += f(a + (i + 0.5) * h);
        }
        s_cur *= h;
    } while (fabs(s_cur - s_prev) >= eps2 * 3);
    return s_cur;
}
