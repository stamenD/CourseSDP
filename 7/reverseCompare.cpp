#include <iostream>
template <class T>
class stack;

template <class T>
class item {
	friend class stack<T>;
private:
	item(T x = 0) {
		inf = x;
		link = NULL;
	}

	T inf;
	item* link;
};


template <class T>
class stack {
public:
	stack(T x);
	stack();
	~stack();
	stack(stack const &);

	stack<T>& operator=(stack const &);

	void push(T const &);
	void pop(T&);
	void top(T&) const;
	bool empty() const;
	void print();

private:
	item<T>* start;
	void delstack();
	void copy(stack const &);
};

// Constructors & operators
template <class T>
stack<T>::stack(T x) {
	start = new item<T>(x);
}

template <class T>
stack<T>::stack() {
	start = NULL;
}

template <class T>
stack<T>::stack(stack const & r) {
	copy(r);
}

template <class T>
stack<T>::~stack() {
	delstack();
}

template <class T>
stack<T>& stack<T>::operator=(stack<T> const & r) {
	if (this != &r) {
		delstack();
		copy(r);
	}
	return *this;
}

// Stack API
template <class T>
void stack<T>::push(T const & x) {
	item<T> * i = new item<T>(x);
	i->link = start;
	start = i;
}

template <class T>
void stack<T>::pop(T & x) {
	if (!start) {
		throw 1;
	}

	item<T>* temp = start;
	start = start->link;

	x = temp->inf;
	delete temp;
}

template <class T>
void stack<T>::top(T& res) const {
	res = start->inf;
}

template <class T>
bool stack<T>::empty() const {
	return start == NULL;
}

template <class T>
void stack<T>::print() {
	T x;
	while (!empty()) {
		pop(x);
		cout << x << " ";
	}
	cout << endl;
}

// Private helpers
template <class T>
void stack<T>::delstack() {
	item<T> * p;
	while (start) {
		p = start;
		start = start->link;
		delete p;
	}
}

template <class T>
void stack<T>::copy(stack const & r) {
	if (r.start) {
		item<T> *p = r.start;
		item<T> *q = NULL;

		start = new item<T>;
		start->inf = p->inf;
		start->link = q;

		q = start;
		p = p->link;
		while (p) {
			q->link = new item<T>;
			q->link->inf = p->inf;
			q->link->link = NULL;

			q = q->link;
			p = p->link;
		}
	}
	else {
		start = NULL;
	}
}


template <class T>
struct elem_link1
{
	T inf;
	elem_link1 *link;
};

template <class T>
class LList
{
public:
	LList();
	~LList();
	LList(LList const&);
	LList& operator=(LList const &);
	void print();
	void IterStart(elem_link1<T>* = NULL);
	elem_link1<T>* Iter();
	void ToEnd(T const &);

	void InsertAfter(elem_link1<T> *, T const &);
	void InsertBefore(elem_link1<T> *, T const &);

	int DeleteAfter(elem_link1<T> *, T &);
	int DeleteBefore(elem_link1<T> *, T &);
	void DeleteElem(elem_link1<T> *, T &);

	bool empty() const;
	int len();
	void concat(LList const&);
	void reverse();

	T operator[](int idx);
private:
	elem_link1<T> *Start, *End, *Current;
	void DeleteList();
	void CopyList(LList<T> const &);
};


template <class T>
LList<T>::LList()
{
	Start = NULL;
	End = NULL;
}

template <class T>
LList<T>::~LList()
{
	DeleteList();
}

template <class T>
LList<T>::LList(LList<T> const& r)
{
	CopyList(r);
}

template <class T>
LList<T>& LList<T>::operator=(LList<T> const & r)
{
	if (this != &r)
	{
		DeleteList();
		CopyList(r);
	}
	return *this;
}

template <class T>
void LList<T>::DeleteList()
{
	elem_link1<T> *p;
	while (Start)
	{
		p = Start;
		Start = Start->link;
		delete p;
	}
	End = NULL;
}

template <class T>
void LList<T>::CopyList(LList<T> const & r)
{
	Start = End = NULL;
	if (r.Start)
	{
		elem_link1<T> *p = r.Start;
		while (p)
		{
			ToEnd(p->inf);
			p = p->link;
		}
	}
}

