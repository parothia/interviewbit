// Given an array of strings, return all groups of strings that are anagrams. Represent a group by a list of integers representing the index in the original list. Look at the sample case for clarification.
//     Anagram : a word, phrase, or name formed by rearranging the letters of another, such as 'spar', formed from 'rasp' 
//     Note: All inputs will be in lower-case. 
// Example :
// Input : cat dog god tca
// Output : [[1, 4], [2, 3]]
// cat and tca are anagrams which correspond to index 1 and 4.
// dog and god are another set of anagrams which correspond to index 2 and 3.
// The indices are 1 based ( the first element has index 1 instead of index 0).

vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    unordered_map<string,vector<int>> umap;
    for(int i=0;i<A.size();i++) {
        string str=A[i];
        sort(str.begin(),str.end());
        if(umap.find(str)!=umap.end())
            umap[str].push_back(i+1);
        else umap[str].push_back(i+1);
    }
    vector<vector<int>> res;
    for(auto it=umap.begin();it!=umap.end();it++) {
        res.push_back(it->second);
    }
    return res;
