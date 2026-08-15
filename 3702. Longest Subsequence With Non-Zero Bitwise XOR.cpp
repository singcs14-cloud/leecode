class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        bool zero = false;
        int xxor = 0;
        for(int num : nums){
            xxor ^= num;
            if(num != 0){
                zero = true;
                
            }
        }
        if(!zero) return 0;
        if(!xxor) return nums.size()-1;
        else return nums.size();
    }
};
