    //sort the array-->so that it will for a continous sequence
    //We will apply binarySearch on answer
    //we will take a window of size mid and with the help of prefix sum find if 
    //it is fessible or not
    typedef long long int ll;
    bool isPossible(vector<int>& nums, long long K,int mid,vector<ll> prefix){
        int n=nums.size();
        int i=0;
        int j=mid-1;

          while(j < n) {
            ll target_idx = (i+j) / 2;
            ll target     = nums[target_idx];
            
            
            ll operations_left  = 0;
            ll operations_right = 0;
            
            if(target_idx == 0) {
                operations_left = 0;
            } else {
                operations_left = abs(((target_idx - i) * target) - (prefix[target_idx-1] - (i > 0 ? prefix[i-1] : 0)));
            }
            
            operations_right    = abs(((j - target_idx) * target) - (prefix[j] - prefix[target_idx]));
          
            if(operations_right + operations_left <= K) {
                return true;
            }
            
            i++;
            j++;
        }

        return false;
    }
    int maxFrequencyScore(vector<int>& nums, long long k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<ll> prefix(n,0);
        prefix[0]=(ll)nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }

        int s=1;
        int e=n;
        int mid=s+(e-s)/2;
        int ans=0;
        while(s<=e){
            if(isPossible(nums,k,mid,prefix)){
              ans=mid;
              s=mid+1;
            }
            else{
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }

        return ans;
    }

    // sIMILAR Question->1838. Frequency of the Most Frequent Element
    class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int ans=1;
        int n=nums.size();
        vector<long long> prefixSum(n,0);
        prefixSum[0]=nums[0];

        for(int i=1;i<n;i++){
            prefixSum[i]=prefixSum[i-1]+nums[i];
        }
        long long actualSum=0;
        for(j=0;j<nums.size();j++){
            long long hypoSum=(j-i+1)*(long long)nums[j];
            actualSum+=nums[j];
            int operation=hypoSum-actualSum;

            while(operation>k){
                actualSum-=nums[i];
                i++;
                hypoSum=(j-i+1)*(long long)nums[j];
                operation=hypoSum-actualSum;
            }
            ans=max(ans,j-i+1);
        }

        return ans;
    }
};