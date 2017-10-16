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

namespace custom
{
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
      Node();                    //     default constructor
      Node(const T & data);      // non-default constructor
      Node(const Node <T> * node); //        copy constructor
      
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
}; // end custom namespace
#endif /* node_h */
