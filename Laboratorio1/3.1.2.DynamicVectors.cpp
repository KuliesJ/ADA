#include <iostream>
using namespace std;

int *gpVect = NULL; // Dynamic buffer to save the elements int
int gnCount = 0;        // Counter to know the number of used elements int
int gnMax = 0;          // Variable containing the size of the allocated


void Resize(){
const int delta = 10; // Used to increase the vector size
gpVect = (int *)realloc(gpVect, sizeof(int) * (gnMax + delta));
gnMax += delta; // The Max has to be increased by delta
}

void Insert(int elem){
   if( gnCount == gnMax ) // There is no space at this moment for elem
      Resize(); // Resize the vector before inserting elem
   gpVect[gnCount++] = elem; // Insert the element at the end of the sequence
}

int main() {
  for (int i = 0; i < 10; i++) {
    Insert(i);
  }
  cout << "Aiuda D:";
  return 0;
}
