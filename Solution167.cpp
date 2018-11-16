#include"tool.h"
class Solution167 {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>::iterator head = numbers.begin();
        vector<int>::iterator tail = numbers.end();
        vector<int> res;
        for(; head < tail; head++){
            int targetNum = target - *head;
            auto searchRes = search(numbers, head + 1, tail - 1, targetNum);
            if(searchRes != numbers.end()){
                int index1 = head - numbers.begin() + 1;
                int index2 = searchRes - numbers.begin() + 1;
                res.push_back(index1);
                res.push_back(index2);
                break;
            }
        }
        return res;
    }

    vector<int>::iterator search(vector<int>& nums, vector<int>::iterator head, vector<int>::iterator tail, int targetNum){
        auto mid = head + (tail - head) / 2;
        if(head == mid){
            if(*head == targetNum){
                return head;
            }
            else if(*tail == targetNum){
                return tail;
            }
            else
                return nums.end();
        }
        if(*mid < targetNum){
           return search(nums, mid, tail, targetNum);
        }
        else if(*mid == targetNum){
            return mid;
        }
        else{
           return search(nums, head, mid, targetNum); 
        }
    }
};