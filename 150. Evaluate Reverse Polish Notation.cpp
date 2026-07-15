class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> num;
        for(string s : tokens){
            if(s =="+" ){
                int a = num.top();
                num.pop();
                int b = num.top();
                num.pop();
                num.push(a+b);
            }else if(s =="-" ){
                int a = num.top();
                num.pop();
                int b = num.top();
                num.pop();
                num.push(b-a);
            }else if(s =="*" ){
                int a = num.top();
                num.pop();
                int b = num.top();
                num.pop();
                num.push(a*b);
            }else if(s =="/" ){
                int a = num.top();
                num.pop();
                int b = num.top();
                num.pop();
                num.push(b/a);
            }else{
                num.push( stoi(s));
            }
        }
        int ans = num.top();
        return ans;
    }
};
