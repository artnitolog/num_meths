#include "decls.h"

static double f4(double x)
{
    return x * x * x + 2.5 * x * x - 0.5 * x + 3;
}

static double df4(double x)
{
    return 3 * x * x + 5 * x - 0.5;
}

static double (*f[])() = {f1, f2, f3, f4};
static double (*df[])() = {df1, df2, df3, df4};

void test_rt(double eps1)
{
    int n1, n2;
    double a, b;
    printf("Type the numbers of functions in the equation:\n");
    scanf("%d%d", &n1, &n2);
    n1--;
    n2--;
    printf("Set the interval (two real numbers):\n");
    scanf("%lf%lf", &a, &b);
    double test_x = root(f[n1], f[n2], df[n1], df[n2], a, b, eps1);
    printf("The approximate root is %.5lf\n", test_x);
    printf("y = %.5lf\n", f[n1](test_x));
}

void test_itg(double eps2)
{
    int n;
    double a, b;
    printf("Type the number of function to integrate:\n");
    scanf("%d", &n);
    n--;
    printf("Set the interval (two real numbers):\n");
    scanf("%lf%lf", &a, &b);
    double test_s = integral(f[n], a, b, eps2);
    printf("The integral is approximately equal to %.4lf\n", test_s);
}
