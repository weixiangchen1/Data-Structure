#pragma once

enum color
{
	RED,
	BLACK
};

template<class T>
struct RBTreeNode
{
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;
	T _data;

	color _col;

	RBTreeNode(const T& data)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _col(RED)
		, _data(data)
	{}
};

template<class T, class Ref, class Ptr>
struct RBTreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef RBTreeIterator<T, Ref, Ptr> Self;

	RBTreeIterator(Node* node)
		:_node(node)
	{}
	
	Ref operator*()
	{
		return _node->_data;
	}

	Ptr operator->()
	{
		return &_node->_data;
	}

	Self& operator++()
	{
		if (_node->_right)
		{
			Node* min = _node->_right;
			while (min->_left)
			{
				min = min->_left;
			}

			_node = min;
		}
		else
		{
			Node* cur = _node;
			Node* parent = _node->_parent;
			while (parent && cur == parent->_right)
			{
				cur = parent;
				parent = parent->_parent;
			}

			_node = parent;
		}

		return *this;
	}

	Self& operator--()
	{
		if (_node->_left)
		{
			Node* max = _node;
			while (max->_right)
			{
				max = max->_right;
			}

			_node = max;
		}
		else
		{
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && cur == parent->_right)
			{
				cur = parent;
				parent = parent->_parent;
			}
			_node = parent;

			return *this;
		}
	}

	bool operator!=(const Self& s) const
	{
		return _node != s._node;
	}

	bool operator==(const Self& s) const
	{
		return _node == s._node;
	}

	Node* _node;
};

template<class K, class T, class KeyOfT>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	typedef RBTreeIterator<T, T&, T*> iterator;
	typedef RBTreeIterator<T, const T&, const T*> const_iterator;
	RBTree()
		:_root(nullptr)
	{}

	RBTree(const RBTree<K, T, KeyOfT>& t)
	{
		_root = Copy(t._root);
	}

	RBTree<K, T, KeyOfT>& operator=(RBTree<K, T, KeyOfT> t)
	{
		swap(_root, t._root);
		return *this;
	}

	~RBTree()
	{
		Destory(_root);
		_root = nullptr;
	}

	iterator begin()
	{
		Node* min = _root;
		while (min && min->_left)
		{
			min = min->_left;
		}

		return iterator(min);
	}

	iterator end()
	{
		return iterator(nullptr);
	}

	iterator Find(const K& key)
	{
		Node* cur = _root;
		KeyOfT kot;

		while (cur)
		{
			if (kot(cur->_data) > key)
			{
				cur = cur->_right;
			}
			else if (kot(cur->_data) < key)
			{
				cur = cur->_left;
			}
			else
			{
				return iterator(cur);
			}
		}

		return end();
	}

	pair<iterator, bool> Insert(const T& data)
	{
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_col = BLACK;
			return make_pair(iterator(_root), true);
		}

		KeyOfT kot;
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (kot(cur->_data) < kot(data))
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (kot(cur->_data) > kot(data))
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return make_pair(iterator(cur), false);
			}
		}

		cur = new Node(data);
		Node* newnode = cur;
		cur->_col = RED;
		if (kot(parent->_data) > kot(data))
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_right = cur;
			cur->_parent = parent;
		}

		// 控制颜色，控制平衡
		while (parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			if (grandfather->_left == parent)
			{
				Node* uncle = grandfather->_right;
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					// 继续向上调整
					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					//      g
					//    p
					//  c
					if (parent->_left == cur)
					{
						RotateR(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					//      g
					//    p
					//      c
					else
					{
						RotateL(parent);
						RotateR(grandfather);
						grandfather->_col = RED;
						cur->_col = BLACK;
					}
				}
			}
			else  // grandfather->_right == parent
			{
				Node* uncle = grandfather->_left;
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					// 继续向上调整
					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					//     g
					//       p
					//         c
					if (parent->_right == cur)
					{
						RotateL(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					//      g
					//		   p
					//      c
					else
					{
						RotateR(parent);
						RotateL(grandfather);
						grandfather->_col = RED;
						cur->_col = BLACK;
					}
					
					break;
				}
			}
		}
		_root->_col = BLACK;
		return make_pair(iterator(newnode), true);
	}

private:
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
		{
			subRL->_parent = parent;
		}

		Node* parentParent = parent->_parent;
		subR->_left = parent;
		parent->_parent = subR;

		if (_root == parent)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (parentParent->_left == parent)
				parentParent->_left = subR;
			else
				parentParent->_right = subR;
			subR->_parent = parentParent;
		}
	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		Node* parentParent = parent->_parent;

		subL->_right = parent;
		parent->_parent = subL;

		if (parent == _root)
		{
			_root = subL;
			_root->_parent = nullptr;
		}
		else
		{
			if (parentParent->_left == parent)
				parentParent->_left = subL;
			else
				parentParent->_right = subL;

			subL->_parent = parentParent;
		}
	}

	Node* Copy(Node* root)
	{
		if (root == nullptr)
			return nullptr;

		Node* newRoot = new Node(root->_data);
		newRoot->_col = root->_col;

		newRoot->_left = Copy(root->_left);
		newRoot->_right = Copy(root->_right);

		if (newRoot->_left)
			newRoot->_left->_parent = newRoot;
		
		if (newRoot->_right)
			newRoot->_right->_parent = newRoot;

		return newRoot;
	}

	void Destory(Node* root)
	{
		if (root == nullptr)
			return;

		Destory(root->_left);
		Destory(root->_right);
		delete root;
	}

private:
	Node* _root;
};

