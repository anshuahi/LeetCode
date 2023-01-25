class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t x = 0;
        int i = 0;
        while(i < 32){
            x = x*2 + n%2;
            n = n/2;
            i++;
        }
        
        return x;
    }
};