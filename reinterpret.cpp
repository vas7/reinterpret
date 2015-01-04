#include "reinterpret.h"
#include <cstdlib>
#include <sstream>
#include <bitset>
#include <cassert>

int uint2int(uint u) {
	return *(reinterpret_cast<int*>(&u));
}
int uint2int(string s) {
	uint u = atoll(s.c_str());
	return uint2int(u);
}
uint int2uint(int i) {
	return *(reinterpret_cast<uint*>(&i));
}
uint int2uint(string s) {
	uint i = atoll(s.c_str());
	return int2uint(i);
}

int float2int(float f) {
	return *(reinterpret_cast<int*>(&f));
}
int float2int(string s) {
	float f = atof(s.c_str());
	return float2int(f);
}
float int2float(int i) {
	return *(reinterpret_cast<float*>(&i));
}
float int2float(string s) {
	int i = atoi(s.c_str());
	return int2float(i);
}

llong ullong2llong(ullong u) {
	return *(reinterpret_cast<llong*>(&u));
}
llong ullong2llong(string s) {
	istringstream iss(s);
	ullong u;
	iss >> u;
	return ullong2llong(u);
}
ullong llong2ullong(llong l) {
	return *(reinterpret_cast<ullong*>(&l));
}
ullong llong2ullong(string s) {
	llong l = atoll(s.c_str());
	return llong2ullong(l);
}

llong double2llong(double d) {
	return *(reinterpret_cast<llong*>(&d));
}
llong double2llong(string s) {
	double d = atof(s.c_str());
	return double2llong(d);
}
double llong2double(llong l) {
	return *(reinterpret_cast<double*>(&l));
}
double llong2double(string s) {
	llong l = atoll(s.c_str());
	return llong2double(l);
}

int bits2int(string s) {
	assert(s.length() == 32);
	bitset<32> b(s);
	return uint2int(b.to_ulong());
}
string int2bits(int i) {
	bitset<32> b = int2uint(i);
	return b.to_string();
}
string int2bits(string s) {
	bitset<32> b = int2uint(s);
	return b.to_string();
}

llong bits2llong(string s) {
	assert(s.length() == 64);
	bitset<64> b(s);
	return ullong2llong(b.to_ullong());
}
string llong2bits(llong l) {
	bitset<64> b = llong2ullong(l);
	return b.to_string();
}
string llong2bits(string s) {
	bitset<64> b = llong2ullong(s);
	return b.to_string();
}
