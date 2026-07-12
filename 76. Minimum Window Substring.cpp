class Solution {
public:
    string minWindow(string s, string t) {

        int left=0;int right=0;
        int valid=0;
        int start=0; int minlen = 100005;
        unordered_map<char,int> target;
        unordered_map<char,int> now;
        
        for(int j=0;j<t.size();j++){
            target[t[j]]++;
        }

        while(right<s.size()){
            char c = s[right++];

            if(target.count(c) ){
                now[c]++;
                if(target[c] == now[c])valid++;
            } 
            while(valid == target.size()){

                while(right-left < minlen){
                    start = left;
                    minlen = right-left;
                }
                
                char d= s[left++];
                if(target.count(d)){
                    if(target[d] ==  now[d]){
                    valid--;
                    }
                    now[d]--;
                }
                
            }

        }
        return minlen == 100005 ? "": s.substr(start,minlen);

    }
};
