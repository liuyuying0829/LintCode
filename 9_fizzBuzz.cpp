/*
9 Fizz Buzz ����

����һ������n. �� 1 �� n ��������Ĺ����ӡÿ������

����������3��������ӡfizz.
����������5��������ӡbuzz.
����������ͬʱ��3��5��������ӡfizz buzz.
*/

class Solution {
public:
    /**
     * param n: As description.
     * return: A list of strings.
     */
    vector<string> fizzBuzz(int n) {
        vector<string> results;
        for (int i = 1; i <= n; i++) {
            if (i % 15 == 0) {
                results.push_back("fizz buzz");
            } else if (i % 5 == 0) {
                results.push_back("buzz");
            } else if (i % 3 == 0) {
                results.push_back("fizz");
            } else {
                results.push_back(to_string(i));
            }
        }
        return results;
    }
};