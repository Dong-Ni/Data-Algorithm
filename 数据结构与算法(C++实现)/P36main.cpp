#include <iostream>
#include <map>//映射(也叫字典),二叉树映射，不是哈希映射
#include <hash_map>//！！！！！！！！！！！！哈希映射
#include <string>
#include "LinearMap.h"
#include "HashMap.h"



using namespace std;

int main()
{
	cout<< "二叉树（红黑树）映射：" << endl;
	map<string ,int> m;
	m["Bill"] = 98;
	m["Tom"] = 67;
	m["Mary"] = 100;
	//...继续保存，保存了很多，100万个，1000万个
	cout<< m["Tom"] << endl;


	//数组的优点
	cout<< "数组的优点。。。" << endl;
	int a[100000];
	for(int i=0; i<100000; ++i)
		a[i] = i % 100;
	//for(int i=0; i<100000; ++i)
	//	cout<< a[i] << endl;

	cout<< a[8] << endl;
	cout<< a[18] << endl;
	cout<< a[98756] << endl;


	//一个没用的，只供学习的线性映射
	LinearMap<string, int> lm;
	lm.Put("Bill", 99);
	lm.Put("Tom", 88);
	lm.Put("Mary", 77);
	//继续put很多数据
	cout<< "LinearMap: " << lm.Get("Tom") << endl;


	//我的哈希映射
	cout<< endl << "我的哈希映射: " << endl;
	HashMap<string, int> myHMap;

	cout<< myHMap.hash("Bill") << endl;
	cout<< myHMap.myhash("Bill") << endl;
	myHMap.Put("Bill", 999);
	myHMap.Put("Tom", 888);
	myHMap.Put("Mary", 777);
	cout<< myHMap.Get("Tom") << endl;
	cout<< myHMap.Get("Bill") << endl;

	//使用c++做好的哈希映射
	cout<< "使用c做好的哈希映射hash_map" << endl;
	hash_map<string, int> hm;
	hm["Bill"] = 12;
	hm["Tom"] = 22;
	hm["Mary"] = 32;
	cout<< hm["Tom"] << endl;

	return 0;
}