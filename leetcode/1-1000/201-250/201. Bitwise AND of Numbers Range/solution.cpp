class Solution {
public:

    int findNearestPowerOf2(int n){
        if(n <= 2){
            return n;
        }
        return pow(2, int(log(n)/log(2)));
    }

    int rangeBitwiseAnd(int left, int right) {

        if(left == right){
            return left;
        }

        // find nearest power of 2
        int l = findNearestPowerOf2(left);
        int r = findNearestPowerOf2(right);

        if(l != r) {
            return 0;
        }
        return l + rangeBitwiseAnd(left-l, right-l);
    }
};
