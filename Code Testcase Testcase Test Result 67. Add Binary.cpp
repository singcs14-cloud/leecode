class Solution {
public:
    string addBinary(string a, string b) {
        int posa = a.size()-1;
        int posb = b.size()-1;
        int next =0;
        stack<int> sta;
        while(posa>= 0 && posb >=0){
            int sum =( a[posa--] -'0') +( b[posb--] -'0')+ next;
            next=0;
            if(sum >=2){
                next = 1;
                sum-=2;
            }
            sta.push(sum);
        }
        while(posa>= 0 ){
            int sum =( a[posa--] -'0') + next;
            next=0;
            if(sum >=2){
                next = 1;
                sum-=2;
            }
            sta.push(sum);
        }
        while(posb >=0){
            int sum = ( b[posb--] -'0')+ next;
            next=0;
            if(sum >=2){
                next = 1;
                sum-=2;
            }
            sta.push(sum);
        }
        if(next ==1) sta.push(1);
        string ans;
        while(!sta.empty()){
            ans += to_string(sta.top());
            sta.pop();
        }
        return ans;
    }
    
};
