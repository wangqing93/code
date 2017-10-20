#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

class RandomizedSet {
public:
    vector<int> data;
    unordered_map<int, int> mark;
    /** Initialize your data structure here. */
    RandomizedSet() {
        data.clear();
        mark.clear();
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (mark.find(val) != mark.end())
            return false;
        mark[val] = data.size();
        data.push_back(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (mark.find(val) == mark.end())
            return false;
        mark[data[data.size()-1]] = mark[val];
        swap(data[mark[val]], data[data.size()-1]);
        mark.erase(val);
        data.pop_back();
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return data[rand()%(data.size())];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
