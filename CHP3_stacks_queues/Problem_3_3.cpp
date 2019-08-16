#include <iostream>
#include <vector>

using namespace std;

// max size stack class
class stackPlates {
private:
  size_t threshold = 0;
  vector<vector<uint32_t>> tmp;
public:
  stackPlates::stackPlates(size_t threshold) : threshold(threshold){}

  void push(uint32_t val) {
    if (tmp[tmp.size() - 1].size() != threshold) tmp[tmp.size() - 1].push_back(val);
    else tmp.push_back(vector<uint32_t>(1,val));
  }

  void pop() {
    tmp[tmp.size() - 1].erase(--(tmp[tmp.size() - 1].end()));
    if (tmp[tmp.size() - 1].size() == 0) tmp.erase(--(tmp.end()));
  }

  uint32_t top() {
    return tmp[tmp.size() - 1].back();
  }

  uint32_t popAt(size_t index) {
    auto ret = *(--(tmp[index].end()));
    tmp[index].erase(--(tmp[index - 1].end()));
    return ret;
  }
};