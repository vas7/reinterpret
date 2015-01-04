#ifndef REINTERPRET_H
#define REINTERPRET_H

#include <string>

using namespace std;

typedef unsigned int uint;
typedef long long llong;
typedef unsigned long long ullong;

static_assert(sizeof(int) == 4, "sizeof(int) != 4");
static_assert(sizeof(float) == 4, "sizeof(float) != 4");
static_assert(sizeof(double) == 8, "sizeof(double) != 8");
static_assert(sizeof(llong) == 8, "sizeof(long long int) != 8");

#define int2int(x) (x)
#define llong2llong(x) (x)

int uint2int(uint u);
int uint2int(string s);
uint int2uint(int i);
uint int2uint(string s);

int float2int(float f);
int float2int(string s);
float int2float(int i);
float int2float(string s);

llong ullong2llong(ullong u);
llong ullong2llong(string s);
ullong llong2ullong(llong l);
ullong llong2ullong(string s);

llong double2llong(double d);
llong double2llong(string s);
double llong2double(llong l);
double llong2double(string s);

int bits2int(string s);
string int2bits(int i);
string int2bits(string s);

llong bits2llong(string s);
string llong2bits(llong l);
string llong2bits(string s);

#endif // REINTERPRET_H
