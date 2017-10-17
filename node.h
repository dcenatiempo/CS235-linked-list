/***********************************************************************
 * Header:
 *    NODE
 * Summary:
 *    This data type holds a single piece of data and points to another
 *    node, creating an ordered chain of nodes containing data.
 * Author
 *    Devin Cenatiempo
 ************************************************************************/

#ifndef node_h
#define node_h
#include <iostream>

using namespace std;

/************************************************
   * NODE
   * Holds data and points to another node.
   ***********************************************/
template <class T>
class Node
{
   // Nodes do not keep anything private - similarly to most millennials on Facebook.
      
public:
   // data
   T data;           // a single piece of data
   Node <T> * pNext; // a pointer to the next node
   Node <T> * pPrev; // a pointer to the previous node
      
   // constructors
   Node();                       // default constructor
   Node(const T & data);         // non-default constructor
   Node(const Node <T> * node);  // copy constructor
   
   // operators
   Node <T> & operator = (const Node <T> & rhs); // Assignment
};
   
/****************************************
 * Node : Default Constructor
 * Create a new node which holds nothing.
 * ***************************************/
template <class T>
Node <T> :: Node()
{
   pNext = NULL;
   pPrev = NULL;
}
   
/****************************************
 * Node : Non-Default Constructor
 * Create a new node which holds a given value.
 * ***************************************/
template <class T>
Node <T> :: Node(const T & data)
{
   this->data = data;
   pNext = NULL;
   pPrev = NULL;
}
   
/****************************************
 * Node : Copy Constructor
 * Create a new node which holds
 * the same values as a given node.
 * ***************************************/
template <class T>
Node <T> :: Node(const Node <T> * node)
{
   this->data = node->data;
   pNext = node->pNext;
   pPrev = node->pPrev;
}

/******************************************
 * Node : Assignment Operator - Constant
 * ****************************************/
template <class T>
Node <T> & Node <T> :: operator = (const Node <T> & rhs)
{
   data  = rhs->data;
   pNext = rhs->pNext;
   pPrev = rhs->pPrev;
   
   return *this;
}


/******************************************
 * insert()
 * Insert a new Node into the current linked-list. The first parameter is the
 * Node preceding the new Node in the list. The second parameter is the value
 * to be placed in the new Node. An optional third parameter is set to true if
 * the new element is to be at the head of the list. Please return a pointer to
 * the newly created Node. This should be a non-member function.
 * ****************************************/
template <class T>
Node <T> * insert(Node <T> * pCurrent, // our new node will be before this node
                  const T & t,         // value that will reside in the new node
                  bool after = false)  // by default, we insert before
{
   Node<T> *pNew = new Node<T> (t);
   
   if (pCurrent && after == false)
   {
      pNew->pNext = pCurrent;
      pNew->pPrev = pCurrent->pPrev;
      pCurrent->pPrev = pNew;
      if (pNew->pPrev)
         pNew->pPrev->pNext = pNew;
   }
   if (pCurrent && after == true)
   {
      pNew->pPrev = pCurrent;
      pNew->pNext = pCurrent->pNext;
      pCurrent->pNext = pNew;
      if (pNew->pNext)
         pNew->pNext->pPrev = pNew;
   }
   return pNew;
}
/****************************************
 * copy()
 * Copy a linked-list. Takes a pointer to a Node as a parameter and returns a
 * newly created linked-list containing a copy of all the nodes below the list
 * represented by the parameter. This should be a non-member function.
 * ***************************************/
template <class T>
Node <T> * copy(const Node <T> * pSource) throw (const char *)
{
   Node<T> *pNewHead = new Node<T>(pSource->data);
   const Node<T> *pSrc = pSource;
   Node<T> *pCopy = pNewHead;
   
   pSrc = pSrc->pNext;
   while (pSrc)
   {
      pCopy = insert(pCopy, pSrc->data, true);
      pSrc = pSrc->pNext;
   }
   return pNewHead;
}

/******************************************
 * find()
 * Find the Node corresponding to a given passed value from a given linked-list.
 * The first parameter is a pointer to the front of the list, the second is the
 * value to be found. The return value is a pointer to the found node if one
 * exists. This should be a non-member function.
 * ****************************************/
template <class T>
Node <T> * find(Node <T> * pHead, const T & t)
{
   for (Node<T> *p = pHead; p; p = p->pNext)
   {
      if (p->data == t)
         return p;
   }
   return NULL;
}

/******************************************
 * operator<<()
 * Display the contents of a given linked-list.
 * ****************************************/
template <class T>
ostream & operator << (ostream & out, const Node <T> *rhs)
{

   for (const Node<T> *it = rhs; it; it = it->pNext)
   {
      out << it->data;
      if (it->pNext)
         out << ", ";
   }
   return out;
}
/******************************************
 * freeData()
 * Release all the memory contained in a given linked-list. The one parameter
 * is a pointer to the head of the list. This should be a non-member function.
 * ****************************************/
template <class T>
void freeData(Node <T> * & pHead)
{
   while (pHead)
   {
      Node<T> *pDelete = pHead;
      pHead = pHead->pNext;
      delete pDelete;
   }
}

/******************************************
 * remove()
 * This will remove a given node from the linked list it is attached to. It
 * takes a pointer to a Node as a parameter. This is the node to be deleted.
 * It returns a pointer to the previous node in the list if such a node exists.
 * Otherwise, it returns a pointer to the next node.
 * ****************************************/
template <class T>
Node <T> * remove (const Node <T> * pRemove)
{
   Node<T> *pReturn = new Node<T>;
   if (!pRemove)
      return NULL;
   
   if (pRemove->pPrev)
      pRemove->pPrev->pNext = pRemove->pNext;
   if (pRemove->pNext)
      pRemove->pNext->pPrev = pRemove->pPrev;
   if (pRemove->pPrev)
      pReturn = pRemove->pPrev;
   else
      pReturn = pRemove->pNext;
   
   delete pRemove;
   return pReturn;
}

#endif /* node_h */
