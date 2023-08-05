
bool isSafe(int i, int j, vector<vector<int> > &arr){
    int n = arr.size();
    int m = arr[0].size();

    if(i>=0 and i<n and j>=0 and j<m and arr[i][j] != -1)
        return true;
    
    return false;
}

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void f(int row, int col, vector<vector<int> > &arr, int count, int &ways){
    if(arr[row][col] == 2 and count == 0){
        ways++;
        return;
    }
    int temp = arr[row][col];
    arr[row][col] = -1;

    for(int i=0;i<4;i++){
        int new_row = row + dx[i];
        int new_col = col + dy[i];

        if(isSafe(new_row, new_col, arr)){
            f(new_row, new_col, arr, count - 1, ways);
        }
    }
    arr[row][col] = temp;
}

int Solution::solve(vector<vector<int> > &arr) {
    int n = arr.size();
    int m = arr[0].size();

    int count = 1, si = 0, sj = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == 1){
                si = i;
                sj = j;
            }
            if(arr[i][j] == 0){
                count++;
            }
        }
    }
    int ways = 0;

    f(si, sj, arr, count, ways);

    return ways;
}
