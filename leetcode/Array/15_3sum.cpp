Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]


Attention:露了对nums判断，size_type和int混用，导致runtime error!!!!


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3) return {};
        set<vector<int>> temp;
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size()-2;i++){
            vector<int> t = {nums[i]};
            int index1=i+1, index2=nums.size()-1;
            while(index1<index2){
                if(nums[index1] + nums[index2] == -nums[i]){
                    t.push_back(nums[index1]);
                    t.push_back(nums[index2]);
                    temp.insert(t);
                    t.pop_back();
                    t.pop_back();
                    index1++;
                    index2--;
                }
                else if(nums[index1] + nums[index2] > -nums[i])
                    index2--;
                else
                    index1++;
            }
        }
        vector<vector<int>> ret;
        for(auto x: temp)
            ret.push_back(x);
        return ret;
    }
};
