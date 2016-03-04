/*--- LQueue.cpp ----------------------------------------------------------
 
                    Aaron Paul  COSC2436  03/04/16

             This file implements LQueue member functions.
-------------------------------------------------------------------------*/
 
#include <new>
using namespace std;

#include "LQueue.h"

//--- Definition of Queue constructor
Queue::Queue()
: last(0)
{}
//--- Queue class has no copy constructor
// Queue::Queue(const Queue & original){}

//--- Queue class has no assignment operator
// const Queue & Queue::operator=(const Queue & rightHandSide){}



//--- Definition of Queue destructor
Queue::~Queue()
{ 
  // Set pointer to run through the queue
  Queue::NodePointer prev = last,
                     ptr;
  
    do{
      ptr = prev->next;
      delete prev;
      prev = ptr;
    }while (prev != last);
}

//--- Definition of empty()
bool Queue::empty() const{
   return (last == 0);
}

//--- Definition of enqueue()
void Queue::enqueue(const QueueElement & value){
   Queue::NodePointer newptr = new Queue::Node(value);
    if (empty()){
        last = newptr;
        last->next = newptr;
    }else{
       newptr->next = last->next;
       last->next = newptr;
       last = newptr;
   }
}

//--- Definition of display()
void Queue::display(ostream & out) const
{

    if (last->next==0) {
        out<<"Queue Empty"<<endl;
    }else{
        Queue::NodePointer ptr = last;
        do {
            ptr = ptr->next;
            out<< ptr->data<<endl;
            } while (ptr !=last);
    
 
    }
}
//--- Definition of front()
QueueElement Queue::front() const
{
    if (!empty()){
       //Queue::NodePointer frontPtr = last->next;
      return 	(last->data);
    }
    else
   {
      cerr << "*** Queue is empty "
              " -- returning garbage ***\n";
      QueueElement * temp = new(QueueElement);  
      QueueElement garbage = *temp;     // "Garbage" value
      delete temp;
      return garbage;
   }
}

//--- Definition of dequeue()
void Queue::dequeue()
{
   if (!empty())
   {
      Queue::NodePointer ptr = last;
      last = last->next;
      delete ptr;
      if (last == 0)     // queue is now empty
         last = 0;
   }   
   else
      cerr << "*** Queue is empty -- can't remove a value ***\n";
}
