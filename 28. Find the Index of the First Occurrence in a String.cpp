class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size() < needle.size())return -1;
        int neepos=0;
        for(int i=0;i<=haystack.size()-needle.size();i++){
            if(haystack[i] != needle[0])continue;
            string s = haystack.substr(i,needle.size());

           if(s == needle)return i;
        }
        return -1;
    }
};
