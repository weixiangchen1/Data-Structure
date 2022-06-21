#pragma once

namespace K
{
	template<class K>
	struct BSTreeNode
	{
		BSTreeNode<K>* _left;
		BSTreeNode<K>* _right;
		K _key;

		BSTreeNode(const K& key)
			:_left(nullptr)
			, _right(nullptr)
			, _key(key)
		{}
	};

	template<class K>
	struct BSTree
	{
		typedef BSTreeNode<K> Node;

		BSTree()
			:_root(nullptr)
		{}

		bool Insert(const K& key)
		{
			if (_root == nullptr)
			{
				_root = new Node(key);
				return true;
			}

			Node* parent = nullptr;
			Node* cur = _root;

			while (cur)
			{
				if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else
				{
					return false;
				}
			}

			cur = new Node(key);

			if (parent->_key > key)
			{
				parent->_left = cur;
				return true;
			}
			else
			{
				parent->_right = cur;
				return true;
			}
		}

		bool Find(const K& key)
		{
			Node* cur = _root;

			while (cur)
			{
				if (cur->_key > key)
				{
					cur = cur->_left;
				}
				else if (cur->_key < key)
				{
					cur = cur->_right;
				}
				else
				{
					return true;
				}
			}

			return false;
		}

		bool Erase(const K& key)
		{
			Node* parent = nullptr;
			Node* cur = _root;

			while (cur)
			{
				if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else
				{
					// ÕÒµ½Ä¿±ê½ÚµãÉ¾³ý
					if (cur->_left == nullptr)
					{
						if (parent == nullptr)
						{
							_root = cur->_right;
						}
						else
						{
							if (parent->_left == cur)
							{
								parent->_left = cur->_right;
							}
							else
							{
								parent->_right = cur->_right;
							}
						}

						delete cur;
					}
					else if (cur->_right == nullptr)
					{
						if (parent == nullptr)
						{
							_root = cur->_left;
						}
						else
						{
							if (parent->_left == cur)
							{
								parent->_left = cur->_left;
							}
							else
							{
								parent->_right = cur->_left;
							}
						}

						delete cur;
					}
					else
					{
						Node* minParent = cur;
						Node* min = cur->_right;

						while (min->_left)
						{
							minParent = min;
							min = min->_left;
						}

						cur->_key = min->_key;
						if (minParent->_left == cur)
						{
							minParent->_left = min->_right;
						}
						else
						{
							minParent->_right = min->_right;
						}

						delete min;
					}
					return true;
				}
			}
			return false;
		}

		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}

		void _InOrder(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}

			_InOrder(root->_left);
			cout << root->_key << " ";
			_InOrder(root->_right);
		}

		bool InsertR(const K& key)
		{
			return _InsertR(_root, key);
		}

		// ËÑË÷Ê÷²åÈëµÝ¹éÐ´·¨
		bool _InsertR(Node*& root, const K& key)
		{
			if (root == nullptr)
			{
				root = new Node(key);
				return true;
			}

			if (root->_key > key)
			{
				return _InsertR(root->_left, key);
			}
			else if (root->_key < key)
			{
				return _InsertR(root->_right, key);
			}
			else
			{
				return false;
			}
		}

		bool EraseR(const K& key)
		{
			return _EraseR(_root, key);
		}

		// ËÑË÷Ê÷É¾³ýµÝ¹éÐ´·¨
		bool _EraseR(Node*& root, const K& key)
		{
			if (root == nullptr)
			{
				return false;
			}

			if (root->_key > key)
			{
				return _EraseR(root->_left, key);
			}
			else if (root->_key < key)
			{
				return _EraseR(root->_right, key);
			}
			else
			{
				Node* del = root;

				if (root->_left == nullptr)
				{
					root = root->_right;
				}
				else if (root->_right == nullptr)
				{
					root = root->_left;
				}
				else
				{
					Node* min = root->_right;
					while (min->_left)
					{
						min = min->_left;
					}

					swap(min->_key, root->_key);

					return _EraseR(root->_right, key);
				}

				delete del;
				return true;
			}
		}

		Node* FindR(const K& key)
		{
			return _FindR(_root, key);
		}

		Node* _FindR(Node*& root, const K& key)
		{
			if (root == nullptr)
			{
				return nullptr;
			}

			if (root->_key > key)
			{
				return _FindR(root->_left, key);
			}
			else if (root->_key < key)
			{
				return _FindR(root->_right, key);
			}
			else
			{
				return root;
			}
		}

		Node* _root;
	};

	void TestBSTree()
	{
		BSTree<int> t;
		int a[] = { 2,3,1,8,5,6,5,5,4,4,9,7 };
		for (auto e : a)
		{
			t.InsertR(e);
		}
		//t.InOrder();

		//t.EraseR(7);
		//t.InOrder();

		//t.EraseR(5);
		//t.InOrder();

		//t.EraseR(0);
		//t.InOrder();

		//t.EraseR(1);
		//t.InOrder();

		//for (auto e : a)
		//{
		//	t.EraseR(e);
		//	t.InOrder();
		//}

		BSTreeNode<int>* FindNode = t.FindR(5);
		if (FindNode)
		{
			cout << "Find Success" << endl;
		}
		else
		{
			cout << "Find Failed" << endl;
		}
	}
}

namespace KV
{
	template<class K, class V>
	struct BSTreeNode
	{
		BSTreeNode<K, V>* _left;
		BSTreeNode<K, V>* _right;
		K _key;
		V _value;

