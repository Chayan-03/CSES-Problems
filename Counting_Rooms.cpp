# include<bits/stdc++.h>
using namespace std;

void dfs(int i,int j,vector<vector<int>> &vis,vector<vector<char>> &mat){
  vis[i][j]=1;
  int n = mat.size();
  int m = mat[0].size();
  int delrow[] = {-1,0,1,0};
  int delcol[] = {0,1,0,-1};
  for(int k=0;k<4;k++){
    int nrow = i+delrow[k];
    int ncol = j+delcol[k];
    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && mat[nrow][ncol]=='.' && vis[nrow][ncol]==0){
      dfs(nrow,ncol,vis,mat);
    }
  }
}
int main(){
  int n,m;
  int ans = 0;
  cin>>n>>m;
  vector<vector<char>> mat(n,vector<char>(m));
  vector<vector<int>> vis(n,vector<int>(m,0));
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>mat[i][j];
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(mat[i][j]=='.' && vis[i][j]==0){
        dfs(i,j,vis,mat);
        ans++;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}