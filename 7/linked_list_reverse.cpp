template<typename T>
void LinkedList<T>::reverse()
{
	if(this->length() > 1)
	{
	    this->end = this->start;
		element<T> * right, * middle = this->start, *left = NULL;
		while(middle)
		{
			right = middle->next;
			middle->next = left;
			left = middle;
			middle = right;
		}
		this->start = left;
	}
}