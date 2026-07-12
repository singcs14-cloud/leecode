class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int num=0; int n = matrix[0].size();int m = matrix.size();
        int posx=0; int posy=0;
        int lastx=0;int lasty=1; //last move
        vector<int> arr(n*m);
        while(num < m*n){
            arr[num++] = matrix[posx][posy];
            matrix[posx][posy] = 200; //used
            if(lastx==0 && lasty == 1){
                if( posy+1 < n   && matrix[posx][posy+1] != 200 ){
                    posy++;
                }else{
                    posx++;
                    lastx=1;
                    lasty=0;
                }
            }else if(lastx==0 && lasty == -1){
                if( posy-1 >= 0 && matrix[posx][posy-1] != 200 ){
                    posy--;
                }else{
                    posx--;
                    lastx=-1;
                    lasty=0;
                }
            }else if(lastx==1 && lasty == 0){
                if( posx+1 < m && matrix[posx+1][posy] != 200 ){
                    posx++;
                }else{
                    posy--;
                    lastx=0;
                    lasty=-1;
                }
            }else if(lastx==-1 && lasty == 0){
                if( posx-1 >= 0 && matrix[posx-1][posy] != 200 ){
                    posx--;
                }else{
                    posy++;
                    lastx=0;
                    lasty=1;
                }
            }
        }
        return arr;
    }
};
