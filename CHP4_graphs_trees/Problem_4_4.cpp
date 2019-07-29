#include <vector>
#include <stack>

using namespace std;

class node_t {
public:
    node_t* left;
    node_t* right;
    int val;
    node_t (int v) : val(v), left(nullptr), right(nullptr) {}
};

//Problem is to see if a given tree is balanced.
class isBalanced {
public:
    // visit keeps track of what we have visited at a node
    bool isBlncd(node_t* root) {
        if (root == nullptr) return true;
        stack<node_t*> st;
        auto visit = vector<int>(20);
        vector<int> depths;

        visit[0] = 0;
        st.push(root);

        while(!st.empty()) {
            node_t* tmp = st.top();

            // do left 
            if (visit[st.size() - 1] == 0) {            
                if (tmp->left == nullptr) depths.push_back(st.size());
                else {
                    st.push(tmp->left);
                    depths[st.size()-1] = 0;
                }
                ++visit[st.size() - 1];
            } else if (visit[st.size - 1] == 1) {
                if (tmp->right == nullptr) depths.push_back(st.size());
                else {
                    st.push(tmp->right);
                    depths[st.size()-1] = 0;
                }
                ++visit[st.size() - 1];
            } else if (visit[st.size - 1] == 2) {
                st.pop();
            } else {
                //dead
                return false;
            }
        }

        int b = depths[0];
        for (auto i : depths) {
            if ((b-i) > 1 || (i-b) > 1) return false;
        }
        return true;
    }
};