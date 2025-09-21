class Solution {
public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        if(nums1 == nums2) return 0;
        queue<vector<int>> q;
        set<vector<int>> seen;
        int steps=0, n=nums1.size();
        q.push(nums1);
        seen.insert(nums1);
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto v = q.front();
                q.pop();
                for(int l=0; l<n; l++){
                    for(int r=l; r<n; r++){
                        //we have the subarray to be cut
                        //now lets choose where to insert it
                        vector<int> cut(v.begin() + l, v.begin() + r + 1);
                        vector<int> left;
                        for (int j = 0; j < n; j++) {
                            if (j < l || j > r) left.push_back(v[j]);
                        }
                
                        for (int pos = 0; pos <= (int)left.size(); pos++) {
                            vector<int> temp = left;
                            temp.insert(temp.begin() + pos, cut.begin(), cut.end());
                
                            if (temp == nums2) return steps + 1;
                            if (!seen.count(temp)) {
                                seen.insert(temp);
                                q.push(temp);
                            }
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};