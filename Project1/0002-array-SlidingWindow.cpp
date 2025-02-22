class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT32_MAX;
        int i = 0;
        int sum = 0;
        int len = nums.size();
        for (int j = 0; j < len; j++) {
            sum += nums[j];
            while (sum >= target) {
                int subLength = j - i + 1;
                result = result < subLength ? result : subLength;
                sum -= nums[i++];//i变动的精髓
            }
        }
        return result == INT32_MAX ? 0 : result;
    }
};