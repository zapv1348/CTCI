#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

// already done in leetcode
// My leetcode problems 210 and 207
// lets do it anBuildOrder
class BuildOrder {
public:
    vector<int> findBuildOrder(vector<pair<int,int>> dependencies, int numClass) {
        auto visited = vector<bool>(numClass, false);
        auto ret = vector<int>(numClass, 0);
        
        for (auto i : dependencies) {
            unordered_set<int> current_nodes;
            current_nodes.insert(i.first);
            for (auto j : dependencies) {
                if (i != j && i.second == j.first) {
                    
                }
            }
        }

        return ret;
    }
};