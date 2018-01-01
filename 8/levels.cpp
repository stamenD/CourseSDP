//print levels
template<typename T>
void BST<T>::print_levels()
{
	for (int i = 1; i <= this->height(); i++)
	{
		this->print_level(i); cout << endl;
		//this->BFS_Kth_level(i); cout << endl;
	}
}
template<typename T>
void BST<T>::print_level(int i)
{
	this->print_level_help(this->root, i);
}
template<typename T>
void BST<T>::print_level_help(const node<T>* root,int i)
{
	
	if (i <= 0) return;
	if (root)
	{
		if (i == 1)
		{
			cout << root->value << " ";
			return;
		}
		this->print_level_help(root->left, i - 1);
		this->print_level_help(root->right, i - 1);
	}
}
//BFS-Kth-level
template<typename T>
void BST<T>::BFS_Kth_level(int level)
{
	queue<node<T>*> q;
	q.push(this->root);
	node<T>* my_node;
	int size = 1;
	int lvl = 1;
	while (!q.empty() && level != lvl){
		my_node = q.front();
		q.pop();
		size--;
		if (my_node->left){
			q.push(my_node->left);
		}
		if (my_node->right){
			q.push(my_node->right);
		}
		if (size == 0){
			lvl++;
			size = q.size();
		}
	}
	int len = q.size();
	for (int i = 0; i < len; i++){
		my_node = q.front();
		q.pop();
		cout << my_node->value << " ";
	}
}