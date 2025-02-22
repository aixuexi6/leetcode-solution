#include <iostream>
#include <vector>
#include <algorithm> // 用于std::copy和std::ostream_iterator
#include <iterator>  // 用于std::ostream_iterator

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int len = nums.size();
        int k = len - 1;
        vector<int> result(len); // 初始化result数组，长度与nums相同

        // 双指针法排序
        for (int i = 0, j = len - 1; i <= j;) {
            if (nums[i] * nums[i] < nums[j] * nums[j]) {
                result[k--] = nums[j] * nums[j];
                j--;
            }
            else {
                result[k--] = nums[i] * nums[i];
                i++;
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums = { -4, -1, 0, 3, 10 };
    Solution solution;
    vector<int> result = solution.sortedSquares(nums);

    // 使用ostream_iterator直接输出result数组
    copy(result.begin(), result.end(), ostream_iterator<int>(cout, " "));
    cout << endl; // 输出换行符

    return 0;
}