'''
56 ����֮��

��һ���������飬�ҵ�������ʹ�����ǵĺ͵���һ���������� target��

����Ҫʵ�ֵĺ���twoSum��Ҫ���������������±�, ���ҵ�һ���±�С�ڵڶ����±ꡣע�������±�ķ�Χ�� 1 �� n�������� 0 ��ͷ��

 ע������

����Լ���ֻ��һ��𰸡�

������ʵ���������Ƿ�����������⣿ Yes
����
���� numbers = [2, 7, 11, 15], target = 9, ���� [1, 2].

'''

class Solution:
    """
    @param numbers : An array of Integer
    @param target : target = numbers[index1] + numbers[index2]
    @return : [index1 + 1, index2 + 1] (index1 < index2)
    """

    def twoSum(self, numbers, target):
        # write your code here
        ret = []
        for i in range(len(numbers)):
            for j in range(i + 1, len(numbers)):
                if numbers[i] + numbers[j] == target:
                    ret.append(i+1)
                    ret.append(j+1)

        return ret


s = Solution()
l = [2,7,11,15]

print(s.twoSum(l,9))