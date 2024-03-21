class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) 
            return 0;
        
        //After doing below three statements our unordered_map looks like this
        //it will store value and vector<int> will store indices of that value    
            //-23: [1, 2],
            //3: [8],
            //23: [5, 6, 7],
            //100: [0, 4],
            //404: [3, 9] 

        unordered_map<int, vector<int>> indices;
        for (int i = 0; i < n; i++) {
            indices[arr[i]].push_back(i);
        }
        //queue will store index of adjacent element
        queue<int> storeIndex;
        //visited will take care wheather the particular index is visited or not
        vector<bool> visited(n);
        storeIndex.push(0);
        visited[0] = true;
        int steps = 0;
        while (!storeIndex.empty()) {
            int size = storeIndex.size();
            while (size--) {
                int currIndex = storeIndex.front();
                storeIndex.pop();
                if (currIndex == n - 1) 
                    return steps;
                vector<int>& jumpNextIndices = indices[arr[currIndex]];
                jumpNextIndices.push_back(currIndex - 1);
                jumpNextIndices.push_back(currIndex + 1);
                for (int jumpNextIndex : jumpNextIndices) {
                    if (jumpNextIndex >= 0 && jumpNextIndex < n && !visited[jumpNextIndex]) {
                        storeIndex.push(jumpNextIndex);
                        visited[jumpNextIndex] = true;
                    }
                }
                jumpNextIndices.clear();
            }
            steps++;
        }
        return -1; // unreachable
    }
};