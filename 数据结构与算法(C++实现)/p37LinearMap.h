#ifndef LINEAR_H
#define LINEAR_H

#include <vector>

template<class Key, class Value>
class LinearMap//线性映射，没用的东西，用作学习
{
public:
	LinearMap(int size = 101): arr(size)
	{
		currentSize = 0;

	}
	void Put(const Key& k, const Value& v)
	{
		arr[currentSize] = DataEntry(k, v);
		++currentSize;
	}
	Value Get(const Key& k)
	{
		//线性查找
		for(size_t i=0; i<currentSize; ++i)
		{
			if(arr[i].key == k)
				return arr[i].value;
		}
		return Value();
	}

private:
	struct DataEntry
	{
		Key key;
		Value value;
		DataEntry(const Key& k = Key(), const Value& v = Value()):key(k), value(v){}
	};
	std::vector<DataEntry> arr;
	int currentSize;

};





#endif