class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        //对循环体要用到的变量进行初始化，这样可以减少循环层，但循环体里面会复杂
        vector<vector<int>> result(n, vector<int>(n, 0));
        int loop = n / 2;
        int startx = 0, starty = 0;
        int offset = 1;
        int count = 1;
        int mid = n / 2;
        int i, j;

        while (loop--) {
            i = startx;
            j = starty;
            for (j; j < n - offset; j++) {
                result[i][j] = count++;
            }
            for (i; i < n - offset; i++) {
                result[i][j] = count++;
            }
            for (; j > startx; j--) {
                result[i][j] = count++;
            }
            for (; i > starty; i--) {
                result[i][j] = count++;
            }

            startx++;
            starty++;

            offset++;
        }
        if (n % 2 != 0) {
            result[mid][mid] = count;
        }
        return result;
    }
};