#ifndef __PROJ_FOUR_AVL_HPP
#define __PROJ_FOUR_AVL_HPP

#include "runtimeexcept.hpp"
#include <string>
#include <stack>
#include <vector>
#include <cmath>
#include <iostream>

template<typename Key, typename Value> class MyAVLTree;

class ElementNotFoundException : public RuntimeException 
{
public:
	ElementNotFoundException(const std::string & err) : RuntimeException(err) {}
};

template<typename Key, typename Value>
class MyAVLNode
{
	friend class MyAVLTree<Key, Value>;
	
private:
	Key key;
	Value val;
	int height;
	MyAVLNode* left;
	MyAVLNode* right;

public:
	MyAVLNode(Key key = Key(), Value val = Value(), MyAVLNode* left = nullptr, MyAVLNode* right = nullptr):key(key), val(val), height(0), left(left), right(right)
	{
		
	}
	~MyAVLNode()
	{
		
	}
};

template<typename Key, typename Value>
class MyAVLTree
{
private:
	// fill in private member data here
	// If you need to declare private functions, do so here too.
	MyAVLNode<Key, Value>* root;
	size_t nodeCount;

public:
	MyAVLTree();
	MyAVLTree(const MyAVLTree<Key, Value> & otherTree);
	// In general, a copy constructor and assignment operator
	// are good things to have.
	// For this quarter, I am not requiring these. 
	//	MyAVLTree(const MyAVLTree & st);
	//	MyAVLTree & operator=(const MyAVLTree & st);


	// The destructor is, however, required. 
	~MyAVLTree();

	// size() returns the number of distinct keys in the tree.
	size_t size() const noexcept;

	// isEmpty() returns true if and only if the tree has no values in it. 
	bool isEmpty() const noexcept;

	// contains() returns true if and only if there
	//  is a (key, value) pair in the tree
	//	that has the given key as its key.
	bool contains(const Key & k) const noexcept; 

	// find returns the value associated with the given key
	// If !contains(k), this will throw an ElementNotFoundException
	// There needs to be a version for const and non-const MyAVLTrees.
	Value & find(const Key & k);
	const Value & find(const Key & k) const;

	// Inserts the given key-value pair into 
	// the tree and performs the AVL re-balance
	// operation, as described in lecture. 
	// If the key already exists in the tree, 
	// you may do as you please (no test cases in
	// the grading script will deal with this situation)
	void insert(const Key & k, const Value & v);

	// in general, a "remove" function would be here
	// It's a little trickier with an AVL tree
	// and I am not requiring it for this quarter's ICS 46.
	// You should still read about the remove operation
	// in your textbook. 

	// The following three functions all return
	// the set of keys in the tree as a standard vector.
	// Each returns them in a different order.
	std::vector<Key> inOrder() const;
	std::vector<Key> preOrder() const;
	std::vector<Key> postOrder() const;

private:
	MyAVLNode<Key, Value>* find(const Key & k, MyAVLNode<Key, Value>* node) const noexcept;
	MyAVLNode<Key, Value>* insert(const Key & k, const Value & v, MyAVLNode<Key, Value>* node);
	void inOrder(std::vector<Key>& path, MyAVLNode<Key, Value>* node) const;
	void preOrder(std::vector<Key>& path, MyAVLNode<Key, Value>* node) const;
	void postOrder(std::vector<Key>& path, MyAVLNode<Key, Value>* node) const;
	void clear();
	void clear(MyAVLNode<Key, Value>* node);
	MyAVLNode<Key, Value>* leftRotation(MyAVLNode<Key, Value>* node);
	MyAVLNode<Key, Value>* rightRotation(MyAVLNode<Key, Value>* node);
	MyAVLNode<Key, Value>* leftRightRotation(MyAVLNode<Key, Value>* node);
	MyAVLNode<Key, Value>* rightLeftRotation(MyAVLNode<Key, Value>* node);
	void setHeight(MyAVLNode<Key, Value>* node);
	int getHeight(MyAVLNode<Key, Value>* node) const;
};


template<typename Key, typename Value>
MyAVLTree<Key,Value>::MyAVLTree():root(nullptr), nodeCount(0)
{

}


template<typename Key, typename Value>
MyAVLTree<Key,Value>::MyAVLTree(const MyAVLTree<Key, Value> & otherTree):nodeCount(otherTree.nodeCount)
{
	if(!otherTree.root)
	{
		root = nullptr;
		return;
	}
	std::stack<MyAVLNode<Key, Value>*> st;
	st.push(otherTree.root);
	while(!st.empty())
	{
		MyAVLNode<Key, Value>* temp = st.top();
		st.pop();
		if(temp) insert(temp->key, temp->val);
		else continue;
		st.push(temp->right);
		st.push(temp->left);
	}
}


template<typename Key, typename Value>
MyAVLTree<Key,Value>::~MyAVLTree()
{
	if(root) clear();
}


template<typename Key, typename Value>
size_t MyAVLTree<Key, Value>::size() const noexcept
{
	return nodeCount;
}


template<typename Key, typename Value>
bool MyAVLTree<Key, Value>::isEmpty() const noexcept
{
	return root == nullptr;
}


template<typename Key, typename Value>
bool MyAVLTree<Key, Value>::contains(const Key &k) const noexcept
{
	if(isEmpty()) return false;
	return find(k, root) != nullptr;
}


template<typename Key, typename Value>
Value & MyAVLTree<Key, Value>::find(const Key & k)
{
	if(isEmpty()) throw ElementNotFoundException("TREE IS EMPTY");
	MyAVLNode<Key, Value>* result = find(k, root);
	if(result) return result->val;
	else throw ElementNotFoundException("KEY IS NOT IN THE TREE");
}


