class Solution {
public:
    int findPeakElement(vector<int>& v) {
        int n = v.size();
        if(n == 1)
            return 0;
        if(n == 2){
            return (v[0] > v[1])? 0 : 1;
        }
        // v.push_back(INT_MIN);
        for(int i = 0; i < n; i++){
            if(i == 0){     // check for first element
                if(v[i] > v[i+1]){
                    return i; 
                }
            }
            else if(i == n-1){  // check for last element
                if(v[i] > v[i-1])
                    return i;
            }
            // if current element is greater than both its previous and next element
            else if(v[i] > v[i-1] && v[i] > v[i+1]){   
                return i;
            }
        }
        
        
        return -1;
    }
};