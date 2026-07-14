class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        int ans=0;
        unordered_map<int,int> mapp;
        for(int i : nums1){
            for(int j : nums2){
                mapp[ i + j ]++;
            }
        }
        for(int i : nums3){
            for(int j : nums4){
                if(mapp.count(-i-j)){
                    if(mapp[ -i-j ] > 0)ans+=mapp[ -i-j ] ;
                }
                
            }
        }

        return ans;
    }
};
