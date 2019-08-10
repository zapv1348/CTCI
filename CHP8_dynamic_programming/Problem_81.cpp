#include <iostream>
#include <vector>

using namespace std;

// A child can take 1, 2, or 3 steps up a flight of n stairs.
// Calculate how many possible ways the child can go up the steps
int threeStepStairCase(int n) {
    vector<int> ret = vector<int>(n, 0);
    ret[0] = 0;
    ret[1] = 1;
    ret[2] = ret[1] + 1;
    ret[3] = ret[2] + ret[1] + 1;

    for (auto i = 4; i <= n; ++i) {
        ret[i] = ret[i-1] + ret[i-2] + ret[i-3];
    }

    return ret[n];
}