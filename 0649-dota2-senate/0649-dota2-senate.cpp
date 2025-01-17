class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<char> q(senate.begin(), senate.end());
        int rCount=0, dCount=0;
        while(1){
            int n = q.size(), reEnter=0;
            for(int i=0; i<n; i++){
                if(q.front()=='D'){
                    q.pop();
                    if(dCount){
                        dCount--;
                    }else{
                        rCount++;
                        q.push('D');
                        reEnter++;
                    }
                }else{
                    q.pop();
                    if(rCount){
                        rCount--;
                    }else{
                        dCount++;
                        q.push('R');
                        reEnter++;
                    }
                }
            }
            if(reEnter == n) break;
        }
        return (q.front()=='R')? "Radiant" : "Dire";
    }
};