#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

// consider one world many times
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.size() == 0)
        {
            return res;
        }
        unordered_map<string, int> markWord;
        for (int i = 0; i < words.size(); i++)
        {
            if (markWord.find(words[i]) != markWord.end())
                markWord[words[i]]++;
            else
                markWord.insert(make_pair(words[i], 1));
        }
        unordered_map<string, int> tempMarkWord;
        int sublen = words[0].length(), alllen = sublen*words.size();
        string subword;
        bool flag;
        int i,j;
        for (i = 0; i < s.length()-alllen+1; i++)
        {
            tempMarkWord = markWord;
            flag = true;
            for (j = i; j < i+alllen; j=j+sublen)
            {
                subword = s.substr(j,sublen);
                unordered_map<string, int>::const_iterator temp = tempMarkWord.find(subword);
                if (temp != tempMarkWord.end())
                {
                    if (temp->second == 0)
                    {
                        break;
                    }
                    else
                    {
                      tempMarkWord[subword]--;
                    }
                }else
                    break;
            }
            for (auto tempmap = tempMarkWord.begin();tempmap!=tempMarkWord.end(); ++tempmap)
            {
                if (tempmap->second != 0)
                {
                    flag = false;
                    break;
                }
            }
            if (flag == true)
            {
                res.push_back(j-alllen);
            }

        }
        return res;
    }
};

int main()
{
    string s, temp;
    cin >> s;
    vector<string> words;
    for (int i = 0; i<2; i++)
    {
        cin >> temp;
        words.push_back(temp);
    }
    vector<int> res;
    Solution test;

    res = test.findSubstring(s, words);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    return 0;
}
