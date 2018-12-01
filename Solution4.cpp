#include "tool.h"
class Solution
{
  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        double result;
        int length = nums1.size() + nums2.size();
        int index = 0, index1 = 0, index2 = 0;
        int flag1 = 0, flag2 = 0;
        vector<int> targetIndex;
        if (length % 2 == 0)
        {
            targetIndex.push_back(length / 2 - 1);
            targetIndex.push_back(length / 2);
        }
        else
        {
            targetIndex.push_back(length / 2);
        }
        if (nums1.empty() || nums2.empty())
        {
            vector<int> tmp = nums1.empty() ? nums2 : nums1;
            if (targetIndex.size() == 1)
            {
                result = tmp[targetIndex[0]];
                return result;
            }
            else
            {
                result = (tmp[targetIndex[0]] + tmp[targetIndex[1]]) / 2.0;
                return result;
            }
        }
        int flag = nums1[index1] <= nums2[index2] ? 0 : 1;
        while (true)
        {
            if (index == targetIndex[0])
            {
                if (targetIndex.size() == 1)
                {
                    result = flag ? nums2[index2] : nums1[index1];
                    return result;
                }
                else
                {
                    int tmp1, tmp2;
                    if (flag)
                    {
                        tmp1 = nums2[index2];
                        if (index2 + 1 == nums2.size())
                        {
                            tmp2 = nums1[index1];
                        }
                        else
                        {
                            if (flag1)
                            {
                                tmp2 = nums2[index2 + 1];
                            }
                            else
                            {
                                tmp2 = nums2[index2 + 1] <= nums1[index1] ? nums2[index2 + 1] : nums1[index1];
                            }
                        }
                    }
                    else
                    {
                        tmp1 = nums1[index1];
                        if (index1 + 1 == nums1.size())
                        {
                            tmp2 = nums2[index2];
                        }
                        else
                        {
                            if (flag2)
                            {
                                tmp2 = nums1[index1 + 1];
                            }
                            else
                            {
                                tmp2 = nums1[index1 + 1] <= nums2[index2] ? nums1[index1 + 1] : nums2[index2];
                            }
                        }
                    }
                    result = (tmp1 + tmp2) / 2.0;
                    return result;
                }
            }
            else
            {
                if (index1 + 1 == nums1.size() && flag == 0)
                {
                    if (flag)
                    {
                        index2++;
                    }
                    flag1 = 1;
                    flag = 1;
                }
                else if (index2 + 1 == nums2.size() && flag == 1)
                {
                    if (flag == 0)
                    {
                        index1++;
                    }
                    flag2 = 1;
                    flag = 0;
                }
                else
                {
                    if (flag)
                    {
                        if (nums2[index2 + 1] >= nums1[index1] && !flag1)
                        {
                            flag = 0;
                        }
                        index2++;
                    }
                    else
                    {
                        if (nums1[index1 + 1] >= nums2[index2] && !flag2)
                        {
                            flag = 1;
                        }
                        index1++;
                    }
                }
                index++;
            }
        }
    }
};

int main(void)
{
    vector<int> nums1 = {1};
    vector<int> nums2 = {2, 3, 4, 5};
    double res = Solution().findMedianSortedArrays(nums1, nums2);
    return 0;
}