#pragma once
#include <stdio.h>
#include <getopt.h>
#include <stdbool.h>
#include <math.h>

int cnt; //iteration counter

double f1(double x);
double f2(double x);
double f3(double x);
double df1(double x);
double df2(double x);
double df3(double x);

double root(
        double (*f)(double),
        double (*g)(double),
        double (*df)(double),
        double (*dg)(double),
        double a,
        double b,
        double eps1);

double integral(
        double (*f)(double),
        double a,
        double b,
        double eps2);

void test_rt(double eps1);
void test_itg(double eps2);
