class Solution {
public:
    /*vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        //题意理解清楚，最短转换序列，所以需要BFS，两个节点是否有关系用map【只相差一个字符】
        vector<vector<string>> res;
        map<string, vector<string>> relations;
        wordList.push_back(beginWord);
        for (int i = 0; i < wordList.size(); i++) {
            vector<string> onlyOneC;
            for (int j = 0; j < wordList.size(); j++) {
                //compare wordlist[i] wordlist[j]
                if (wordList[j] == wordList[i])
                    continue;
                int count = 0;
                for (int k = 0; k < beginWord.length(); k++) {
                    if (wordList[i][k] != wordList[j][k])
                        count++;
                    if (count > 1)
                        break;
                }
                //cout << wordList[j] << " " << count << endl;
                if (count == 1) {
                    onlyOneC.push_back(wordList[j]);
                }
            }
            relations.insert(make_pair(wordList[i], onlyOneC));
        }
        vector<pair<string, vector<string>>> temp;
        vector<pair<string, vector<string>>> nextTemp;
        vector<string> path;
        path.push_back(beginWord);
        temp.push_back(make_pair(beginWord, path));
        bool occurEndWord = false;
        int step = 0;
        while(!occurEndWord && !temp.empty()) {
            //cout << "********: " << step << endl;
            for (int i = 0; i < temp.size(); i++) {
                pair<string, vector<string>> one;
                one = temp[i];
                vector<string> onePath = one.second;
                vector<string> edges = relations[one.first];
                for (int j = 0; j < edges.size(); j++) {
                    bool flag = false;
                    for (int k = 0; k < onePath.size(); k++) {
                        if (edges[j] == onePath[k]) {
                            flag = true;
                            break;
                        }
                    }
                    if (!flag) {
                        onePath.push_back(edges[j]);
                        nextTemp.push_back(make_pair(edges[j], onePath));
                        if (edges[j] == endWord) {
                            occurEndWord = true;
                            res.push_back(onePath);
                        }
                        onePath.pop_back();
                    }
                }
                //cout << one.first << " ";
            }
            //cout << endl;
            temp.clear();
            temp.assign(nextTemp.begin(), nextTemp.end());
            nextTemp.clear();
            step++;
        }
        return res;
    }*/

    //以上方法超时了，优化边

    /*vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        //题意理解清楚，最短转换序列，所以需要BFS，两个节点是否有关系用map【只相差一个字符】
        vector<vector<string>> res;
        map<string, vector<string>> relations;
        wordList.push_back(beginWord);

        // alone wordList;
        map<string, bool> isExistWord;
        vector<string> aloneWord;
        for (int i = 0; i < wordList.size(); i++) {
            if (isExistWord.find(wordList[i]) == isExistWord.end()) {
                isExistWord.insert(make_pair(wordList[i], true));
                aloneWord.push_back(wordList[i]);
            }
        }
        wordList.assign(aloneWord.begin(), aloneWord.end());
        for (int i = 0; i < wordList.size(); i++) {
            vector<string> onlyOneC;
            for (int j = 0; j < wordList.size(); j++) {
                //compare wordlist[i] wordlist[j]
                if (wordList[j] == wordList[i])
                    continue;
                int count = 0;
                for (int k = 0; k < beginWord.length(); k++) {
                    if (wordList[i][k] != wordList[j][k])
                        count++;
                    if (count > 1)
                        break;
                }
                //cout << wordList[j] << " " << count << endl;
                if (count == 1) {
                    onlyOneC.push_back(wordList[j]);
                }
            }
            relations.insert(make_pair(wordList[i], onlyOneC));
        }
        vector<pair<string, vector<string>>> temp;
        vector<pair<string, vector<string>>> nextTemp;
        vector<string> path;
        path.push_back(beginWord);
        temp.push_back(make_pair(beginWord, path));
        bool occurEndWord = false;
        int step = 0;
        map<string, bool> isTraverse;
        isTraverse.insert(make_pair(beginWord, true));
        while(!occurEndWord && !temp.empty()) {
            cout << "********: " << step << endl;
            for (int i = 0; i < temp.size(); i++) {
                pair<string, vector<string>> one;
                one = temp[i];
                vector<string> onePath = one.second;
                vector<string> edges = relations[one.first];
                for (int j = 0; j < edges.size(); j++) {
                    if (isTraverse.find(edges[j]) != isTraverse.end())
                        continue;
                    onePath.push_back(edges[j]);
                    nextTemp.push_back(make_pair(edges[j], onePath));
                    //edges的边可以删掉one.first

                    if (edges[j] == endWord) {
                        occurEndWord = true;
                        res.push_back(onePath);
                    }
                    onePath.pop_back();
                }
                cout << one.first << " ";
            }
            cout << endl;
            temp.clear();
            temp.assign(nextTemp.begin(), nextTemp.end());
            nextTemp.clear();
            for (int i = 0; i < temp.size(); i++) {
                isTraverse.insert(make_pair(temp[i].first, true));
            }
            step++;
        }
        return res;
    }
*/
    //以上方法还是超时，那把边的关系从map改为vector

