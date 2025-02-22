class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        //��ѭ����Ҫ�õ��ı������г�ʼ�����������Լ���ѭ���㣬��ѭ��������Ḵ��
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