#include <memory>
#include <vector>

using namespace std;

class node_t {
public:
    unique_ptr<node_t> left;
    unique_ptr<node_t> right;
    int val;
    node_t (int v) : val(v), left(nullptr), right(nullptr) {}
};

// take an array(vector) of increasing order unique elements and turn it into a balanced BST
class GenBalancedBST {
private:
    unique_ptr<node_t> createDown(vector<int>& elems, int min, int max) {
        if (min == max) return nullptr;
        int half = min + (max-min)/2;
        auto ret = make_unique<node_t>(elems[half]);
        ret->left = createDown(elems, min, half);
        ret->right = createDown(elems, half+1, max);
    }

public:
    unique_ptr<node_t> creatBalancedBST(vector<int> elems) {
        if (elems.size() == 0) return nullptr;

        int half = elems.size()/2;
        auto ret = make_unique<node_t>(elems[half]);
        int min = 0;
        int max = elems.size();


        ret->left = createDown(elems, min, half);
        ret->right = createDown(elems, half+1, max);

        return ret;
    }
};