#include <string>
#include <regex>
#include <sstream>

using namespace std;

string line;         // read line buffer
#define CFG_READ(x) cfgRead(line, #x, x)

inline static void parse(const string &line, string &name, string &value) {
	regex pattern("\\s?(\\w+)\\s+(.*)\\s?");
	smatch match; // match result

	if ( regex_match(line, match, pattern) ) {
		name  = match[1];
		value = match[2];
		// trim trailing spaces
		size_t endpos = value.find_last_not_of(" \t");
		if( string::npos != endpos ) {
			value = value.substr( 0, endpos+1 );
		}
	}
}

inline static void parseArray(const string &in, vector<string> &element) {
	smatch match;
	regex pattern("([0-9-.A-Za-z]+)");
	string str = in;
	element.clear();

	while ( regex_search (str, match, pattern) ) {
		//cout << match[1] << endl;
		element.push_back( match[1].str() );
		str = match.suffix().str();
	}
}

inline static bool matchBool(const string &in) {
	// match case insensitive string
	regex patTrue ("\\s*true\\s*" , regex_constants::icase);
	regex patFalse("\\s*false\\s*", regex_constants::icase);
	// match number 0 or 1
	regex patNum  ("\\s*[01]\\s*");
	smatch match;
	if ( regex_match(in, match, patTrue) ) {         // match true
		return true;
	} else if ( regex_match(in, match, patFalse) ) { // match false
		return false;
	} else if ( regex_match(in, match, patNum) ) {   // match number
		return atoi( in.c_str() );
	}
	return false;
}

template <size_t size>
bool cfgRead(const string &line, const string &varName, int (&var)[size]) {
	string lineVarName;  // variable name buffer
	string lineVarValue; // variable value buffer
	parse(line, lineVarName, lineVarValue);

	vector<string> arr;
	parseArray(lineVarValue, arr);

	if ( lineVarName == varName ) {
		for (size_t i = 0; i < size; ++i) {
			var[i] = atoi(arr[i].c_str());
		}
		return true;
	} else {
		return false;
	}
}

template <size_t size>
bool cfgRead(const string &line, const string &varName, float (&var)[size]) {
	string lineVarName;  // variable name buffer
	string lineVarValue; // variable value buffer
	parse(line, lineVarName, lineVarValue);

	vector<string> arr;
	parseArray(lineVarValue, arr);

	if ( lineVarName == varName ) {
		for (size_t i = 0; i < size; ++i) {
			var[i] = atof(arr[i].c_str());
		}
		return true;
	} else {
		return false;
	}
}

template <size_t size>
bool cfgRead(const string &line, const string &varName, double (&var)[size]) {
	string lineVarName;  // variable name buffer
	string lineVarValue; // variable value buffer
	parse(line, lineVarName, lineVarValue);

	vector<string> arr;
	parseArray(lineVarValue, arr);

	if ( lineVarName == varName ) {
		for (size_t i = 0; i < size; ++i) {
			var[i] = atof(arr[i].c_str());
		}
		return true;
	} else {
		return false;
	}
}

template <size_t size>
bool cfgRead(const string &line, const string &varName, bool (&var)[size]) {
	string lineVarName;  // variable name buffer
	string lineVarValue; // variable value buffer
	parse(line, lineVarName, lineVarValue);

	vector<string> arr;
	parseArray(lineVarValue, arr);

	if ( lineVarName == varName ) {
		for (size_t i = 0; i < size; ++i) {
			var[i] = matchBool( arr[i] );
		}
		return true;
	} else {
		return false;
	}

}

template <size_t size>
bool cfgRead(const string &line, const string &varName, char (&var)[size]) {
	string lineVarName;  // variable name buffer
	string lineVarValue; // variable value buffer
	parse(line, lineVarName, lineVarValue);

	if ( lineVarName == varName ) {
		snprintf(var, size, "%s", lineVarValue.c_str());
		return true;
	} else {
		return false;
	}
}

bool cfgRead(const string &line, const string &varName, int &var) {
	string lineVarName;  // variable name buffer
	string lineVarValue; // variable value buffer
	parse(line, lineVarName, lineVarValue);
	if ( lineVarName == varName ) {
		var = atoi( lineVarValue.c_str() );
		return true;
	} else {
		return false;
	}
}

bool cfgRead(const string &line, const string &varName, float &var) {
	string lineVarName;  // variable name buffer
	string lineVarValue; // variable value buffer
	parse(line, lineVarName, lineVarValue);
	if ( lineVarName == varName ) {
		var = atof( lineVarValue.c_str() );
		return true;
	} else {
		return false;
	}
}

bool cfgRead(const string &line, const string &varName, double &var) {
	string lineVarName;  // variable name buffer
	string lineVarValue; // variable value buffer
	parse(line, lineVarName, lineVarValue);
	if ( lineVarName == varName ) {
		var = atof( lineVarValue.c_str() );
		return true;
	} else {
		return false;
	}
}

bool cfgRead(const string &line, const string &varName, bool &var) {
	string lineVarName;  // variable name buffer
	string lineVarValue; // variable value buffer
	parse(line, lineVarName, lineVarValue);
	if ( lineVarName == varName ) {
		var = matchBool( lineVarValue );
		return true;
	} else {
		return false;
	}
}

bool cfgRead(const string &line, const string &varName, string &var) {
	string lineVarName;  // variable name buffer
	string lineVarValue; // variable value buffer
	parse(line, lineVarName, lineVarValue);
	if ( lineVarName == varName ) {
		var = lineVarValue;
		return true;
	} else {
		return false;
	}
}
