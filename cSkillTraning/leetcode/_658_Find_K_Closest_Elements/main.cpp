//  Given a sorted array, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.
//
//  Example 1:
//  Input: [1,2,3,4,5], k=4, x=3
//  Output: [1,2,3,4]
//
//  Example 2:
//  Input: [1,2,3,4,5], k=4, x=-1
//  Output: [1,2,3,4]
//
//  Note:
//  The value k is positive and will always be smaller than the length of the sorted array.
//  Length of the given array is positive and will not exceed 104
//  Absolute value of elements in the array and x will not exceed 104

//  class Solution {
//  public:
//      vector<int>
//      findClosestElements(vector<int>& arr, int k, int x)
//      {
//      }
//  };

#include <vector>
#include <iostream>

using namespace std;

class Solution1 {
public:
    vector<int>
    findClosestElements(vector<int>& arr, int k, int x)
    {
        vector<int> res = arr;
        while (res.size() > k) {
            if (x - res.front() <= res.back() - x)
                res.pop_back();
            else
                res.erase(res.begin());
        }
        return res;
    }
};

class Solution2 {
public:
    vector<int>
    findClosestElements(vector<int>& arr, int k, int x)
    {
        int left = 0, right = arr.size() - k;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (x - arr[mid] > arr[mid + k] - x) left = mid + 1;
            else right = mid;
        }
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};

int
main(void)
{
    vector<int>arr_{1, 2, 3, 4, 5};
    Solution2 s2;
    for (auto value: s2.findClosestElements(arr_, 4, 3))
        cout << value << endl;
    return 0;
}
