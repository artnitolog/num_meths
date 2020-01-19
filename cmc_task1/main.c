#include "decls.h"

int main(int argc, char *argv[])
{
    const double eps1 = 0.00001, eps2 = 0.0001;
    int opt;
    char opt_str[] = "hacir";
    bool pr_absc = false, pr_it = false;
    while ((opt = getopt(argc, argv, opt_str)) != -1) {
        switch (opt) {
        case 'h':
            printf("%13s\n", "Options:");
            printf("%9s\t", "-a");
            printf("print abscissas of intersection points of the curves\n");
            printf("%9s\t", "-c");
            printf("print the number of iterations to find approximate roots\n");
            printf("%9s\t", "-i");
            printf("enable test mode for numerical integration\n");
            printf("%9s\t", "-r");
            printf("enable test mode for numerical solution of equations\n");
            printf("%9s\t", "-h");
            printf("see this list\n");
            break;
        case 'a':
            pr_absc = true;
            break;
        case 'c':
            pr_it = true;
            break;
        case 'i':
            test_itg(eps2);
            break;
        case 'r':
            test_rt(eps1);
            break;
        case '?':
            printf("Unrecognized option. Try \'-h\'.\n");
            break;
        }
    }
    double x1, x2, x3;
    x1 = root(f1, f3, df1, df3, -3, -2, eps1);
    if (pr_it)
        printf("x1 was counted in %d iterations\n", cnt);
    x2 = root(f2, f3, df2, df3, -1, -0.1, eps1);
    if (pr_it)
        printf("x2 was counted in %d iterations\n", cnt);
    x3 = root(f1, f2, df1, df2, 0, 2, eps1);
    if (pr_it)
        printf("x3 was counted in %d iterations\n", cnt);
    if (pr_absc) {
        printf("x1 = %.5lf\n", x1);
        printf("x2 = %.5lf\n", x2);
        printf("x3 = %.5lf\n", x3);
    }
    double s = integral(f3, x1, x2, eps2);
    s += integral(f2, x2, x3, eps2);
    s -= integral(f1, x1, x3, eps2);
    printf("The area between curves is approximately %.3lf\n", s);
    return 0;
}
