template<typename T>
bool BST<T>::is_balanced_help(const node<T>* root)
{
	if (root)
	{
		return abs(this->height_help(root->left) - this->height_help(root->right)) <= 1 
			&& is_balanced_help(root->left) && is_balanced_help(root->right);
	}
	return true;
}
template<typename T>
bool BST<T>::is_balanced()
{
	return this->is_balanced_help(this->root);
}
template<typename T>
bool BST<T>::is_perfect_balanced_help(const node<T>* root)
{
	if (root)
	{
		return abs(this->size_help(root->left) - this->size_help(root->right)) <= 1
			&& is_perfect_balanced_help(root->left) && is_perfect_balanced_help(root->right);
	}
	return true;
}
template<typename T>
bool BST<T>::is_perfect()
{
	return this->is_perfect_balanced_help(this->root);
}