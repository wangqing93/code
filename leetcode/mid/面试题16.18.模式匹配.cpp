/*
这个题目可能考验人的思维缜密度
bug 1： 
"ab"
""
value="" 特殊判断

bug2：
"bbbaa"
"xxxxxxy"
if 条件用这个判断：value.length()-tryStartLength*startNum，不行，非要赋值为int，数据紊乱


bug3：
"a"
"zqvamqvuuvvazv"
遍历x代表的字符串的时候，它的长度是0-value.length()
*/

class Solution {
public:
    bool patternMatching(string pattern, string value) {
        //可以遍历ab可能出现的字符，然后对比和value是不是相等，如果有相等的，证明匹配上了，如果没有则没有
        //整个可以做一个递归，比如a先匹配上了，递归继续匹配
        //a的长度确定之后，b的长度也就确定了
        //a的长度遍历是0-n的复杂度，对比每一次需要n，所以是一个n*n
        if (pattern.length() == 0)
            return value.length() == 0 ? true:false; 
        
        char startChar = pattern[0];
        int startNum = 0;
        int nextNum = 0;
        for (int i = 0; i <pattern.length(); i++) {
            if (pattern[i] == startChar) {
                startNum++;
            } else {
                nextNum++;
            }
        }
        if (value == "" ){
            return nextNum==0?true:false;
        }
        int tryStartLength = 0;
        int tryNextLength = 0;
        
        for (int i = 0; i <=value.length(); i++) {
            tryStartLength = i;
           //cout << value.length() << " "  << tryStartLength << " " <<  startNum <<  endl;
           int temp = value.length()-tryStartLength*startNum;
           
            if (temp < 0)
                continue;
            //cout <<tryStartLength << " : " <<value.length()-(tryStartLength*startNum) << endl;
            if (nextNum!=0 && (value.length()-tryStartLength*startNum)%nextNum!=0)
                continue;
            else {
                if (nextNum != 0)
                    tryNextLength = (value.length()-tryStartLength*startNum)/nextNum;
                //cout << tryStartLength << " " << tryNextLength << endl;
                string startPattern ="";
                string nextPattern ="";
                string patternValue="";
                int index = 0;
                for (int j = 0; j <pattern.length(); j++) {
                    if (pattern[j] == startChar) {
                        if (startPattern=="")
                            startPattern = value.substr(index, tryStartLength);
                        patternValue += startPattern;
                        index += tryStartLength;
                    } else {
                        if (nextPattern=="")
                            nextPattern = value.substr(index, tryNextLength);
                        patternValue += nextPattern;
                        index += tryNextLength;
                    }
                }
                
                bool flag = true;
                //cout << patternValue <<  " BEGIN  " << flag << endl;
                if (patternValue.length() != value.length())
                    continue;
                for (int j = 0; j < patternValue.length(); j++) {
                    if (patternValue[j] != value[j]) {
                        flag = false;
                        break;
                    }
                }
                //cout << patternValue <<  " END  " << flag << endl;
                if (flag)
                    return true;
            }
        }
        return false;
    }
};
