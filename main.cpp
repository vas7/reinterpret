#include "reinterpret.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> typenames {"bits", "int", "uint", "float", "llong", "ullong", "double"};
bool typenameIsCorrect(string tname) {
	return count(typenames.cbegin(), typenames.cend(), tname) == 1;
}

void usageError(int exit_code) {
	cerr << "Usage: reinterpret <typename1> <typename2> <value>\n";
	cerr << "       reinterpret int bits 123\n";
	cerr << "       reinterpret float bits 123.4E-5\n";
	cerr << "       reinterpret float int 123.4E-5\n";
	cerr << "Typenames:" << endl;
	for (string t: typenames)
		cerr << "    " << t << endl;
	exit(exit_code);
}

int main(int argc, char** argv) {
	if (argc != 4)
		usageError(1);

	string typename1 = argv[1];
	string typename2 = argv[2];
	string value = argv[3];

	if (!typenameIsCorrect(typename1) || !typenameIsCorrect(typename1))
		usageError(2);

	if (typename1 == "bits") {
		     if (typename2 == "int")    cout << int2int(bits2int(value));
		else if (typename2 == "uint")   cout << int2uint(bits2int(value));
		else if (typename2 == "float")  cout << int2float(bits2int(value));
		else if (typename2 == "llong")  cout << llong2llong(bits2llong(value));
		else if (typename2 == "ullong") cout << llong2ullong(bits2llong(value));
		else if (typename2 == "double") cout << llong2double(bits2llong(value));
	} else if (typename1 == "int") {
		     if (typename2 == "bits")   cout << int2bits(int2int(value));
		else if (typename2 == "uint")   cout << int2uint(int2int(value));
		else if (typename2 == "float")  cout << int2float(int2int(value));
		else                            usageError(3);
	} else if (typename1 == "uint") {
		     if (typename2 == "bits")   cout << int2bits(uint2int(value));
		else if (typename2 == "int")    cout << int2int(uint2int(value));
		else if (typename2 == "float")  cout << int2float(uint2int(value));
		else                            usageError(3);
	} else if (typename1 == "float") {
		     if (typename2 == "bits")   cout << int2bits(float2int(value));
		else if (typename2 == "int")    cout << int2int(float2int(value));
		else if (typename2 == "uint")   cout << int2uint(float2int(value));
		else                            usageError(3);
	} else if (typename1 == "llong") {
		     if (typename2 == "bits")   cout << llong2bits(llong2llong(value));
		else if (typename2 == "ullong") cout << llong2ullong(llong2llong(value));
		else if (typename2 == "double") cout << llong2double(llong2llong(value));
		else                            usageError(3);
	} else if (typename1 == "ullong") {
		     if (typename2 == "bits")   cout << llong2bits(ullong2llong(value));
		else if (typename2 == "llong")  cout << llong2llong(ullong2llong(value));
		else if (typename2 == "double") cout << llong2double(ullong2llong(value));
		else                            usageError(3);
	} else if (typename1 == "double") {
		     if (typename2 == "bits")   cout << llong2bits(double2llong(value));
		else if (typename2 == "llong")  cout << llong2llong(double2llong(value));
		else if (typename2 == "ullong") cout << llong2ullong(double2llong(value));
		else                            usageError(3);
	}

	cout << endl;

	return 0;
}

