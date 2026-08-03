class Solution {
public:
    int score[21][21] ;
    int get_score(vector<int>& nums , int l ,int r ){
        if(l == r) return nums[l];
        if(score[l][r] != -1) return score[l][r];

        int left = nums[l] - get_score(nums ,l+1,r);
        int right = nums[r] - get_score(nums ,l,r-1);
        score[l][r] =  max(left,right);
        return max(left,right);
    }
    
    bool predictTheWinner(vector<int>& nums) {
        if(nums.size() == 1) return true;
        memset(score , -1, sizeof(score));
        
        return get_score(nums ,0 ,nums.size()-1 )>=0;
    }
    
}; 
