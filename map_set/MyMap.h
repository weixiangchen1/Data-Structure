#pragma once
#include "RBTree.h"
#include <map>
#include <set>
namespace cwx
{
	template<class K, class V>
	class map 
	{
	public:
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};

		typedef typename RBTree<K, pair<K, V>, MapKeyOfT>::iterator iterator;

		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}

		pair<iterator, bool> insert(const pair<K, V>& kv)
		{
			return _t.Insert(kv);
		}

		iterator find(const K& key)
		{
			return _t.Find(key);
		}

		V& operator[](const K& key)
		{
			auto it = _t.Insert(make_pair(key, V()));
			return it.first->second;
		}

	private:
		RBTree<K, pair<K, V>, MapKeyOfT> _t;
	};

	void test_map()
	{
		//map<int, int> m;
		//m.insert(make_pair(1, 1));
		//m.insert(make_pair(3, 3));
		//m.insert(make_pair(2, 2));
		//m.insert(make_pair(7, 7));
		//map<int, int>::iterator it = m.begin();
		//while (it != m.end())
		//{
		//	cout << it->first << ":" << it->second << endl;
		//	++it;
		//}
		//cout << endl;


		map<string, string> dict;
		dict.insert(make_pair("sort", "ÅÅÐò"));
		dict.insert(make_pair("string", "×Ö·û´®"));
		dict.insert(make_pair("map", "µØÍ¼"));
		dict["left"];
		dict["left"] = "×ó±ß";

		auto it = dict.begin();
		while (it != dict.end())
		{
			cout << it->first << ":" << it->second << endl;
			++it;
		}
		cout << endl;
	}
}