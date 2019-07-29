#include <vector>
#include <memory>
#include <queue>

using namespace std;

//Problem is to create n linked lists out of a tree of depth n
class node_t {
public:
    node_t* left;
    node_t* right;
    int val;
    node_t (int v) : val(v), left(nullptr), right(nullptr) {}
};

class link_t {
public:
    link_t* next;
    int val;
    link_t (int v) : val(v), next(nullptr) {}
};

class createLinkedLists {
public:
    vector<link_t*> createLists(node_t* root) {
        auto ret = vector<link_t*>();
        if (root == NULL) return ret;
        queue<node_t*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            auto a = q.front(); q.pop();
            auto head = new link_t(a->val);
            auto tmp = head;
            
            if (a->left != nullptr) q.push(a->left);
            if (a->right != nullptr) q.push(a->right);
            for (auto i = 1; i < size; ++i) {
                auto node = q.front(); q.pop();
                tmp->next = new link_t(node->val);
                tmp = tmp->next;
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }

            ret.push_back(head);
        }
        return ret;
    }
};