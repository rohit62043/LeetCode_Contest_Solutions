// 2959. Number of Possible Sets of Closing Branches
class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        int count=0;
        for(int set=0;set<1<<n;set++){
            vector<vector<int>> adjMatrix(n,vector<int>(n,1e9));
            bool flag=true;
            for(auto x:roads){
                int u=x[0];
                int v=x[1];
                int wt=x[2];
                if(set>>u&1==1 && set>>v&1==1){
                    adjMatrix[u][v]=min(adjMatrix[u][v],wt);
                    adjMatrix[v][u]=min(adjMatrix[v][u],wt);
                }
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i==j){
                        adjMatrix[i][j]=0;
                    }
                }
            }
            for(int helper=0;helper<n;helper++){
                for(int src=0;src<n;src++){
                    for(int dest=0;dest<n;dest++){
                        adjMatrix[src][dest]=min(adjMatrix[src][dest],adjMatrix[src][helper]+adjMatrix[helper][dest]);
                    }
                }
            }

            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i==j){
                        continue;
                    }
                    if(set>>i&1==1 && set>>j&1==1){
                        if(adjMatrix[i][j]>maxDistance){
                           flag=false;
                           break;
                        }
                    }
                }
            }

            if(flag){
                count++;
            }
        }

        return count;
    }
};