template <class T>
void LList<T>::print()
{
	IterStart();
	elem_link1<T>* e = Iter();
	while (e)
	{
		cout << e->inf << " ";
		e = Iter();
	}
	cout << endl;
}

template <class T>
void LList<T>::IterStart(elem_link1<T> *p)
{
	if (p) Current = p;
	else Current = Start;
}

template <class T>
elem_link1<T>* LList<T>::Iter()
{
	elem_link1<T> *p = Current;
	if (Current)Current = Current->link;
	return p;
}

template <class T>
void LList<T>::ToEnd(T const & x)
{
	Current = End;
	End = new elem_link1<T>;
	End->inf = x;
	End->link = NULL;
	if (Current) Current->link = End;
	else Start = End;
}

template <class T>
void LList<T>::InsertAfter(elem_link1<T> *p, T const & x)
{
	elem_link1<T> *q = new elem_link1<T>;
	q->inf = x;
	q->link = p->link;
	if (p == End) End = q;
	p->link = q;
}

template <class T>
void LList<T>::InsertBefore(elem_link1<T> * p, T const& x)
{
	elem_link1<T> *q = new elem_link1<T>;
	*q = *p;
	if (p == End) End = q;
	p->inf = x;
	p->link = q;
}

template <class T>
int LList<T>::DeleteAfter(elem_link1<T> *p, T &x)
{
	if (p->link)
	{
		elem_link1<T> *q = p->link;
		x = q->inf;
		p->link = q->link;
		if (q == End) End = p;
		delete q;
		return 1;
	}
	else return 0;
}

template <class T>
void LList<T>::DeleteElem(elem_link1<T> *p, T &x)
{
	if (p == Start)
	{
		x = p->inf;
		if (Start == End) { Start = End = NULL; }
		else Start = Start->link;
		delete p;
	}
	else
	{
		elem_link1<T> *q = Start;
		while (q->link != p)q = q->link;
		DeleteAfter(q, x);
	}
}

template <class T>
int LList<T>::DeleteBefore(elem_link1<T> *p, T &x)
{
	if (p != Start)
	{
		elem_link1<T> *q = Start;
		while (q->link != p)q = q->link;
		DeleteElem(q, x);
		return 1;
	}
	else return 0;
}

template <class T>
bool LList<T>::empty() const
{
	return End == NULL;
}

template <class T>
int LList<T>::len()
{
	int n = 0;
	IterStart();
	elem_link1<T> *p = Iter();
	while (p)
	{
		n++;
		p = Iter();
	}
	return n;
}

template <class T>
void LList<T>::concat(LList<T> const &L)
{
	elem_link1<T> *p = L.Start;
	while (p)
	{
		ToEnd(p->inf);
		p = p->link;
	}
}

template <class T>
void LList<T>::reverse()
{
	LList<T> l;
	IterStart();
	elem_link1<T> *p = Iter();
	if (p)
	{
		l.ToEnd(p->inf);
		p = p->link;
		while (p)
		{
			l.InsertBefore(l.Start, p->inf);
			p = p->link;
		}
	}
	*this = l;
}

#include <cassert>

using namespace std;

template <typename T = int>
struct elem_link2
{
	T inf;
	elem_link2<T> *pred,
		*succ;
};

template <typename T = int>
class DLList
{
public:
	DLList();
	~DLList();
	DLList(const DLList&);
	DLList& operator=(const DLList&);

	bool empty() const;
	void iterStart(elem_link2<T>* = NULL);
	void iterEnd(elem_link2<T>* = NULL);
	elem_link2<T>* iterSucc();
	elem_link2<T>* iterPred();
	void toEnd(const T&);
	void toStart(const T&);
	void deleteElem(elem_link2<T>*, T&);
	void print() const;
	void print_reverse() const;
	int length() const;
private:
	elem_link2<T> *start,
		*end,
		*currentS,
		*currentE;
	void copyList(const DLList&);
	void deleteList();
};

template <typename T>
DLList<T>::DLList()
{
	start = end = NULL;
}

template <typename T>
DLList<T>::~DLList()
{
	deleteList();
}

template <typename T>
DLList<T>::DLList(const DLList<T>& r)
{
	copyList(r);
}

