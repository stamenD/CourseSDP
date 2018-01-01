#include<iostream>
using namespace std;
template<typename T>
struct node
{
	T value;
	node<T> * left, *right;
	node(T v) : value(v), left(nullptr), right(nullptr){}
};

template<typename T>
class BST
{
	node<T>* root;
	void copy_tree(node<T> *&, const node<T>*);
	void delete_tree(node<T>*&);
	bool member_help(const node<T>*, T);
	void insert_help(node<T>*&, T);
	void delete_node_help(node<T>*&, T);
	void print_help(const node<T>*);
public:
	BST();
	BST(T *, int);
	BST(const BST<T>&);
	BST<T>& operator=(const BST<T>&);
	~BST();
	void insert(T);
	void delete_node(T);
	bool member(T);
	void print();
};
template<typename T>
void BST<T>::copy_tree(node<T> *& root, const node<T>* other)
{
	if (other)
	{
		root = new node<T>(other->value);
		this->copy_tree(root->left, other->left);
		this->copy_tree(root->right, other->right);
	}	
}
template<typename T>
void BST<T>::delete_tree(node<T>*& root)
{
	if (root)
	{
		delete_tree(root->left);
		delete_tree(root->right);
		delete root;
		root = nullptr;
	}
}
template<typename T>
BST<T>::BST()
{
	this->root = nullptr;
}
template<typename T>
BST<T>::BST(T * arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		this->insert(arr[i]);
	}
}
template<typename T>
BST<T>::BST(const BST<T>& other)
{
	this->copy_tree(this->root, other.root);
}
template<typename T>
BST<T>& BST<T>::operator=(const BST<T>& other)
{
	if (this != &other)
	{
		this->delete_tree(this->root);
		this->copy_tree(this->root, other.root);
	}
	return *this;
}
template<typename T>
bool BST<T>::member(T value)
{
	return this->member_help(this->root, value);
}
template<typename T>
bool BST<T>::member_help(const node<T>* root, T value)
{
	if (root)
	{
		if (root->value == value) return true;
		return member_help(root->left, value) || member_help(root->right, value);
	}
	return false;
}
template<typename T>
void BST<T>::insert(T value)
{
	this->insert_help(this->root, value);
}
template<typename T>
void BST<T>::insert_help(node<T>*& root, T value)
{
	if (root == nullptr)
	{
		root = new node<T>(value);
	}
	else if (root->value < value) this->insert_help(root->right, value);
	else if (root->value > value) this->insert_help(root->left, value);
}
template<typename T>
void BST<T>::delete_node(T value)
{
	this->delete_node_help(this->root, value);
}
template<typename T>
void BST<T>::delete_node_help(node<T>*& root, T value)
{
	if (root)
	{
		if (root->value < value) this->delete_node_help(root->right, value);
		else if(root->value > value) this->delete_node_help(root->left, value);
		else
		{
			if (root->left && root->right)
			{
				node<T> * smallest_right = root->right;
				while (smallest_right->left) smallest_right = smallest_right->left;
				T temp = root->value;
				root->value = smallest_right->value;
				smallest_right->value = temp;
				this->delete_node_help(root->right, temp);
			}
			else if (root->left && root->right == nullptr)
			{
				node<T> * left_child = root->left;
				delete root;
				root = left_child;
			}
			else if (root->right && root->left == nullptr)
			{
				node<T> * right_child = root->right;
				delete root;
				root = right_child;
			}
			else
			{
				delete root;
				root = nullptr;
			}
		}
	}
}
template<typename T>
void BST<T>::print()
{
	this->print_help(this->root);
}
template<typename T>
void BST<T>::print_help(const node<T>* root)
{
	if (root)
	{
		this->print_help(root->left);
		cout << root->value << " ";
		this->print_help(root->right);
	}
}
template<typename T>
BST<T>::~BST()
{
	this->delete_tree(this->root);
}
int main()
{
	
	system("pause");
	return 0;
}