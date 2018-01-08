#ifndef __DataStorage_H_
#define __DataStorage_H_

#pragma once
#include <mutex>
#include <string>
#include <map>

class DataStorage
{
	std::mutex _mtx;
	static std::map<std::string, std::string> _storage;
	static std::map<std::string, std::string>::iterator it;

public:
	DataStorage();
	~DataStorage();
	void AddData(std::string& Key, std::string& Data);
	std::string GetData(std::string Key);
};

#endif