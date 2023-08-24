#include <iostream>
#include <cstdlib> // Include cstdlib for the realloc function
using namespace std;

class CVector {
private:
  int *m_pVect; // Pointer to the buffer
  int m_nCount; // Control how many elements are actually used
  int m_nMax;   // Control how many are allocated as maximum
  int m_nDelta; // To control the growing
  void Resize();        // Resize the vector when an overflow occurs

public:
  CVector(int delta = 10); // Constructor
  void Insert(int elem);   // Insert a new element
  // More methods can go here
};

CVector::CVector(int delta) {
  m_pVect = NULL; // Initialize the pointer
  m_nCount = 0;
  m_nMax = 0;
  m_nDelta = delta;
}

void CVector::Insert(int elem) {
  if (m_nCount == m_nMax) // Verify overflow
    Resize();             // Resize the vector before inserting elem
  m_pVect[m_nCount++] = elem;
}

void CVector::Resize() {
  m_pVect = (int *)realloc(m_pVect, sizeof(int) * (m_nMax + m_nDelta));
  m_nMax += m_nDelta;
}

int main() {
  CVector sampleVector;
  cout << "Inserted: ";
  for (int i = 0; i < 100; i++) {
    sampleVector.Insert(i);
    cout << i << " ";
  }
  return 0;
}
