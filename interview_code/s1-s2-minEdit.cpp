//ÆÀ²âÌâÄ¿
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

struct node {
    node(int _x, int _y):x(_x), y(_y) {}
    int x, y;
    bool operator == (const node &t) const {
        return  x==t.x && y==t.y;
    }

};
unordered_map<node, int> mark;

int minEditTimes(string a, string b, int a_index, int b_index)
{
  if (a_index == 0)
  {
      mark.insert(make_pair(Node(0, b_index)), b_index);
      return b_index+1;
  }
if (b_index == 0)
{
    mark.insert(make_pair(Node(a_index, 0)), 0);
      return a_index+1;
}
  int min_temp = -1, temp;
  for (int i = 1; i <= a_index; i++)
  {
    unordered_map<int, int>::const_iterator oneres = mark.find(node(i-1, b_index-1));
    if (oneres != mark.end())
    {
        temp = oneres->second;
    } else
    {
      temp = minEditTimes(a, b, i-1, b_index-1);
    }
    if (a[i] != b[b_index])
        temp++;
    if (min_temp == -1 ||  min_temp > temp)
        min_temp = temp;
  }
  mark.insert(make_pair(Node(a_index, b_index)), min_temp);
  return min_temp;
}

int main()
{
  string a, b;
  cin >> a >> b;
  minEditTimes(a, b, a.length()-1, b.length()-1);
  return 0;
}





















