# Linked-List
Create a class encapsulating the notion of a linked-list `Node`. Because a linked-list is bigger than a single `Node`, we cannot put all the necessary linked-list functions in our `Node` class.

Your class should only have two methods: constructors:

- **Constructor:** You will want to have exactly two methods in your `Node` class: a default constructor setting `pNext` to `NULL`, and a non-default constructor which takes a `T` as a parameter.

We will need to write a collection of stand-alone functions to manipulate our linked-list:
- **`copy()`:** Copy a linked-list. Takes a pointer to a `Node` as a parameter and returns a newly created linked-list containing a copy of all the nodes below the list represented by the parameter. This should be a non-member function.
- **`insert()`:** Insert a new `Node` into the current linked-list. The first parameter is the `Node` preceding the new `Node` in the list. The second parameter is the value to be placed in the new `Node`. An optional third parameter is set to `true` if the new element is to be at the head of the list. Please return a pointer to the newly created `Node`. This should be a non-member function.
- **`find()`:** Find the `Node` corresponding to a given passed value from a given linked-list. The first parameter is a pointer to the front of the list, the second is the value to be found. The return value is a pointer to the found node if one exists. This should be a non-member function.
- **`operator<<()`:** Display the contents of a given linked-list.
- **`freeData()`:** Release all the memory contained in a given linked-list. The one parameter is a pointer to the head of the list. This should be a non-member function.
- **`remove()`:** This will remove a given node from the linked list it is attached to. It takes a pointer to a `Node` as a parameter. This is the node to be deleted. It returns a pointer to the previous node in the list if such a node exists. Otherwise, it returns a pointer to the next node.

Unlike all the previous assignments, this will not be a self-contained abstract data-type. We will do that next lesson. Instead, this will just be a linked-list. The client will become aware of all the inner workings of this linked-list.

A few hints that may come in handy when implementing this data-structure:
- A single `Node` is not a linked-list. It should therefore only be aware of itself and the nodes around it. Don't try to make your `Node` class or structure do too much. We will build a `List` class next week to encapsulate the notation of an entire linked-list.
- It is easiest to create the display and free function recursively. Other functions can be done recursively as well.
- Please do not create more methods for your `Node` class than the constructors. All the other functions should be non-member functions.
- Do not forget to remove all the nodes in the linked-list when the object is destroyed.
- You may need more functions or methods for your linked-list than described at the beginning of the assignment.
## Insertion Sort
In addition to the linked-list, you will need to implement an insertion sort. As you may recall from previous semesters, a sort is an algorithm that converts an un-ordered collection of values into an ordered collection of values. By convention, sorts order the collection from least to greatest. In order for this to happen, sort algorithms typically need the collection data-type to support the less-than operator and the assignment operator.

The insertion sort is a sort similar to the method most humans use when ordering a deck of cards or a collection of papers. There are two parts to an insertion sort: the unsorted list and the sorted list. Initially the unsorted list consists of the entire collection and the sorted list is empty. With each iteration, elements are removed from the unsorted list and inserted into the sorted list. This operation is continued until the unsorted list is empty and the sorted list consists of all the elements in the collection.

You are to implement the insertion sort using your linked-list. This will be done because inserting elements into the middle of a linked-list can be done in constant time, unlike array implementations where shifting of the array is required. The input will be an unsorted array of values. Build a sorted linked-list from this array and, when finished, copy the elements from the linked-list back into the input array. The stub-function for the insertion sort function is the following:
```
/***********************************************
* INSERTION SORT
* Sort the elements in the array
**********************************************/
template <class T>
void insertionSort(T array[], int num)
{
   // your code here
}
```
Your insertion sort algorithm must be performed in O(n2) to get full credit.
