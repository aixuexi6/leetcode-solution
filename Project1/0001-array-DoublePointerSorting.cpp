#include <iostream>
#include <vector>
#include <algorithm> // ����std::copy��std::ostream_iterator
#include <iterator>  // ����std::ostream_iterator

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int len = nums.size();
        int k = len - 1;
        vector<int> result(len); // ��ʼ��result���飬������nums��ͬ

        // ˫ָ�뷨����
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

    // ʹ��ostream_iteratorֱ�����result����
    copy(result.begin(), result.end(), ostream_iterator<int>(cout, " "));
    cout << endl; // ������з�

    return 0;
}