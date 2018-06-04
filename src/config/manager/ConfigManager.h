#ifndef SRC_CONFIG_CONFIGMANAGER_H_
#define SRC_CONFIG_CONFIGMANAGER_H_

class ConfigManager {
private:
	ConfigManager();
	~ConfigManager();
public:
	static bool read(const char *fileName);
	static bool write(const char *fileName);
	static void print();
};

#endif /* SRC_CONFIG_CONFIGMANAGER_H_ */
