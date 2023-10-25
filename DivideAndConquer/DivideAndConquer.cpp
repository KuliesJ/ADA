#include <iostream>
#include <vector>
using namespace std;

void quickSort(vector <int> &A, int inf, int sup){
   int i = inf;
   int j = sup;
   int x = A[(inf+sup)/2];
   while(i <= j){
      for(;A[i] < x;i++);
      for(;A[j] > x;j--);
      if(i <= j){
         swap(A[i], A[j]);
         i++;
         j--;
      }
   }
   if (inf < j){
      quickSort(A,inf,j);
   }
   if (i < sup){
      quickSort(A,i,sup);
   }
}

void prevQuickSort(vector <int> &A){
   quickSort(A, 0, A.size()-1);
}

vector<int> merge(vector<int>& a, vector<int>& b) {
    vector<int> c;
    int i = 0, j = 0;

    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            c.push_back(a[i]);
            i++;
        } else {
            c.push_back(b[j]);
            j++;
        }
    }

    while (i < a.size()) {
        c.push_back(a[i]);
        i++;
    }

    while (j < b.size()) {
        c.push_back(b[j]);
        j++;
    }

    return c;
}

vector<int> mergeSort(vector<int> a) {
    int n = a.size();
    if (n <= 1) {
        return a;
    }

    vector<int> arrayOne(a.begin(), a.begin() + n / 2);
    vector<int> arrayTwo(a.begin() + n / 2, a.end());

    arrayOne = mergeSort(arrayOne);
    arrayTwo = mergeSort(arrayTwo);

    return merge(arrayOne, arrayTwo);
}

void printVector(vector <int> &A){
   for(int i=0; i<A.size(); i++){
       printf("%d ", A[i]);
   }
}

int findMiddle(vector <int> A, int position){
    int n = A.size()-1;
    int pivot = A[n];
    int index = 0;
    for(int i=0; i<n; i++){
        if (A[i] < pivot){
            index = index + 1;
        }
    }
    if(index < position){
        vector <int> a(A.begin() + index, a.begin());
        return findMiddle(a, position);
    }
    if(index > position){
        vector <int> a(A.begin(), a.begin() + index);
        return findMiddle(a, position);
    }
    else{
        return A[index];
    }
}

int main() {
   vector<int> test = {5,1,2,6,7,3,8};
   printf("%d", findMiddle(test, ((test.size()-1)/2)+1));
   return 0;
}