class Solution {
public:
    int findMin(vector<int>& v) {
        int st = 0, n = v.size();
        int en = n-1;
        int a = v[0];

        while(st <= en){
            int m = (st+en)/2;

            a = min(a, v[m]);
            // If mid element > first element of array 
            // this means that we need to look for the inflection point on the right of mid
            if(v[m] >= v[0]){   
                st = m+1;
            }
            // If mid element < first element of array 
            // this that we need to look for the inflection point on the left of mid.
            else {
                en = m-1;
            }
        }

        return a;
    }
};