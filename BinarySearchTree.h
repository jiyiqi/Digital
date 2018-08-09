#include <iostream>
#include<list>
using namespace std;

template <class T>
struct BinaryNode
{
	T				element;
	BinaryNode		*left;
	BinaryNode		*right;

	BinaryNode(T& theElement,BinaryNode *lt,BinaryNode *rt)
		:element(theElement),left(lt),right(rt)
	{}
};

template <class T>
class BinarySearchTree
{
private:
	BinaryNode<T>			*root;
public:
	BinarySearchTree();
	const T& findMin() ;
	bool contains(T& x) ;

	void insert( T& x);
	void remove(T& x);
	void printTreeInPrev();
	void printTree();
private:
	void insert( T& x, BinaryNode<T>* &t) ;
	void remove( T& x, BinaryNode<T>* &t) ;
	BinaryNode<T>* findMin( BinaryNode<T>* t) ;
	bool contains(T& x, BinaryNode<T>* t) ;
	void printTreeInPrev(BinaryNode<T>* t) ;
	void printTree(BinaryNode<T>* t);
};

template <class T>
BinarySearchTree<T>::BinarySearchTree()
{
	root = NULL;
}

template <class T>
bool  BinarySearchTree<T>::contains( T& x)
{
	return contains(x, root);
}

template <class T>
bool BinarySearchTree<T>::contains( T& x,  BinaryNode<T>* t) 
{
	if (!t)
		return false;
	else if (x < t->element)
		return contains(x, t->left);
	else if (x > t->element)
		return contains(x, t->right);
	else
		return true;
}

template <class T>
const T& BinarySearchTree<T>::findMin() 
{
	return findMin(root)->element;
}

template <class T>
BinaryNode<T>* BinarySearchTree<T>::findMin( BinaryNode<T>* t) 
{

	if (!t)
		return NULL;
	if (t->left == NULL)
		return t;
	else
		return findMin(t->left);
}

template <class T>
void BinarySearchTree<T>:: insert( T& x)
{
	insert(x, root);
}

template <class T>
void BinarySearchTree<T>::insert( T& x, BinaryNode<T>* &t) 
{
	if (t == NULL)
		t = new BinaryNode<T>(x, NULL, NULL);
	else if (x < t->element)
		insert(x, t->left);
	else if (x > t->element)
		insert(x, t->right);
}

template <class T>
void BinarySearchTree<T>::remove(T& x)
{
	return remove(x, root);
}

template <class T>
void BinarySearchTree<T>::remove(T& x, BinaryNode<T>* &t) 
{
	if (t == NULL)
		return;
	if (x < t->element)
		remove(x, t->left);
	else if (x > t->element)
		remove (x, t->right);
	else 
	{
		if (t->left != NULL &&t->right != NULL)
		{
			t->element = findMin(t->right)->element;
			remove(t->element, t->right);
		}
		else
		{
			BinaryNode<T> *oldNode = t;
			t = (t->left != NULL) ? t->left : t->right;
			delete oldNode;
		}
	}
}

template <class T>
void BinarySearchTree<T>:: printTreeInPrev( )
{
	printTreeInPrev(root);
}
template <class T>
void BinarySearchTree<T>::printTreeInPrev(BinaryNode<T>* t) 
{
	if (t)
	{
		cout << t->element;
		cout<<" ";
		printTreeInPrev(t->left);
		printTreeInPrev(t->right);
	}
}

template <class T>
void BinarySearchTree<T>:: printTree()
{
	printTree(root);
}
template <class T>
void BinarySearchTree<T>::printTree(BinaryNode<T>* t) 
{
	list<BinaryNode<T>* >q;
    if(t)
		q.push_back(t);
    while(!q.empty())
    {
        t=q.front();
        q.pop_front();
        cout<<t->element;
        if(t->left)
		{  q.push_back(t->left);
		}
		else
		{
		t->left=0;
		}
        if(t->right)
            q.push_back(t->right);
		else
		{
			t->right=0;
		}
    }
	cout<<endl;
}
