class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        // KEY OBSERVATION : **edges is useless!!**
        // if we pick any two nodes (say u & v) then there is always a path between them
        // and even more impressive is the fact that if operations are performed on every edge in this path then only u & v change values (rest all nodes in path had xor done twice therefore origin value remains; a^b^b = a)
        // therefore we can pick any two nodes and apply changes to their values if it benefits us (a change coverts original value into xored value)
        // OBSERVATION 2: after any valid sequesnce of operations an even number of values would be changed
        int n = nums.size();
        long long sum=0;
        int nodesChanged=0, minPositive=INT_MAX, maxNegative=INT_MIN;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int change = (nums[i]^k)-nums[i];
            if(change>0){
                sum+=change;    //any positive change is desired
                nodesChanged++;
                minPositive = min(minPositive,change);
            }else{
                maxNegative = max(maxNegative,change);
            }
        }
        if(nodesChanged % 2 == 0)
            return sum;         //if even number of nodes changed then these can be divided into pairs
        else
            return max(sum - minPositive, sum + maxNegative); //if odd number of nodes changed then to make it even we drop one node that was included (obviously dropping the one which contributed least +ve change) or we add another node (all available choices of nodes left have -ve changes so we take the maxNegative (least manginute wala -ve number))
    }
};