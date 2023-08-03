#include<bits/stdc++.h>

bool isValid(int i, int j, vector<vector<char>> &arr, vector<vector<int>> &visited){
    int n = arr.size();
    int m = arr[0].size();
    
    if(i>=0 and i<n and j>=0 and j<m and !visited[i][j] and arr[i][j] == '.')
        return true;
    
    return false;
}

bool bfs(int row, int col, vector<vector<char>> &arr, vector<vector<char>> &dir,         vector<vector<int>> &visited, vector<char> &path){
    queue<pair<int,int>> q;
    q.push({row, col});
    
    visited[row][col] = 1;
    
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        
        if(arr[i][j] == 'B'){
            while(1){
                path.push_back(dir[i][j]);
                
                if(path.back() == 'R') i--;
                if(path.back() == 'L') i++;
                if(path.back() == 'U') j--;
                if(path.back() == 'D') j++;
                
                if(i == row and j == col)
                    break;
            }
            return true;
        }
        
        if(isValid(i-1, j, arr, visited)){            // left
            visited[i-1][j] = 1;
            dir[i-1][j] = 'L';
            q.push({i-1, j});
        }
        if(isValid(i+1, j, arr, visited)){            // right
            visited[i+1][j] = 1;       
            dir[i+1][j] = 'R';
            q.push({i+1, j});
        }
        if(isValid(i, j-1, arr, visited)){            // up
            visited[i][j-1] = 1;
            dir[i][j-1] = 'U';
            q.push({i, j-1});
        }
        if(isValid(i, j+1, arr, visited)){            // down
            visited[i][j+1] = 1;
            dir[i][j+1] = 'D';
            q.push({i, j+1});
        }
    }
    
    return false;
}


int main(){
    int n, m;
    cin>>n>>m;
    
    vector<vector<char>> arr(n, vector<char> (m));
    vector<vector<char>> dir(n, vector<char> (m));
    vector<vector<int>> visited(n, vector<int> (m, 0));
    vector<char> path;
    
    int si = 0, sj = 0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            if(arr[i][j] == 'A') si = i, sj = j;
        }
    }
    
    if(bfs(si, sj, arr, dir, visited, path) == true){
        cout<<"YES"<<"\n";
        cout<< path.size()<<"\n";
        while(path.size() > 0){
            cout<<path.back();
            path.pop_back();
        }
    }
    else{
        cout<< "NO"<<"\n";
    }
    
}
