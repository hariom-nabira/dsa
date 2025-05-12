class Solution {
private:
    set<int> ans;
public:
    void checkAndForm(int a, int b, int c){
        if(a!=0 && c%2==0){
            ans.insert(a*100 + b*10 + c);
        }
    }
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n=digits.size();
        sort(digits.begin(), digits.end());
        for(int a=0; a<n; a++){
            for(int b=a+1; b<n; b++){
                for(int c=b+1; c<n; c++){
                    int i=digits[a], j=digits[b], k=digits[c];
                    checkAndForm(i,j,k);
                    checkAndForm(i,k,j);
                    checkAndForm(j,i,k);
                    checkAndForm(j,k,i);
                    checkAndForm(k,i,j);
                    checkAndForm(k,j,i);
                }
            }
        }
        vector<int> ans1(ans.begin(), ans.end());
        return ans1;
    }
};