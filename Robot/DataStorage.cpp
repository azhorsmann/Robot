#include "DataStorage.h"



DataStorage::DataStorage()
{
}


DataStorage::~DataStorage()
{
}

void DataStorage::AddData(std::string& Key, std::string& Data)
{
	_mtx.lock();

	//if (_storage.find(Key) != _storage.end())
	//	int i = 1; //_storage.erase(Key);

	//_storage[Key] = Data;
	
	_mtx.unlock();
}

std::string DataStorage::GetData(std::string Key)
{
	_mtx.lock();
	
	/*if (_storage.find(Key) != _storage.end())
		return search->first;
	else
		return NULL;
	*/

	return "";

	_mtx.unlock();
}
