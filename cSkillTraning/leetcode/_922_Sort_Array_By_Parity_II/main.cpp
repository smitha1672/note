//  Given an array A of non-negative integers, half of the integers in A are odd, and half of the integers are even.
//
//  Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is even, i is even.
//
//  You may return any answer array that satisfies this condition.
//
//
//
//  Example 1:
//
//  Input: [4,2,5,7]
//  Output: [4,5,2,7]
//  Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.
//
//
//  Note:
//
//  1. 2 <= A.length <= 20000
//  2. A.length % 2 == 0
//  3. 0 <= A[i] <= 1000

//  class Solution {
//  public:
//      vector<int>
//      sortArrayByParityII(vector<int>& A)
//      {
//      }
//  };

#include <vector>
#include <iostream>
#include <cstdio>


using namespace std;

// https://zxi.mytechroad.com/blog/uncategorized/leetcode-922-sort-array-by-parity-ii/
// Author: Huahua
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    vector<int>
    sortArrayByParityII(vector<int>& A)
    {
        vector<int> evens;
        vector<int> odds;
        for (int a : A)
            if (a % 2 == 0)
                evens.push_back(a);
            else
                odds.push_back(a);
        auto it1 = begin(evens);
        auto it2 = begin(odds);
        for (int i = 0; i < A.size(); ++i) {
            A[i] = *it1++;
            swap(it1, it2);
        }
        return A;
    }
};

int
main(void)
{
    int i = 0;
    Solution s;
    vector<int> A = {4,2,5,7};
    s.sortArrayByParityII(A);
    for(i = 0 ; i < A.size(); i++)
        printf("%d \n", A[i]);

    return 0;
}
