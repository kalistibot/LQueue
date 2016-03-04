
/*-- LQueue.h -------------------------------------------------------------
Aaron Paul  COSC2436  03/04/16
 
  This header file defines a Queue data type using a Circular Linked List.
  Basic operations:
    constructor:  Constructs an empty queue
    empty:        Checks if a queue is empty
    enqueue:      Modifies a queue by adding a value at the back
    front:        Accesses the top queue value; leaves queue unchanged
    dequeue:      Modifies queue by removing the value at the front
    display:      Displays all the queue elements
    There are no assignment or copy construtors.  These operations are not permitted
    Note: Execution terminates if memory isn't available for a queue element.
---------------------------------------------------------------------------*/

#include <iostream>

#ifndef LQUEUE
#define LQUEUE

typedef int QueueElement;

class Queue
{
 public:
 /***** Function Members *****/
 /***** Constructors *****/

  Queue();
  /*-----------------------------------------------------------------------
    Construct a Queue object.

    Precondition:  None.
    Postcondition: An empty Queue object has been constructed.
        (myFront and myBack are initialized to null pointers).
  -----------------------------------------------------------------------*/

  Queue(const Queue & original);
    // the Queue class has no copy constructor
    // Operations that require a copy constructor are not allowed
    
 /***** Destructor *****/
  ~Queue(); 
  /*-----------------------------------------------------------------------
    Class destructor 

    Precondition:  None.
    Postcondition: The linked list in the queue has been deallocated.
  -----------------------------------------------------------------------*/

 /***** Assignment *****/
 const Queue & operator= (const Queue & rightHandSide);
    // the Queue class has no assignment operator
    // Assigning a Queue object to another Queue object is not allowed

  bool empty() const;
  /*-----------------------------------------------------------------------
    Check if queue is empty.

    Precondition:  None.
    Postcondition: Returns true if queue is empty and false otherwise.
  -----------------------------------------------------------------------*/

  void enqueue(const QueueElement & value);
  /*-----------------------------------------------------------------------
    Add a value to a queue.

    Precondition:  value is to be added to this queue.
    Postcondition: value is added at back of queue.               
  -----------------------------------------------------------------------*/

  void display(ostream & out) const;
  /*-----------------------------------------------------------------------
    Display values stored in the queue.

    Precondition:  ostream out is open.
    Postcondition: Queue's contents, from front to back, have been 
        output to out.
  -----------------------------------------------------------------------*/

  QueueElement front() const;
  /*-----------------------------------------------------------------------
    Retrieve value at front of queue (if any).

    Precondition:  Queue is nonempty.
    Postcondition: Value at front of queue is returned, unless the queue 
        is empty; in that case, an error message is displayed and a 
        "garbage value" is returned.
  -----------------------------------------------------------------------*/

  void dequeue();
  /*-----------------------------------------------------------------------
    Remove value at front of queue (if any).

    Precondition:  Queue is nonempty.
    Postcondition: Value at front of queue has been removed, unless
        queue is empty; in that case, an error message is displayed 
        and execution allowed to proceed.
  -----------------------------------------------------------------------*/

 private:
    

   /*** Node class ***/
   class Node
   {
    public:
       QueueElement data;
       Node * next;
      //--- Node constructor
       Node(QueueElement value, Node * link =0)
      /*-------------------------------------------------------------------
        Precondition:  value and link are received
        Postcondition: A Node has been constructed with value in its 
            data part and its next part set to link (default 0).
       ------------------------------------------------------------------*/
      { data = value; next = 0; }

  };
    typedef Node * NodePointer;
    /***** Data Members *****/
    NodePointer last;      // pointer to last node of queue
    

}; // end of class declaration

#endif
