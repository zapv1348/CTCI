#include <vector>

using namespace std;

class node_t {
public:
    node_t* left;
    node_t* right;
    node_t* parent;
    int val;
    node_t (int v) : val(v), left(nullptr), right(nullptr), parent(nullptr) {}
};

class findNextInOrder {
    int nextInOrder(node_t* node) {
        if (node->right != nullptr) {
            auto tmp = node->right;
            while (tmp->left != nullptr) tmp = tmp->left;
            return tmp->val;
        }
        if (node->parent != nullptr) {
            auto tmp = node->parent;
            if (tmp->right != node) return tmp->val;
            while(tmp->parent != nullptr) {
                if(tmp->parent->right != tmp) {
                    return tmp->parent->val;
                }
                else {
                    tmp = tmp->parent;
                }
            }
        } 
        return 0;
    }
};