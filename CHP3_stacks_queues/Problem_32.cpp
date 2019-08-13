#include <iostream>
#include <vector>

using namespace std;

class minStack {
private:
vector<int> st;
vector<int> minSt;

public:
  int top() {
    return st[st.size()-1];
  }

  void push(int ele) {
    st.push_back(ele);
    if (ele < minSt[minSt.size() - 1]) {
      minSt.push_back(ele);
    }
  }

  int pop() {
    auto a = st[st.size() - 1];
    st.pop_back();
    if (a == minSt[minSt.size() - 1]) minSt.pop_back();
    return a;
  }

  int min() {
    return minSt[minSt.size() - 1];
  }

};
