#pragma once
#include <vector>
#include <string>


template<class K>
struct Hash
{
	size_t operator()(const K& key)
	{
		return key;
	}
};

// 模板全特化
template<>
struct Hash<string>
{
	size_t operator()(const string& s)
	{
		size_t value = 0;
		for (auto e : s)
		{
			value *= 31;
			value += e;
		}

		return value;
	}
};

namespace CloseHash {
	enum Status
	{
		EXIST,
		EMPTY,
		DELETE
	};

	template<class K, class V>
	struct HashData
	{
		pair<K, V> _kv;
		Status _status = EMPTY;
	};

	template<class K, class V, class HashFunc = Hash<K>>
	class HashTable
	{
	public:
		bool Erase(const K& key)
		{
			HashData<K, V>* res = Find(key);
			if (res == nullptr)
			{
				return false;
			}
			else
			{
				--_n;
				res->_status = DELETE;
				return true;
			}
		}

		HashData<K, V>* Find(const K& key)
		{
			if (_tables.size() == 0)
			{
				return nullptr;
			}

			HashFunc hf;
			size_t start = hf(key) % _tables.size();
			size_t i = 0;
			size_t index = start;
			while (_tables[index]._status != EMPTY)
			{
				if (_tables[index]._kv.first == key && _tables[index]._status == EXIST)
				{
					return &_tables[index];
				}

				++i;
				index += i * i;
				index %= _tables.size();
			}

			return nullptr;
		}


		bool Insert(const pair<K, V>& kv)
		{
			HashData<K, V>* res = Find(kv.first);
			if (res)
			{
				return false;
			}

			if (_tables.size() == 0 || _n * 10 / _tables.size() >= 7)
			{
				// 载荷因子 a>=0.7 需要扩容
				int newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				HashTable<K, V, HashFunc> newTable;
				newTable._tables.resize(newSize);

				for (size_t i = 0; i < _tables.size(); ++i)
				{
					if (_tables[i]._status == EXIST)
					{
						newTable.Insert(_tables[i]._kv);
					}
				}

				_tables.swap(newTable._tables);
			}

			HashFunc hf;
			size_t start = hf(kv.first) % _tables.size();
			size_t i = 0;
			size_t index = start;
			while (_tables[index]._status == EXIST)
			{
				++i;
				// index += i;   // 一次探测
				index += i * i;  // 二次探测
				index %= _tables.size();
			}

			_tables[index]._kv = kv;
			_tables[index]._status = EXIST;
			++_n;

			return true;
		}

	private:
		vector<HashData<K, V>> _tables;
		int _n = 0;      // 有效数据的个数
	};

	void TestHashTable()
	{
		HashTable<int, int> HashT;
		int a[] = { 2, 12, 22, 32, 42, 52 };
		for (auto e : a)
		{
			HashT.Insert(make_pair(e, e));
		}
		HashT.Insert(make_pair(21, 21));
		HashT.Insert(make_pair(41, 41));

		Hash<int> hs;
		cout << hs(9) << endl;
		cout << hs(-9) << endl;
		Hash<string> hstr;
		cout << hstr("hello world") << endl;
		cout << hstr("eat") << endl;
		cout << hstr("ate") << endl;

		cout << HashT.Find(12) << endl;
		HashT.Erase(12);
		cout << HashT.Find(12) << endl;
	}
}

namespace LinkHash
{
	template<class K, class V>
	struct HashNode
	{
		pair<K, V> _kv;
		HashNode<K, V>* _next;

		HashNode(const pair<K, V>& kv)
			:_kv(kv)
			, _next(nullptr)
		{}
	};

	template<class K, class V, class HashFunc = Hash<K>>
	class HashTable
	{
		typedef HashNode<K, V> Node;
	public:
		bool Erase(const K& key)
		{
			if (_tables.empty())
			{
				return false;
			}

			HashFunc hf;
			size_t index = hf(key) % _tables.size();
			Node* prev = nullptr;
			Node* cur = _tables[index];
			while (cur)
			{
				if (cur->_kv.first == key)
				{
					if (prev == nullptr)
					{
						_tables[index] = cur->_next;
					}
					else
					{
						prev->_next = cur->_next;
					}

					delete cur;
					--_n;
					return true;
				}
				else
				{
					prev = cur;
					cur = cur->_next;
				}

			}
			return false;
		}

		HashNode<K, V>* Find(const K& key)
		{
			if (_tables.empty())
			{
				return nullptr;
			}

			HashFunc hf;
			size_t index = hf(key) % _tables.size();

			HashNode<K, V>* cur = _tables[index];
			while (cur)
			{
				if (cur->_kv.first == key)
				{
					return cur;
				}
				else
				{
					cur = cur->_next;
				}
			}

			return nullptr;
		}

		bool Insert(const pair<K, V>& kv)
		{
			Node* res = Find(kv.first);
			if (res)
				return false;

			HashFunc hf;
			if (_n == _tables.size())
			{
				// 平衡因子等于1，扩容
				size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				vector<Node*> newTable;
				newTable.resize(newSize);

				for (size_t i = 0; i < _tables.size(); ++i)
				{
					Node* cur = _tables[i];
					while (cur)
					{
						Node* next = cur->_next;
						size_t index = hf(cur->_kv.first) % newTable.size();

						cur->_next = newTable[index];
						newTable[index] = cur;

						cur = next;
					}

					_tables[i] = nullptr;
				}
				_tables.swap(newTable);
			}

			size_t index = hf(kv.first) % _tables.size();
			Node* newnode = new Node(kv);
			// 头插
			newnode->_next = _tables[index];
			_tables[index] = newnode;

			++_n;
			return true;
		}

	private:
		vector<Node*> _tables;
		size_t _n = 0;
	};

	void TestHashTable()
	{
		int a[] = { 4, 24, 14,7,37,27,57,67,34,14,54 };
		HashTable<int, int> ht;
		for (auto e : a)
		{
			ht.Insert(make_pair(e, e));
		}

		ht.Insert(make_pair(84, 84));
		ht.Erase(24);
	}

}