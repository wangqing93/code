class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> res;
        if (n == 0)
            return res;
        int m = matrix[0].size();
        int xs,xend,ys,yend, x,y;
        int num = 0;
        x = 0; 
        y=0;
        xs = 0;
        ys = 0;
        xend = n-1;
        yend = m-1;
        while(res.size() < n*m) {
            if (ys <= yend) {
                for (y = ys; y <= yend; y++) {
                    //cout << x << " " << y << endl;
                    if (res.size() == n*m)
                        return res;
                    res.push_back(matrix[x][y]);
                    
                }
                xs = x+1;
                y = yend;
            }
            //cout << "xs: " << xs << " xend: " << xend << endl;
            if (xs <= xend) {
                for (x = xs; x <= xend; x++) {
                    //cout << x << " " << y << endl;
                    if (res.size() == n*m)
                        return res;
                    res.push_back(matrix[x][y]);
                }
                yend = y-1;
                x = xend;
            }
            //cout << "ys: " << ys << " yend: " << yend << endl;     
            
            if (ys <= yend) {
                for (y = yend; y >= ys; y--) {
                    //cout << x << " " << y << endl;
                    if (res.size() == n*m)
                        return res;
                    res.push_back(matrix[x][y]);
                }
                xend = x-1;
                y = ys;
            } 
            //cout << "xs: " << xs << " xend: " << xend << endl;      
            if (xs <= xend) {
                for (x = xend; x >= xs; x--) {
                    //cout << x << " " << y << endl;
                    if (res.size() == n*m)
                        return res;
                    res.push_back(matrix[x][y]);
                }
                ys = y+1;
                x = xs;
            }
            //cout << "ys: " << ys << " yend: " << yend << endl;   
            //cout << res.size() << endl;
        }
        return res;
    }
};
