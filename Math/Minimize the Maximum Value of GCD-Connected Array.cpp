class Solution {
public:
    long long minimumMaxValue(int n, int index, int value) {
        //Step 1 find smallest factor
        if(value == 1) return -1;
        long long minFactor = INT_MAX, location = 1;
        long long left = 0, right = 0, leftind = 0, rightind = 0;

        for(long long i = 1 ; i * i <= value ; i++){
            if(i != 1 && value % i == 0){
                minFactor = min(minFactor, i);
                location = value / i;
                break;
            }
        }
        if(minFactor == INT_MAX) minFactor = value;
        if(value % 2 == 0){
            if((location - index) > 0){
                return ((n-1-index)+location)*minFactor;
            }
            return -1;
        }
        
        left = value, right = value;
        leftind = index, rightind = index;

        while(left % 2 != 0){
            left -= minFactor;
            leftind--;
            if(leftind >= 0 && left <= 0) return -1;
        }

        while(right % 2 != 0){
            if((left - leftind*2) > 0 && rightind == n-1) return right;
            right += minFactor;
            rightind++;
        }
        if((left - leftind*2) > 0){
            return ((n-1-rightind)*2 + right);
        }
        return -1;
    }
};
