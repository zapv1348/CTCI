#include <vector>
#include <iostream>

using namespace std;

class SortedMerge {

public:
  void SortAndMerge(vector<int> a, vector<int> b) {
    int i = 0;
    int j = 0;
    while (i< (a.size() + b.size())) {
      if (a[i] > b[j]) {
        auto k = i;
        while (k < a.size() + i) {
          int tmp = a[k+1];
          a[k+1] = a[k];
          ++k;
        }
        a[i] = b[j];
        ++j;
        ++i;
      } else {
        ++i;
      }
    }
  }
};