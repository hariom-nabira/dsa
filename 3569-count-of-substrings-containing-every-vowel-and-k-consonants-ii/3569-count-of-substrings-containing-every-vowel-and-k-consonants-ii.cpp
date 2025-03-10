class Solution {
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:
    long countOfSubstrings(string word, int k) {
        long numValidSubstrings = 0;
        int start = 0;
        int end = 0;
        unordered_map<char, int> vowelCount;
        int consonantCount = 0;

        vector<int> nextConsonant(word.size());
        int nextConsonantIndex = word.size();
        for (int i = word.size() - 1; i >= 0; i--) {
            nextConsonant[i] = nextConsonantIndex;
            if (!isVowel(word[i])) {
                nextConsonantIndex = i;
            }
        }

        while (end < word.size()) {
            char newLetter = word[end];

            if (isVowel(newLetter)) {
                vowelCount[newLetter]++;
            } else {
                consonantCount++;
            }

            while (consonantCount > k) {
                char startLetter = word[start];
                if (isVowel(startLetter)) {
                    vowelCount[startLetter]--;
                    if (vowelCount[startLetter] == 0) {
                        vowelCount.erase(startLetter);
                    }
                } else {
                    consonantCount--;
                }
                start++;
            }

            while (vowelCount.size() == 5 &&
                   consonantCount == k) {
                numValidSubstrings += nextConsonant[end] - end;
                char startLetter = word[start];
                if (isVowel(startLetter)) {
                    vowelCount[startLetter]--;
                    if (vowelCount[startLetter] == 0) {
                        vowelCount.erase(startLetter);
                    }
                } else {
                    consonantCount--;
                }

                start++;
            }
            end++;
        }

        return numValidSubstrings;
    }
};


// class Solution {
// public:
//     unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
//     bool hasAllVowels(unordered_map<char,int> &mp){
//         int a = mp['a'], e = mp['e'], i = mp['i'], o = mp['o'], u = mp['u'];
//         return (a && e && i && o && u);
//     }
//     long long countOfSubstrings(string word, int k) {
//         long long ans=0;
//         int n=word.size(), l=0, conso=0;
//         unordered_map<char,int> mp;
//         for(int r=0; r<n; r++){
//             mp[word[r]]++;
//             if(!vowels.contains(word[r])) conso++;
//             while(conso>k){
//                 if(!vowels.contains(word[l])) conso--;
//                 mp[word[l++]]--;
//             }
//             if(conso==k && hasAllVowels(mp)){
//                 ans++;
//             }
//         }
//         return ans;
//     }
// };