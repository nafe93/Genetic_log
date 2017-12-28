#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>

#include <bitset>
#include <limits>

#define _USE_MATH_DEFINES

using namespace std;

//convert double to byte
bitset<8> double2bitset(double d) {
    char *bits = reinterpret_cast<char *>(&d);
    for (std::size_t n = 0; n < sizeof d; ++n) {
        std::cout << std::bitset<8>(bits[n]);

    }
    cout << endl;
}

void float2bit()
{
    int i; // declare variables
    float f;
    int bit = 0;
    cout << "Enter a floating point number: "; // enter a float
    cin >> f; // read in the number

    int *b = reinterpret_cast<int*>(&f); // use reinterpret_cast function
    for (int k = 31; k >=0; k--) // for loop to print out binary pattern
    {
        bit = ((*b >> k)&1); // get the copied bit value shift right k times, then and with a 1.
        cout << bit; // print the bit.
    }
}

// Function
double f(double x)
{
    return sin(x) - x /3;
}

// Derivative
double derivative(double x, double h) // function points, step
{
    const double delta = 1.0e-6; // or similar
    double x1 = x - delta;
    double x2 = x + delta;
    double y1 = f(x1);
    double y2 = f(x2);
    return (y2 - y1) / (x2 - x1);
}

//sum of def
double buf_sum(double A, double B, double C)
{
    double sum = 0;
    for(A; A < B; A= A + C)
    {
        sum = sum + 1/fabs(derivative(A,0.1));
        //cout << sum << endl;
    }
    return sum;
}

// fitness
double Fitness(double A,double B, double C)
{
    double *fitness = new double();
    int i = 0;
    double sum = buf_sum(A,B,C);
    for(A; A < B; A= A + C)
    {
        //cout << i++ << endl;
        i++;
        fitness[i] = (1/fabs(derivative(A,0.1)))/sum;
        cout << fitness[i] * 100 << endl;
    }
    return 0;
}
// same function fitness but using vector
double Fitness_vector(double A, double B, double C)
{
    int i = 0;
    vector<double> fitness;
    double sum = buf_sum(A,B,C);
    for(A; A < B; A= A + C)
    {
        i++;
        fitness.resize(i + 1);
        fitness[i] = (1/fabs(derivative(A,0.1)))/sum;
        cout << A << endl;
        cout << fitness[i] * 100 << endl;
    }
}

// mutation
double mutation(double x0 , double x1)
{
    const int number = 1000000;
    return fabs((double)((rand() * number) % (int)((x1 - x0)*number) + 1) / number) + x0;
}
//inversion :: search around
double inversion(double x, double eps)
{
    static int sign = 0;
    sign ++;
    sign %=2;
    if(sign == 0) return x - eps;
    else return x + eps;
}