		BSTreeNode(const K& key, const V& value)
			:_left(nullptr)
			, _right(nullptr)
			, _key(key)
			, _value(value)
		{}
	};

	template<class K, class V>
	struct BSTree
	{
		typedef BSTreeNode<K, V> Node;

		BSTree()
			:_root(nullptr)
		{}

		bool Insert(const K& key, const V& value)
		{
			if (_root == nullptr)
			{
				_root = new Node(key, value);
				return true;
			}

			Node* parent = nullptr;
			Node* cur = _root;

			while (cur)
			{
				if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else
				{
					return false;
				}
			}

			cur = new Node(key, value);

			if (parent->_key > key)
			{
				parent->_left = cur;
				return true;
			}
			else
			{
				parent->_right = cur;
				return true;
			}
		}

		Node* Find(const K& key)
		{
			Node* cur = _root;

			while (cur)
			{
				if (cur->_key > key)
				{
					cur = cur->_left;
				}
				else if (cur->_key < key)
				{
					cur = cur->_right;
				}
				else
				{
					return cur;
				}
			}

			return nullptr;
		}

		bool Erase(const K& key)
		{
			Node* parent = nullptr;
			Node* cur = _root;

			while (cur)
			{
				if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else
				{
					// ÕÒµ½Ä¿±ê½ÚµãÉ¾³ý
					if (cur->_left == nullptr)
					{
						if (parent == nullptr)
						{
							_root = cur->_right;
						}
						else
						{
							if (parent->_left == cur)
							{
								parent->_left = cur->_right;
							}
							else
							{
								parent->_right = cur->_right;
							}
						}

						delete cur;
					}
					else if (cur->_right == nullptr)
					{
						if (parent == nullptr)
						{
							_root = cur->_left;
						}
						else
						{
							if (parent->_left == cur)
							{
								parent->_left = cur->_left;
							}
							else
							{
								parent->_right = cur->_left;
							}
						}

						delete cur;
					}
					else
					{
						Node* minParent = cur;
						Node* min = cur->_right;

						while (min->_left)
						{
							minParent = min;
							min = min->_left;
						}

						cur->_key = min->_key;
						if (minParent->_left == cur)
						{
							minParent->_left = min->_right;
						}
						else
						{
							minParent->_right = min->_right;
						}

						delete min;
					}
					return true;
				}
			}
			return false;
		}

		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}

		void _InOrder(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}

			_InOrder(root->_left);
			cout << root->_key << ":" << root->_value << endl;
			_InOrder(root->_right);
		}

		bool InsertR(const K& key)
		{
			return _InsertR(_root, key);
		}

		// ËÑË÷Ê÷²åÈëµÝ¹éÐ´·¨
		bool _InsertR(Node*& root, const K& key)
		{
			if (root == nullptr)
			{
				root = new Node(key);
				return true;
			}

			if (root->_key > key)
			{
				return _InsertR(root->_left, key);
			}
			else if (root->_key < key)
			{
				return _InsertR(root->_right, key);
			}
			else
			{
				return false;
			}
		}

		bool EraseR(const K& key)
		{
			return _EraseR(_root, key);
		}

		// ËÑË÷Ê÷É¾³ýµÝ¹éÐ´·¨
		bool _EraseR(Node*& root, const K& key)
		{
			if (root == nullptr)
			{
				return false;
			}

			if (root->_key > key)
			{
				return _EraseR(root->_left, key);
			}
			else if (root->_key < key)
			{
				return _EraseR(root->_right, key);
			}
			else
			{
				Node* del = root;

				if (root->_left == nullptr)
				{
					root = root->_right;
				}
				else if (root->_right == nullptr)
				{
					root = root->_left;
				}
				else
				{
					Node* min = root->_right;
					while (min->_left)
					{
						min = min->_left;
					}

					swap(min->_key, root->_key);

					return _EraseR(root->_right, key);
				}

				delete del;
				return true;
			}
		}

		Node* FindR(const K& key)
		{
			return _FindR(_root, key);
		}

		Node* _FindR(Node*& root, const K& key)
		{
			if (root == nullptr)
			{
				return nullptr;
			}

			if (root->_key > key)
			{
				return _FindR(root->_left, key);
			}
			else if (root->_key < key)
			{
				return _FindR(root->_right, key);
			}
			else
			{
				return root;
			}
		}

		Node* _root;
	};

	void TestBSTree()
	{
		BSTree<string, string> dict;
		dict.Insert("sort", "ÅÅÐò");
		dict.Insert("left", "×ó±ß");
		dict.Insert("right", "ÓÒ±ß");
		dict.Insert("map", "µØÍ¼");

		string str;
		while (cin >> str)
		{
			BSTreeNode<string, string>* ret = dict.Find(str);

			if (ret)
			{
				cout << ret->_value << endl;
			}
			else
			{
				cout << "Find Failed" << endl;
			}
		}
	}

	void TestBSTree01()
	{
		string arr[] = { "Æ»¹û", "Î÷¹Ï", "²ÝÝ®", "Æ»¹û", "Î÷¹Ï", "Æ»¹û", "Æ»¹û", "Î÷¹Ï", "Æ»¹û", "Ïã½¶", "Æ»¹û", "Ïã½¶" };

		BSTree<string, int> countTree;
		for (auto& str : arr)
		{
			auto ret = countTree.Find(str);

			if (ret)
			{
				ret->_value++;
			}
			else
			{
				countTree.Insert(str, 1);
			}
		}

		countTree.InOrder();
	}

}