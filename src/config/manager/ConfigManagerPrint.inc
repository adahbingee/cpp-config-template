#include <iostream>
#include <string>

using namespace std;

#define CFG_PRINT(x) cfgPrint(#x, x)

/*
 * print int, float, double array
 */
template <class T, size_t size>
void cfgPrint(const string &name, T (&value)[size]) {
	printf("%-40s ", name.c_str());
	for (size_t i = 0; i < size; ++i) {

		bool isInt = value[i] == (int) value[i];

		if ( isInt ) {
			if (i == size-1) {
				printf("%d\n", (int) value[i]);
			} else {
				printf("%d, ", (int) value[i]);
			}
		} else {
			if (i == size-1) {
				printf("%f\n", (double) value[i]);
			} else {
				printf("%f, ", (double) value[i]);
			}
		}
	}
}

template <size_t size>
void cfgPrint(const string &name, bool (&value)[size]) {
	printf("%-40s ", name.c_str());
	for (size_t i = 0; i < size; ++i) {
		if (i == size-1) {
			printf("%s\n", (value[i])?"true":"false");
		} else {
			printf("%s, ", (value[i])?"true":"false");
		}
	}
}

/*
 * print char array as string format
 */
template <size_t size>
void cfgPrint(const string &name, char (&value)[size]) {
	printf("%-40s %s\n", name.c_str(), value);
}

void cfgPrint(const string &name, int value) {
	printf("%-40s %d\n", name.c_str(), value);
}

void cfgPrint(const string &name, float value) {
	printf("%-40s %e\n", name.c_str(), value);
}

void cfgPrint(const string &name, double value) {
	printf("%-40s %e\n", name.c_str(), value);
}

void cfgPrint(const string &name, bool value) {
	printf("%-40s %s\n", name.c_str(), (value)?"true":"false");
}

void cfgPrint(const string &name, const string &value) {
	printf("%-40s %s\n", name.c_str(), value.c_str());
}

