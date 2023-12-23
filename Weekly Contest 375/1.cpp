// 2960. Count Tested Devices After Test Operations
class Solution {
public:
    void operation(int index,vector<int>& batteryPercentages){
        for(int i=index;i<batteryPercentages.size();i++){
            batteryPercentages[i] = max(0, batteryPercentages[i] - 1);
        }
    }
    int countTestedDevices(vector<int>& batteryPercentages) {
        int count=0;
         for(int i=0;i<batteryPercentages.size();i++){
             if(batteryPercentages[i]>0){
                 count++;
                 operation(i,batteryPercentages);
             }
         }
        
        return count;
    }
};