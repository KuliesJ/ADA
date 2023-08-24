#include <iostream>
using namespace std;
template <typename Type> class CVector {
private:
  Type *m_pVect;        // Pointer to the buffer
  int m_nCount,         // Control how many elements are actually used
      m_nMax,           // Control the number of allocated elements
      m_nDelta;         // To control the growing
  void Resize();        // Resize the vector when occurs an overflow
public:
  CVector(int delta = 10); // Constructor
  void Insert(Type elem);  // Insert a new element
  // ...
};

// Class CVector implementation
template <typename Type> void CVector<Type>::Resize() {
  m_pVect = (Type *)realloc(m_pVect, sizeof(Type) * (m_nMax + m_nDelta));
  m_nMax += m_nDelta;
}

template <typename Type> CVector<Type>::CVector(int delta){
  m_pVect = NULL; // Initialize the pointer
  m_nCount = 0;
  m_nMax = 0;
  m_nDelta = delta;
}

template <typename Type> void CVector<Type>::Insert(Type elem) {
  if (m_nCount == m_nMax)     // Verify the overflow
    Resize();                 // Resize the vector before inserting elem
  m_pVect[m_nCount++] = elem; // Insert the element at the end
}

int main() {
  CVector<int> CIntVector;
  cout << "Inserted: ";
  for (int i = 0; i < 100; i++) {
    CIntVector.Insert(i);
    cout << i << " ";
  }

  return 0;
}
