#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
int maxDifference(const vector<int>& nums) {
    if (nums.size() < 2) {
        throw invalid_argument("Array must contain at least two elements.");
    }
    int min_element = INT_MAX;
    int max_element = INT_MIN;
    for (int num : nums) {
        if (num < min_element) {
            min_element = num;
        }
        if (num > max_element) {
            max_element = num;
        }
    }
    return max_element - min_element;
}
int main() {
    vector<int> nums = {1, 2, 90, 10, 110};
    try {
        int result = maxDifference(nums);
        cout << "The maximum difference between any two elements in the array is " << result <<endl;
    } catch (const invalid_argument& e) {
        cerr << e.what() <<endl;
    }
    return 0;
}
