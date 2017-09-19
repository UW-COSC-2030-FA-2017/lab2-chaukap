// LinkedList.cpp
// tom bailey   0745  5 oct 2010
// **Edited by Chandler Haukap 9/18/2017
// Definition of methods for the List class.

#include "LinkedList.h"
#include <utility>

List::List() : first_(NULL)
{
}

List::List(const List & other) : first_(clone(other.first_))
{
}

List::~List()
{
	while (!empty())
	{
		removeFirst();
	}
}

const List & List::operator=(const List & other)
{
	// check for list = list
	if (&other != this)
	{
		// clear the current contents of this List
		this -> ~List();
		// and get a copy of other
		first_ = clone(other.first_);
	}

	return *this;
}

bool List::empty() const
{
	return first_ == NULL;
}

void List::insertAsFirst(double x)
{
	first_ = new Node(x, first_);
}

double List::removeFirst()
{
	double item = first_->entry_;
	Node * tempPtr = first_;
	first_ = first_->next_;
	delete tempPtr;
	return item;
}

void List::print(ostream & outfile) const
{
	outfile << "[ ";

	if (!empty())
	{
		// The first entry is printed separately because no comma is needed.

		outfile << first_->entry_;

		Node * ptr = first_->next_;

		while (ptr != NULL)
		{
			outfile << ", " << ptr->entry_;
			ptr = ptr->next_;
		}
	}
	outfile << " ]";

	return;
}

// Iterative version of clone.
// This version walks down the linked structure making a new Node for each double in the structure.
//Node * List::clone(Node * ptr)
//{
//	if (ptr == NULL)
//	{
//		return NULL;
//	}
//
//	Node * first = new Node(ptr->entry_);
//
//	Node * last = first;
//
//	ptr = ptr->next_;
//
//	while (ptr != NULL)
//	{
//		last->next_ = new Node(ptr->entry_);
//		last = last->next_;
//		ptr = ptr->next_;
//	}
//
//	return first;
//}

//// Recursive version of clone.
//// This version handles two cases, a linked structure with no Nodes, and a linked structure with one or more Nodes.
Node * List::clone( Node * ptr ) 
{
   if( ptr == NULL )
   {
	   return NULL;
   }

   return new Node( ptr->entry_, clone( ptr->next_ ) );
}

ostream & operator<<(ostream & outfile, const List & list)
{
	list.print(outfile);
	return outfile;
}

//Determines the size of the list by counting the pointers. 
//The last pointer has a value of NULL
double List::size()  //Created by Chandler Haukap
{
	int counter(0);

	if (first_ == NULL) //the list is empty
	{
		return counter;
	}

	Node* ptr = first_->next_;

	counter++; //guaranteed to have at least one entry
	while (ptr != NULL)
	{
		counter++;
		ptr = ptr->next_;
	}

	return counter;
}

//Inserts new node as the last element of the list.
void List::insertAsLast(double x) //Created by Chandler Haukap
{
	if (first_ == NULL) //if the list is empty
	{
		first_ = new Node(x, NULL);
	}
	else
	{
		Node* ptr = first_; //will find the current last item
		Node* addition = new Node(x, NULL); //will become the new last item

		while (ptr->next_ != NULL) //make sure ptr stops BEFORE becoming NULL
		{
			ptr = ptr->next_;
		}

		ptr->next_ = addition; //change the last address from NULL to the address on the new node
	}
	return;
}