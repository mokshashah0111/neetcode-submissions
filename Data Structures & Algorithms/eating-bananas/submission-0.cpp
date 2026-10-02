class Solution {
public:
    bool canEat(int r, int h, vector<int>& piles){
        double t = 0;
        for(int& b: piles){
            t += ceil((double)b/r);
        }
        return (int)t<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int low = 1;
        int high = piles[piles.size()-1];
        int minRate;
        while(low <= high){
            int mid = (low + (high-low)/2);
            if(canEat(mid,h,piles)){
                minRate = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return minRate;
    }
};
