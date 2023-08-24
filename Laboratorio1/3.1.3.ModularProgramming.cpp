#include <cstdlib> // Include cstdlib for the realloc function
#include <iostream>
using namespace std;

struct Vector {
  int *m_pVect, // Pointer to the buffer
      m_nCount, // Control how many elements are actually used
      m_nMax,   // Control how many are allocated as maximum
      m_nDelta; // To control the growing
};

void Resize(Vector *pThis) {
  pThis->m_pVect = (int *)realloc(
      pThis->m_pVect, sizeof(int) * (pThis->m_nMax + pThis->m_nDelta));
  // The Max has to be increased by delta
  pThis->m_nMax += pThis->m_nDelta;
}

void Insert(Vector *pThis, int elem) {
  if (pThis->m_nCount == pThis->m_nMax) // Verify the overflow
    Resize(pThis); // Resize the vector before inserting elem
  // Insert the element at the end of the sequence
  pThis->m_pVect[pThis->m_nCount++] = elem;
}

int main() {
  Vector sampleVector;
  sampleVector.m_pVect = NULL; // Initialize the pointer to nullptr
  sampleVector.m_nCount = 0;
  sampleVector.m_nMax = 0;
  sampleVector.m_nDelta = 1; // Set an initial value for m_nDelta

  for (int i = 0; i < 100; i++) {
    Insert(&sampleVector, i);
  }

  // Print the elements in the vector
  for (int i = 0; i < sampleVector.m_nCount; i++) {
    cout << sampleVector.m_pVect[i] << " ";
  }
}
