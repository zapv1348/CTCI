#include <vector>

using namespace std;

class node_t {
public:
    node_t* left;
    node_t* right;
    int val;
    node_t (int v) : val(v), left(nullptr), right(nullptr) {}
};

// problem is to see if this is a BST
class checkBst {
private:
    bool inIsBST(node_t* root, int min, int max) {
        if (root == nullptr) return true;

        auto middle = root->val;
        if (middle > max || middle < min) return false;
        if (inIsBST(root->left, min, middle) == false) return false;
        if (inIsBST(root->right, middle, max) == false) return false;

        return true;
    }
public:
    bool isBST(node_t* root) {
        if (root == nullptr) return true;
        auto min = __INT32_MAX__ + 1;
        auto max = __INT32_MAX__;
        auto middle = root->val;
        if (inIsBST(root->left, min, middle) == false) return false;
        if (inIsBST(root->right, middle, max) == false) return false;
        return true;
    }
};