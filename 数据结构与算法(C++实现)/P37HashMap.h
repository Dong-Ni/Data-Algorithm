#ifndef HASHMAP_H
#define HASHMAP_H

#include <vector>

template<class Key, class Value>
class HashMap//哈希映射
{
public:
	HashMap(int size = 1000): arr(size)
	{
		currentSize = 0;

	}
	void Put(const Key& k, const Value& v)
	{
		int pos =  myhash(k);
		arr[pos] = DataEntry(k,v);
		//++currentSize;
	}
	Value Get(const Key& k)
	{
		int pos = myhash(k);
		if(arr[pos].key == k)
			return arr[pos].value;
		else
			return Value();
	}

	////////哈希函数////////
	unsigned hash(const Key& k) const
	{
		unsigned int hashVal = 0;//初始哈希值，散列值
		const char *keyp = reinterpret_cast<const char *>(&k);//将&k强制转型成字符
	    for(size_t i=0; i<sizeof(Key); i++)
			hashVal = 37*hashVal + keyp[i];//用asc码计算
		return hashVal;
	}
	int myhash(const Key& k) const
	{
		unsigned hashVal = hash(k);
		hashVal %= arr.size();
		return hashVal;
	}
private:
	struct DataEntry
	{
		Key key;
		Value value;
		DataEntry(const Key& k = Key(), const Value& v = Value()):key(k), value(v){}
	};
	std::vector<DataEntry> arr;
	int currentSize;//问：这个currentSize是用来做什么的？？？

};





#endif