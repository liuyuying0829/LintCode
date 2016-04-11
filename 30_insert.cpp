/*
30 ��������

����һ�����ص��İ���������ʼ�˵�����������б�

���б��в���һ���µ����䣬��Ҫȷ���б��е�������Ȼ�����Ҳ��ص�������б�Ҫ�Ļ������Ժϲ����䣩��

��������[2, 5] �� [[1,2], [5,9]]�����ǵõ� [[1,9]]��

��������[3, 4] �� [[1,2], [5,9]]�����ǵõ� [[1,2], [3,4], [5,9]]��
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

/**
* Definition of Interval:
* class Interval {
* public:
*     int start, end;
*     Interval(int start, int end) {
*         this->start = start;
*         this->end = end;
*     }
* }
*/
class Interval{
public:
	int start, end;
	Interval(int s, int e) :start(s), end(e){}
};

class Solution {
public:
	/**
	* Insert newInterval into intervals.
	* @param intervals: Sorted interval list.
	* @param newInterval: new interval.
	* @return: A new interval list.
	*/
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		// write your code here
		vector<Interval> ret;
		if (intervals.empty())
		{
			ret.push_back(newInterval);
			return ret;
		}//if

		int len = intervals.size();
		
		if (newInterval.end < intervals[0].start)
		{
			ret.push_back(newInterval);
			for (int i = 0; i<len; ++i)
			{
				ret.push_back(intervals[i]);
			}//for
		}//if
		else if (newInterval.start > intervals[len - 1].start)
		{
			for (int i = 0; i < len; ++i)
			{
				ret.push_back(intervals[i]);
				ret.push_back(newInterval);
			}
		}//elif
		else{
			for (int i = 0; i < len; ++i)
			{
				if (isIntersect(intervals[i], newInterval))
				{
					int start = min(intervals[i].start, newInterval.start);
					int end = max(intervals[i].end, newInterval.end);

					newInterval = Interval(start, end);
				}
				else{
					if (intervals[i].start > newInterval.end)
					{
						ret.push_back(newInterval);
						newInterval = intervals[i];
					}//if
					else{
						ret.push_back(intervals[i]);
					}//else
				}//else
			}//for
		}//else
	}

	
	bool isIntersect(Interval i1, Interval i2)
	{
		if (i1.start > i2.end || i1.end < i2.start)
			return false;
		return true;
	}
};