class Solution {
public:

const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
      int n=mat.size();
      int m=mat[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>dis(n,vector<int>(m,0));
         queue<pair<pair<int,int>,int>>q;

         for(int i=0;i<n;i++){
             for(int j=0;j<m;j++){
                 if(mat[i][j]==0){
                     q.push({{i,j},0});
                     vis[i][j]=1;
                 }
                 else{
                     vis[i][j]=0;
                 }
             }
         }

         while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int steps=q.front().second;
            q.pop();
            dis[row][col]=steps;

            for(int i=0;i<4;i++){
                int nexti=row+dx[i];
                int nextj=col+dy[i];

                if(nexti>=0 &&nexti<n &&nextj>=0 && nextj<m &&vis[nexti][nextj]!=1 ){
                    vis[nexti][nextj]=1;
                    q.push({{nexti,nextj},steps+1});
                }
            }
         }

return dis;
        
        
    }
};
