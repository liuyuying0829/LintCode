/*
374 ��������

����һ������ m x n ��Ҫ�صľ��󣬣�m ��, n �У�����������˳��
���ظþ����е�����Ҫ�ء�
*/

class Solution {
public:
	/**
	* @param matrix a matrix of m x n elements
	* @return an integer array
	*/
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		// Write your code here
		if (matrix.empty())
		{
			return vector<int>();
		}//if

		int m = matrix.size(), n = matrix[0].size();

		vector<int> ret;
		int r = 0, c = 0;
		while (r<m && c<n)
		{
			for (int j = c; j<n; ++j)
			{
				ret.push_back(matrix[r][j]);
			}//for

			/*��������ж���*/
			if (r < m - 1)
			{
				for (int i = r + 1; i < m; ++i)
				{
					ret.push_back(matrix[i][n - 1]);
				}
			}
			
			if (c < n - 1 && r < m - 1)
			{
				for (int j = n - 2; j >= c; --j)
				{
					ret.push_back(matrix[m - 1][j]);
				}
			}

			if (c < n - 1 && r < m - 2)
			{
				for (int i = m - 2; i > r; --i)
				{
					ret.push_back(matrix[i][c]);
				}
			}
			++r;
			++c;

			--m;
			--n;
		}//while
		return ret;
	}
};