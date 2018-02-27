#include <iostream>
#include <string>

using namespace std;

FILE *writeFile = NULL; // write file pointer
#define CFG_WRITE(x) cfgWrite(#x, x)

/*
 * print int, float, double array
 */
template <class T, size_t size>
void cfgWrite(const string &name, T (&value)[size]) {
	fprintf(writeFile, "%-40s ", name.c_str());
	for (size_t i = 0; i < size; ++i) {

		bool isInt = value[i] == (int) value[i];

		if ( isInt ) {
			if (i == size-1) {
				fprintf(writeFile, "%d\n", (int) value[i]);
			} else {
				fprintf(writeFile, "%d, ", (int) value[i]);
			}
		} else {
			if (i == size-1) {
				fprintf(writeFile, "%f\n", (double) value[i]);
			} else {
				fprintf(writeFile, "%f, ", (double) value[i]);
			}
		}
	}
}

template <size_t size>
void cfgWrite(const string &name, bool (&value)[size]) {
	fprintf(writeFile, "%-40s ", name.c_str());
	for (size_t i = 0; i < size; ++i) {
		if (i == size-1) {
			fprintf(writeFile, "%s\n", (value[i])?"true":"false");
		} else {
			fprintf(writeFile, "%s, ", (value[i])?"true":"false");
		}
	}
}

/*
 * print char array as string format
 */
template <size_t size>
void cfgWrite(const string &name, char (&value)[size]) {
	fprintf(writeFile, "%-40s %s\n", name.c_str(), value);
}

void cfgWrite(const string &name, int value) {
	fprintf(writeFile, "%-40s %d\n", name.c_str(), value);
}

void cfgWrite(const string &name, float value) {
	fprintf(writeFile, "%-40s %e\n", name.c_str(), value);
}

void cfgWrite(const string &name, double value) {
	fprintf(writeFile, "%-40s %e\n", name.c_str(), value);
}

void cfgWrite(const string &name, bool value) {
	fprintf(writeFile, "%-40s %s\n", name.c_str(), (value)?"true":"false");
}

void cfgWrite(const string &name, const string &value) {
	fprintf(writeFile, "%-40s %s\n", name.c_str(), value.c_str());
}
