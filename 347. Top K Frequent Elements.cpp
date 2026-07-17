class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       
        unordered_map<int ,int> map1;//key = num , value = num.count
        multimap<int ,int,greater<int>> map2; //key = num.count , value = num
        for(int i : nums) map1[i]++;
        for(const auto &pair : map1){
    
            map2.insert({pair.second, pair.first});
        }
        vector<int> v;
        for(const auto &s :map2){
            v.push_back(s.second);
            k--;
            if(k == 0)return v;
        }
        return v;

    }
};
