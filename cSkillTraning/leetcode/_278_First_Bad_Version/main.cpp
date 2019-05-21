//  You are a product manager and currently leading a team to develop a new product. Unfortunately, the
//  latest version of your product fails the quality check. Since each version is developed based on the
//  previous version, all the versions after a bad version are also bad.
//
//  Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes
//  all the following ones to be bad.
//
//  You are given an API bool isBadVersion(version) which will return whether version is bad. Implement
//  a function to find the first bad version. You should minimize the number of calls to the API.
//
//  Example:
//
//  Given n = 5, and version = 4 is the first bad version.
//
//  call isBadVersion(3) -> false
//  call isBadVersion(5) -> true
//  call isBadVersion(4) -> true
//
//  Then 4 is the first bad version.

// Forward declaration of isBadVersion API.

#include <iostream> //bool, true or false

bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n);
};

bool
isBadVersion(int version)
{
    int badversion = 4;
    return (version >= badversion)? true: false;
}

int
Solution::firstBadVersion(int n)
{
    int left = 0, right = n;
    while(left <= right) {
        int mid = left+(right-left)/2;
        if (isBadVersion(mid) && !isBadVersion(mid-1))
            return mid;
        if (isBadVersion(mid))
            right = mid-1;
        else
            left = mid+1;
    }
    return -1;
}

int
main(void)
{
    Solution s;
    std::cout << s.firstBadVersion(5) << std::endl;
    return 0;
}

