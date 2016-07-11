/*
183 ľ�ļӹ�

��һЩԭľ�����������Щľͷ�и��һЩ������ͬ��С��ľͷ����Ҫ�õ���С�ε���Ŀ����Ϊ k����Ȼ������ϣ���õ���С��Խ��Խ�ã�����Ҫ�����ܹ��õ���С��ľͷ����󳤶ȡ�

ľͷ���ȵĵ�λ�����ס�ԭľ�ĳ��ȶ���������������Ҫ���и�õ���С��ľͷ�ĳ���ҲҪ�����������޷��г�Ҫ������ k �ε�,�򷵻� 0 ���ɡ�

����
��3��ľͷ[232, 124, 456], k=7, ��󳤶�Ϊ114.
*/

class Solution {
public:
	/**
	*@param L: Given n pieces of wood with length L[i]
	*@param k: An integer
	*return: The maximum length of the small pieces.
	*/
	int woodCut(vector<int> L, int k) {
		// write your code here
		if (L.empty() || k <= 0)
		{
			return 0;
		}//if

		long long sumLen = 0;
		int len = L.size();
		for (int i = 0; i<len; ++i)
		{
			sumLen += L[i];
		}//for

		if (sumLen < k)
		{
			return 0;
		}//if

		int maxLen = *max_element(L.begin(), L.end());
		int l = 1, r = maxLen;
		while (l <= r)
		{
			int mid = l + (r - l) / 2;
			if (judge(L, mid, k))
			{
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}//else

		}//while
		return (int)r;
	}

	bool judge(vector<int> L, int mid, int k)
	{
		if (L.empty() || k <= 0)
		{
			return 0;
		}//if

		int count = 0, len = L.size();
		for (int i = 0; i<len; ++i)
		{
			count += L[i] / mid;
		}//for

		if (count >= k)
			return true;
		else
			return false;
	}
};