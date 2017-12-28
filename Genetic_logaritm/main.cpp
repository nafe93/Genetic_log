#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>

#include <bitset>
#include <limits>

#define _USE_MATH_DEFINES

#include "Genetic_Algoritm.hpp"

using namespace std;


union FloatInt
{
    float f;
    int i;
};

union Converter { uint64_t i; double d; };

double convert(std::bitset<64> const& bs)
{
    static_assert(sizeof(uint64_t) == sizeof(double), "Cannot use this!");

    uint64_t const u = bs.to_ullong();
    double d;

    // Aliases to `char*` are explicitly allowed in the Standard (and only them)
    char const* cu = reinterpret_cast<char const*>(&u);
    char* cd = reinterpret_cast<char*>(&d);

    // Copy the bitwise representation from u to d
    memcpy(cd, cu, sizeof(u));

    return d;
}

int main()
{
    std::cout << "Genetic algorithm" << std::endl;
    cout << "Please insert interval A-B" << endl;

    double A,B,C;
    cin >> A;
    cin >> B;

    cout << "Please insert range " << endl;

    cin >> C;

    if(A>B)
    {
        cout << "Error!Your insert not true" << endl;
        return -1;
    }
    else
    {

        Fitness_vector(A,B,C);
        double2bitset(1.123);
        float2bit();
        cout << endl;
        //test("0000000000000000000000000000000000000000000000001111000000111111");

        std::string bit_string = "00111111100000000000000000000000";
        std::bitset<32> b3(bit_string);       // [0,0,1,1,0,0,1,0]

        std::cout << b3.to_ullong() << std::endl ;

//        FloatInt foo;
//        foo.f = 1.0;
//        bitset<32> second(foo.i);
//
//        cout << "safasfsaf : " << second.to_string() << endl;

       // cout << convert(b3) << endl;



    }


    return 0;
}