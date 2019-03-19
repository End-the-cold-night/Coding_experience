/*
268. Missing Number
Easy

792

1209

Favorite

Share
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1:

Input: [3,0,1]
Output: 2
Example 2:

Input: [9,6,4,2,3,5,7,0,1]
Output: 8
Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(nums.size()==0) return 0;
        for(int i=0; i<nums.size();i++){
            if(nums[i]<0 || nums[i]>=nums.size()) continue;
            while(nums[i]!=i){
                # the order matters!!!
                if( nums[i]<0 || nums[i]>=nums.size() || nums[nums[i]]==nums[i]) break;
                swap(nums[nums[i]], nums[i]);
            }
        }
        for(int i=0;i<nums.size();i++)
            if(nums[i]!=i)
                return i;
        return nums.size();
    }
};


