#pragma once
#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
	Node(T Value = 0)
	{
		this->value = Value;
	}
	T value;
	Node* Left = nullptr;
	Node* Right = nullptr;
};

template <class T>
class BST
{
	
	Node<T>* Insert(Node<T>* root, T Value)
	{
		if (!root)
		{
			Node<T>* newnode = new Node<T>(Value);
			root = newnode;
			return root;
		}
		else if (Value < root->value)
		{
			root->Left = Insert(root->Left, Value);
		}
		else
		{
			root->Right = Insert(root->Right, Value);
		}

		return root;
	}
	
	Node<T>* Search(Node<T>* root, T item)
	{
		if (!root)
			return NULL;

		if (item == root->value)
		{
			return root;
		}
		else if (item < root->value)
		{
			return Search(root->Left, item);
		}
		else
		{
			return Search(root->Right, item);
		}

	}

	void PreOrder(Node<T>* root)
	{
		if (root)
		{
			cout << root->value << " ";
			PreOrder(root->Left);
			PreOrder(root->Right);
		}

	}

	void InOrder(Node<T>* root)
	{
		if (root)
		{
			InOrder(root->Left);
			cout << root->value << " ";
			InOrder(root->Right);
		}
	}

	void PostOrder(Node<T>* root)
	{
		if (root)
		{
			PostOrder(root->Left);
			PostOrder(root->Right);
			cout << root->value << " ";
		}
	}

public:
	Node<T>* Root;

	BST()
	{
		Root = NULL;
	}

	void Add(T Value)
	{
		Root = Insert(Root, Value);
	}
	
	bool Search(T item)
	{
		Node<T>* Result = Search(Root, item);
		return Result != NULL;
	}

	void Preorder()
	{
		PreOrder(Root);
	}
	void Inorder()
	{
		InOrder(Root);
	}
	void Postorder()
	{
		PostOrder(Root);
	}

	Node<T>* FindMinimum(Node<T>* root)
	{
		if (root)
		{
			if (root->Left == NULL)
			{
				return root;
			}
			else
			{
				return FindMinimum(root->Left);
			}
		}
		return NULL;
	}

	Node<T>* FindMaximum(Node<T>* root)
	{
		if (root)
		{
			if (root->Right == NULL)
			{
				return root;
			}
			else
			{
				return FindMaximum(root->Right);
			}
		}
		return NULL;
	}

	Node<T>* Delete(Node<T>* root, T item)
	{
		if (!root)
			return NULL;

		
		if (item < root->value)
		{
			root->Left = Delete(root->Left,item);
		}
		else if(item > root->value)
		{
			root->Right = Delete(root->Right, item);
		}
		else
		{
			if (!root->Left && !root->Right)
			{
				delete root;
				root = NULL;
				return root;
			}

			if (root->Left == NULL)
			{
				Node<T>* temp = root;
				root = root->Right;
				delete temp;
				return root;
			}
			else if (root->Right == NULL)
			{
				Node<T>* temp = root;
				root = root->Left;
				delete temp;
				return root;
			}
			else
			{
				Node<T>* MaxNodeOnLeft = FindMaximum(root->Left);
				root->value = MaxNodeOnLeft->value;
				root->Left = Delete(root->Left, MaxNodeOnLeft->value);
				return root;
			}

		}
		
		return root;
	}


};
