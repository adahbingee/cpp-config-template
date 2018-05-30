#ifndef SRC_CONFIG_CONFIGMANAGER_H_
#define SRC_CONFIG_CONFIGMANAGER_H_

class ConfigManager {
private:
	ConfigManager();
	~ConfigManager();
public:
	static bool read(const char *fileName = "config.txt");
	static bool write(const char *fileName = "config.txt");
	static void print();
};

#endif /* SRC_CONFIG_CONFIGMANAGER_H_ */
