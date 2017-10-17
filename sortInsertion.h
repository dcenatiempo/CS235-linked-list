/***********************************************************************
 * Header:
 *    INSERTION SORT
 * Summary:
 *    This will contain just the prototype for insertionSortTest(). 
 * Author:
 *    Devin Cenatiempo
 ************************************************************************/

#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "node.h"

/***********************************************
 * INSERTION SORT
 * Sort the items in the array
 **********************************************/
template <class T>
void sortInsertion(T array[], int num)
{
   Node <T> *head = new Node<T>(array[0]);
   //loop through all elements in array
   for (int i = 1; i< num; i++)
   {
      Node<T> *temp = head;
      //loop through all elements in linked list (until insert)
      for (int j = 0; j<i; j++)
      {
         if(array[i] < temp->data)
         {
            if (j == 0)
               head = insert(temp, array[i]); // assign new head
            else
               insert(temp, array[i]);
            j = i; // exit inner loop
         }
         else if (!temp->pNext)
            insert(temp, array[i], true);
         temp = temp->pNext;
      }
   }
   // copy linked list to array
   for (int i = 0; i< num; i++)
   {
      array[i] = head->data;
      head = remove(head);
   }
   
}

#endif // INSERTION_SORT_H

