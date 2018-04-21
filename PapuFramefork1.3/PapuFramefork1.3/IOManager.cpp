#include "IOManager.h"
#include <fstream>


bool IOManager::readFileBuffer(string &filePath,
	vector<unsigned char>& buffer) {
	ifstream file(filePath, ios::binary);

	if (file.fail()) {
		perror(filePath.c_str());
		return false;
	}
	file.seekg(0, ios::end);
	int fileSize = file.tellg();
	file.seekg(0, ios::beg);

	buffer.resize(fileSize);
	file.read((char*)&(buffer[0]), fileSize);
	file.close();
	return true;
	
}