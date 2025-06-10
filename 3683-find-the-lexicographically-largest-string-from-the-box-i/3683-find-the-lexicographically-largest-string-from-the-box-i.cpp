class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends==1) return word;
        vector<int> freq(26);
        for(auto &ch: word) freq[ch-'a']++;
        int ch=25, n=word.size();
        while(!freq[ch]) ch--;
        priority_queue<string> pq;
        for(int i=0; i<n; i++){
            if(word[i]==('a'+ch)){
                pq.push(word.substr(i, n-numFriends+1));
            }
        }
        return pq.top();
    }
};