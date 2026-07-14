class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i=0;i< n-3;i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            for(int j=i+1;j<n-2 ;j++){
                if( j>i+1 && nums[j] == nums[j-1]) continue;
                long long remain = (long long)target - (long long)(nums[i] + nums[j]);
                int left = j+1;
                int right = n-1;
                while(left <right){
                    if(remain == nums[left] + nums[right]){
                        ans.push_back({nums[i] , nums[j] , nums[left] , nums[right] });
                        
                        left++;
                        right--;
                        if(left >= right) break;
                        while(nums[left-1] == nums[left] && nums[right+1] == nums[right]){
                            left++;
                            right--;
                            if(left >= right)break;
                        }
                       
                    }else if(remain > nums[left] + nums[right])left++;
                    else right--;
                }
                
            }
        }
        return ans;

    }
};
