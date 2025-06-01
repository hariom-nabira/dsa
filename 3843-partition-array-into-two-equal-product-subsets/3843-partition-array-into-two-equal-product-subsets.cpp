/* LOGIc
Since we want 2 partitions, each having prod==target, each element of both partition should divide target (i.e be a factor)
Now since elemnts are DISTINCT we can simply check if every element of the array is a factor of target.

IF elements were not distinct, then it would fail
Ex: nums=[2,2,2,2,2,2]; target=2
*/
class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        for(auto e:nums){
            if(target%e) return false;
        }
        return true;
    }
};