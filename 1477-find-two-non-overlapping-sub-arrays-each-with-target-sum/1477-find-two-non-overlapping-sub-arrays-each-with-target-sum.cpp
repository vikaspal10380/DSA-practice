class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int left = 0;
        int sum = 0;
        int prevMin = INT_MAX;
        int ans = INT_MAX;
        vector<int> best(arr.size(), INT_MAX);

        for(int right=0; right<arr.size(); right++){
            sum += arr[right];
            while(sum > target){
                sum -= arr[left];
                left++;
            }
            if (right > 0) {
                best[right] = best[right - 1];
            }
            if(sum == target){
                int len = right-left+1;
                if (left > 0 && best[left - 1] != INT_MAX) {
                    ans = min(ans, len + best[left - 1]);
                }

                // Current subarray becomes a candidate
                prevMin = min(prevMin, len);
                best[right] = min(best[right], prevMin);
            }
        }
        if(ans == INT_MAX){
            return -1;
        }
        else{
            return ans;
        }
    }
};