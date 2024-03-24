/*
Approach :     
    1. Use fast & slow with strides 2 & 1 to move from index 0.
    2. When they meet, there is a cycle within the path, i.e., a duplicative number.
    3. Reset slow to slow=nums[0], traverse both with stride 1 until they meet; 
       the meet point is the entrance for the cycle; return slow or fast
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Use fast and slow
        int slow = nums[0];
        int fast = nums[0];
        // if they meet, duplicative number occur
        // i.e. cycle
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(fast != slow);

        // reset slow to start, and traverse same way
        slow = nums[0];
        while(slow != fast){
            fast = nums[fast];
            slow = nums[slow];
        }

        return slow;
    }
};
