class Solution {
public:
    int findRem(int low, int high, vector<int>& numbers, int target){
        while(low<=high){
            int mid = low + ((high-low)/2);
            if(numbers[mid] == target)return mid;
            else if(numbers[mid] < target)low = mid+1;
            else high = mid-1;
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i =0;i<numbers.size();i++){
            int index1 = i+1;
            int rem = target- numbers[i];
            int index2 = findRem(i+1,numbers.size()-1,numbers, rem);
            if( index2 != -1) return {index1,index2+1}; 
        }
        return {-1,-1};
    }
};
