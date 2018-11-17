#include"tool.h"
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            if(map.count(target-nums[i])){
                res.push_back(map[target - nums[i]]);
                res.push_back(i);
                return res;
            }
            map[nums[i]] = i;
        }  
        return res;
    }
};
int main (){
    vector<int> tmp = {2,7,11,15};
    tmp = Solution().twoSum(tmp,18);
    return 0;
}