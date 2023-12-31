// class Solution {
// public:
//     vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
//         int m = mat.size();
//         int n = mat[0].size();
//         unordered_map<int,vector<int>>mp;

//         for(int i=0; i<m; i++){
//             for(int j=0; j<n; j++){
//                 mp[i-j].push_back(mat[i][j]);
//             }
//         }

//         for(auto &it : mp){
//             sort(it.second.begin() , it.second.end());
//         }

//         vector<vector<int>>ans(m,vector<int>(n,0 ));  
//         for(int i=m-1; i>=0; i--){
//             for(int j=n-1; j>=0; j--){
//                 ans[i][j] = mp[i-j].back();
//                 mp[i-j].pop_back();
//             }
//         }

//         return ans;
//     }
// };



class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        unordered_map<int,
                priority_queue<int,vector<int>,greater<int>>>mp;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                mp[i-j].push(mat[i][j]);
            }
        }

        vector<vector<int>>ans(m,vector<int>(n,0));  
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans[i][j] = mp[i-j].top();
                mp[i-j].pop(); 
            }
        }

        return ans;
    }
};
