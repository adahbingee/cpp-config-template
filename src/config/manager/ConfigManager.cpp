#include <iostream>
#include <fstream>

#include "../config.h"
#include "ConfigManager.h"
#include "ConfigManagerRead.inc"
#include "ConfigManagerPrint.inc"
#include "ConfigManagerWrite.inc"
#include "ConfigManagerMacro.inc"

using namespace std;

bool ConfigManager::read(const char *fileName) {
	fstream file(fileName, ios::in);

	if ( !file.is_open() ) {
		printf("can't open %s\n", fileName);
		return false;
	}

	while( getline(file, line) ){
		CFG_READ_MACRO
	}
	file.close();

	return true;
}

bool ConfigManager::write(const char *fileName) {
	writeFile = fopen(fileName, "w");
	if ( writeFile == NULL ) {
		printf("can't write %s\n", fileName);
		return false;
	}

	CFG_WRITE_MACRO
	fclose( writeFile );
	return true;
}

void ConfigManager::print() {
	CFG_PRINT_MACRO
}

ConfigManager::ConfigManager() {
}

ConfigManager::~ConfigManager() {
}