    //判断两个单词能否互相转换
    bool check_transform(string &str1, string &str2){
        int count = 0;
        for (int i = 0; i < str1.length(); i++) {
            if (str1[i] != str2[i])
                count++;
            if (count > 1)
                return false;
        }
        return true;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

        unordered_map<string, int> wordId;  //word->ID的映射
        vector<string> idWord;  //ID->word的映射
        vector<vector<int>> edges;  //构造图

        int id = 0;
        for(int i = 0; i < wordList.size(); i++){

            if(!wordId.count(wordList[i])){

                wordId[wordList[i]] = id++;   //去重复编号
                idWord.push_back(wordList[i]);  //该编号的字符串
            }
        }

        if(!wordId.count(endWord))
            return {};  //不存在结束单词，返回空
        
        if(!wordId.count(beginWord)){

            wordId[beginWord] = id++;   //加入起始单词
            idWord.push_back(beginWord);
        }
            

        //构造图
        edges.resize(id);  //相当于有id个点，双向边，简单粗暴
        for(int i = 0; i < idWord.size(); i++){

            for(int j = i + 1; j < idWord.size(); j++){

                if(check_transform(idWord[i], idWord[j])){

                    edges[i].push_back(j);
                    edges[j].push_back(i);  //构造两条有向边
                }
            }
        }

        int endWord_id = wordId[endWord];
        vector<vector<string>> res;
        queue<vector<int>> q;
        q.push(vector<int>{wordId[beginWord]}); //起始单词作为一个路径入队

        //cost[id]：从起始单词出发，转换到id所代表的单词所需的次数(代价)，记录步数，而不是记录一层
        vector<int> cost(id, INT_MAX);
        cost[wordId[beginWord]] = 0;

        while(!q.empty()){

            vector<int> now_path = q.front();
            q.pop();

            int last_word_id = now_path.back();
            
            //当前路径最后一个为结束单词时
            if(last_word_id == endWord_id){

                vector<string> temp;
                for(int i = 0; i < now_path.size(); i++){

                    temp.push_back(idWord[now_path[i]]);
                }
                res.push_back(temp);
            }
            else{

                for(int i = 0; i < edges[last_word_id].size(); i++){

                    //路径最后一个单词的连接单词
                    int next = edges[last_word_id][i];
                    if(cost[last_word_id] + 1 <= cost[next]){  //没有被访问过，或者同层访问，巧妙的思路

                        cost[next] = cost[last_word_id] + 1; //更新转换次数 

                        vector<int> temp(now_path.begin(), now_path.end());
                        temp.push_back(next); // 把路径加进去
                        q.push(temp);
                    }
                }
            }
        }
        return res;
    }
};
