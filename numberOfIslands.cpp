#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> arr , int i , int j , vector<vector<bool>> & visited){
    if(i < 0 || i >= arr.size() || j < 0 || j >= arr[0].size() || arr[i][j] == 1 || visited[i][j] == true){
        return;
    }
    visited[i][j] = true;
    
    dfs(arr , i - 1 , j , visited);
    dfs(arr , i , j + 1 , visited);
    dfs(arr , i + 1 , j , visited);
    dfs(arr , i , j - 1 , visited);
    
}

int main()
{
    int n, m;
    cin >> n;
    cin >> m;

    vector<vector<int>> arr;

    for (int i = 0; i < n; i++)
    {
        vector<int> ans;
        for (int j = 0; j < m; j++)
        {
            int res;
            cin >> res;
            ans.push_back(res);
        }
        arr.push_back(ans);
    }

    vector<vector<bool>> visited(n, vector<bool> (m, false)) ;

    int count = 0;
    
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(arr[i][j] == 0 && visited[i][j] == false){
                dfs(arr , i , j , visited);
                count++;
            }
        }
    }
    cout << count << endl;
}