template<typename Key, typename Value>
const Value & MyAVLTree<Key, Value>::find(const Key & k) const
{
	if(isEmpty()) throw ElementNotFoundException("TREE IS EMPTY");
	const MyAVLNode<Key, Value>* result = find(k, root);
	if(result) return result->val;
	else throw ElementNotFoundException("KEY IS NOT IN THE TREE");
}


template<typename Key, typename Value>
void MyAVLTree<Key, Value>::insert(const Key & k, const Value & v)
{
	if(isEmpty())
	{
		root = new MyAVLNode<Key, Value>(k, v);
		++nodeCount;
	}
	else 
	{
		root = insert(k, v, root);
	}
}

template<typename Key, typename Value>
std::vector<Key> MyAVLTree<Key, Value>::inOrder() const
{
	if(isEmpty()) return {};
	std::vector<Key> foo;
	inOrder(foo, root);
	return foo; 
}


template<typename Key, typename Value>
std::vector<Key> MyAVLTree<Key, Value>::preOrder() const
{
	if(isEmpty()) return {};
	std::vector<Key> foo;
	preOrder(foo, root);
	return foo; 
}


template<typename Key, typename Value>
std::vector<Key> MyAVLTree<Key, Value>::postOrder() const
{
	if(isEmpty()) return {};
	std::vector<Key> foo;
	postOrder(foo, root);
	return foo; 
}


template<typename Key, typename Value>
MyAVLNode<Key, Value>* MyAVLTree<Key, Value>::find(const Key & k, MyAVLNode<Key, Value>* node) const noexcept
{
	if(!node) return nullptr;
	if(node->key < k) return find(k, node->right);
	else if(k < node->key) return find(k, node->left);
	else return node;
}


template<typename Key, typename Value>
MyAVLNode<Key, Value>* MyAVLTree<Key, Value>::insert(const Key & k, const Value & v, MyAVLNode<Key, Value>* node)
{
	if(node == nullptr)
	{
		node = new MyAVLNode<Key, Value>(k, v);
		++nodeCount;
		return node;
	}
	if(k < node->key) 
		node->left = insert(k, v, node->left);
	else if(node->key < k) 
		node->right = insert(k, v, node->right);
	else 
		node->val = v;
	setHeight(node);
	int balanced = getHeight(node->left) - getHeight(node->right);
	if(balanced > 1)
	{
		if(k < node->left->key) 
			return rightRotation(node);
		else 
			return leftRightRotation(node);
	}
	else if(balanced < -1)
	{
		if(node->right->key < k)
			return leftRotation(node);
		else  
			return rightLeftRotation(node);
	}
	return node;
}


template<typename Key, typename Value>
void MyAVLTree<Key, Value>::inOrder(std::vector<Key>& path, MyAVLNode<Key, Value>* node) const
{
	if(!node) return;
	inOrder(path, node->left);
	path.push_back(node->key);
	inOrder(path, node->right);
}


template<typename Key, typename Value>
void MyAVLTree<Key, Value>::preOrder(std::vector<Key>& path, MyAVLNode<Key, Value>* node) const
{
	if(!node) return;
	path.push_back(node->key);
	preOrder(path, node->left);
	preOrder(path, node->right);
}


template<typename Key, typename Value>
void MyAVLTree<Key, Value>::postOrder(std::vector<Key>& path, MyAVLNode<Key, Value>* node) const
{
	if(!node) return;
	postOrder(path, node->left);
	postOrder(path, node->right);
	path.push_back(node->key);
}


template<typename Key, typename Value>
void MyAVLTree<Key, Value>::clear()
{
	clear(root);
	nodeCount = 0;
}


template<typename Key, typename Value>
void MyAVLTree<Key, Value>::clear(MyAVLNode<Key, Value>* node)
{
	if(!node) return;
	clear(node->left);
	clear(node->right);
	delete node;
	node = nullptr;
}

template<typename Key, typename Value>
int MyAVLTree<Key, Value>::getHeight(MyAVLNode<Key, Value>* node) const
{
	return node == nullptr ? -1 : node->height;
}

template<typename Key, typename Value>
MyAVLNode<Key, Value>* MyAVLTree<Key, Value>::leftRotation(MyAVLNode<Key, Value>* node)
{
	MyAVLNode<Key, Value>* temp = node->right;
	node->right = temp->left;
	temp->left = node;
	setHeight(node);
	setHeight(temp);
	return temp;
}


template<typename Key, typename Value>
MyAVLNode<Key, Value>* MyAVLTree<Key, Value>::rightRotation(MyAVLNode<Key, Value>* node)
{
	MyAVLNode<Key, Value>* temp = node->left;
	node->left = temp->right;
	temp->right = node;
	setHeight(node);
	setHeight(temp);
	return temp;
}


template<typename Key, typename Value>
MyAVLNode<Key, Value>* MyAVLTree<Key, Value>::leftRightRotation(MyAVLNode<Key, Value>* node)
{
	node->left = leftRotation(node->left);
	return rightRotation(node);
}


template<typename Key, typename Value>
MyAVLNode<Key, Value>* MyAVLTree<Key, Value>::rightLeftRotation(MyAVLNode<Key, Value>* node)
{
	node->right = rightRotation(node->right);
	return leftRotation(node);
}


template<typename Key, typename Value>
void MyAVLTree<Key, Value>::setHeight(MyAVLNode<Key, Value>* node)
{
	node->height = std::max(getHeight(node->left), getHeight(node->right))+1;
}

#endif 