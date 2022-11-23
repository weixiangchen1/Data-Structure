#pragma once
#include "RBTree.h"
namespace cwx
{
	template<class K>
	class set
	{
	public:
		struct SetKeyOfT
		{
			const K& operator()(const K& k)
			{
				return k;
			}
		};
		typedef typename RBTree<K, K, SetKeyOfT>::iterator iterator;

		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}

		pair<iterator, bool> insert(const K& k)
		{
			return _t.Insert(k);
		}

		iterator find(const K& key)
		{
			return _t.Find(key);
		}


	private:
		RBTree<K, K, SetKeyOfT> _t;
	};

	void test_set()
	{
		set<int> s;
		s.insert(1);
		s.insert(3);
		s.insert(2);
		s.insert(6);
		set<int>::iterator it = s.begin();
		while (it != s.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
}