#include <vector>
#include <unordered_set>

using namespace std;

typedef struct node_t {
  int val;
  node_t* next;
} node_t;

void removedDuplicates(node_t* head) {
  unordered_set<int> uset;
  if (head == nullptr) return;
  uset.insert(head->val);

  while (head->next != nullptr) {
    if (uset.find(head->next->val) != uset.end()) {
      // delete node
      node_t* tmp = head->next->next;
      delete(head->next);
      head->next = tmp;
    } else {
      uset.insert(head->val);
    }
  }
}
