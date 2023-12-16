//2957_RemoveAdjacentAlmostEqualCharacters.
class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int count=0;
        for(int i=0;i<word.length()-1;i++){
            if(word[i]==word[i+1] || abs(word[i]-word[i+1])==1){
                count+=2;
                i++;
            }
        }
        
        return count/2;
    }
};