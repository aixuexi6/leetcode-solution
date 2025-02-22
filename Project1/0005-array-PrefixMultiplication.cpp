class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> r(len), l(len), res(len);
        r[0] = 1;
        l[len - 1] = 1;

        //×óÓÒÇ°×º³Ë»ý
        for (int i = 1; i < len; i++) {
            r[i] = r[i - 1] * nums[i - 1];
        }
        for (int i = len - 1; i > 0; i--) {
            l[i - 1] = l[i] * nums[i];
        }
        for (int i = 0; i < len; i++) {
            res[i] = l[i] * r[i];
        }
        return res;
    }
};