template <typename T>
DLList<T>& DLList<T>::operator=(const DLList<T>& r)
{
	if (this != &r)
	{
		deleteList();
		copyList(r);
	}
	return *this;
}

template <typename T>
void DLList<T>::copyList(const DLList<T>& r)
{
	start = end = NULL;
	elem_link2<T>* p = r.start;
	while (p)
	{
		toEnd(p->inf);
		p = p->succ;
	}
}

template <typename T>
void DLList<T>::deleteList()
{
	elem_link2<T>* p = start;
	while (p)
	{
		start = start->succ;
		delete p;
		p = start;
	}
	end = NULL;
}

template <typename T>
bool DLList<T>::empty() const
{
	return start == NULL;
}

template <typename T>
void DLList<T>::iterStart(elem_link2<T>* p)
{
	if (p) currentS = p;
	else currentS = start;
}
template <typename T>
elem_link2<T>* DLList<T>::iterSucc()
{
	elem_link2<T>* p = currentS;
	if (currentS) currentS = currentS->succ;
	return p;
}

template <typename T>
void DLList<T>::iterEnd(elem_link2<T>* p)
{
	if (p) currentE = p;
	else currentE = end;
}

template <typename T>
elem_link2<T>* DLList<T>::iterPred()
{
	elem_link2<T>* p = currentE;
	if (currentE) currentE = currentE->pred;
	return p;
}

template <typename T>
void DLList<T>::toEnd(const T& x)
{
	elem_link2<T>* p = end;
	end = new elem_link2<T>;
	assert(end != NULL);
	end->inf = x;
	end->succ = NULL;
	if (p) p->succ = end;
	else start = end;
	end->pred = p;
}

template <typename T>
void DLList<T>::toStart(const T& x)
{
	elem_link2<T>* p = start;
	start = new elem_link2<T>;
	assert(start != NULL);
	start->inf = x;
	start->pred = NULL;
	if (p) p->pred = start;
	else end = start;
	start->succ = p;
}

template <typename T>
void DLList<T>::deleteElem(elem_link2<T>* p, T& x)
{
	x = p->inf;
	if (start == end)  start = end = NULL;
	else
		if (p == start)
		{
			start = start->succ;
			start->pred = NULL;
		}
		else
			if (p == end)
			{
				end = p->pred;
				end->succ = NULL;
			}
			else
			{
				p->pred->succ = p->succ;
				p->succ->pred = p->pred;
			}
	delete p;
}

template <typename T>
void DLList<T>::print() const
{
	elem_link2<T>* p = start;
	while (p)
	{
		cout << p->inf << " ";
		p = p->succ;
	}
	cout << endl;
}

template <typename T>
void DLList<T>::print_reverse() const
{
	elem_link2<T>* p = end;
	while (p)
	{
		cout << p->inf << " ";
		p = p->pred;
	}
	cout << endl;
}

template <typename T>
int DLList<T>::length() const
{
	int n = 0;
	elem_link2<T>* p = start;
	while (p)
	{
		n++;
		p = p->succ;
	}
	return n;
}


template <typename T>
T elementAtIndex(LList<T> & list, int n) {
  list.IterStart();

  elem_link1<T>* p;
  while ((p = list.Iter()) && n > 0) {
    n--;
  }

  return p->inf;
}

template <typename T>
void reverse(LList<T> & list) {
  for (int i = list.len() - 1; i >= 0; i--) {
    cout << elementAtIndex(list, i) << " ";
  }
  cout << endl;
}

template <typename T>
void reverse2(LList<T> & list) {
  stack<T> listInReverseOrder;

  list.IterStart();
  elem_link1<T>* p;
  while ((p = list.Iter())) {
    listInReverseOrder.push(p->inf);
  }

  listInReverseOrder.print();
}

template <typename T>
void reverse(DLList<T> & list) {
  list.iterEnd();
  elem_link2<T>* p;
  while ((p = list.iterPred())) {
    cout << p->inf << " ";
  }
  cout << endl;
}

int main() {
  int size = 1000000;

  DLList<int> dlist;
  for (int i = 0; i < size; i++) {
    dlist.toEnd(i);
  }

  LList<int> llist;
  for (int i = 0; i < size; i++) {
    llist.ToEnd(i);
  }

  reverse(llist);  // 1
  reverse2(llist); // 2
  reverse(dlist);  // 3
}
