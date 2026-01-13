class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double sum = 0;
        double mn = 1e9, mx = 0;
        
        for(auto& sq : squares) {
            int y = sq[1], l = sq[2];
            sum += 1.0*l * l;
            mn = min(mn, 1.0*y);
            mx = max(mx, 1.0*(y+l));
        }

        double l = mn, r = mx;
        
        while(r - l > 1e-5) {
            double mid = l + (r-l)/2;
            double are = 0;
            
            for(auto& sq : squares) {
                int y = sq[1], l = sq[2];
                double yTop = y + l;
                
                if(yTop <= mid) continue; 
                else if (y >= mid) are += 1.0 * l * l;
                else {
                    double over = yTop - mid;
                    are += over * l;  
                }
            }
            
            double are2 = sum - are;
            
            if(are > are2) {
                l = mid;  
            } else {
                r = mid; 
            }
        }

        return l;
    }
};
