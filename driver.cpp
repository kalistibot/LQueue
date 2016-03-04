


/*---------------------------------------------------------------------

    Aaron Paul  COSC2436  03/04/16
    Driver program to test the LQueue class.
  ----------------------------------------------------------------------*/

#include <iostream>
using namespace std;
	
#include "LQueue.h"

void print(Queue &q) //pass by reference avoids copy constructor
{ q.display(cout); }

int main()
{
   Queue q1;
   cout << "Queue created.  Empty? " << boolalpha << q1.empty() << endl;

   cout << "How many elements to add to the queue? ";
   int numItems;
   cin >> numItems;
   for (int i = 1; i <= numItems; i++) 
      q1.enqueue(100*i);

   cout << "Contents of queue q1 (via  print):\n";
   
      print(q1); cout << endl;
}