class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> map( n, vector<int>(n,0));
        int num=1;
        int posx=0; int posy=0;
        int lastx=0;int lasty=1; //last move
        while(num <= n*n){
            map[posx][posy] = num;
            num++;
            if(lastx==0 && lasty == 1){
                if(posy+1 < n && map[posx][posy+1] == 0){
                    posy++;
                }else{
                    posx++;
                    lastx=1;
                    lasty=0;
                }
            }else if(lastx==0 && lasty == -1){
                if(posy-1 >= 0 && map[posx][posy-1] == 0){
                    posy--;
                }else{
                    posx--;
                    lastx=-1;
                    lasty=0;
                }
            }else if(lastx==1 && lasty == 0){
                if(posx+1 < n && map[posx+1][posy] == 0){
                    posx++;
                }else{
                    posy--;
                    lastx=0;
                    lasty=-1;
                }
            }else if(lastx==-1 && lasty == 0){
                if(posx-1 >= 0 && map[posx-1][posy] == 0){
                    posx--;
                }else{
                    posy++;
                    lastx=0;
                    lasty=1;
                }
            }
        }
        return map;
        
    }
};
