#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stdio.h>

using namespace std;


struct Sequence
{
  int index;   //foo T2T3T4T5(index=0)    2->foo  T2T5 index++ ; 3->foo(T3T4 index++)
  vector<string> times;
};

void dealInput(string sT, string sName, string sOpt, unordered_map<int, string>& markOrder,
              unordered_map<string, Sequence>& markTimes, int enterIndex)
{
  if (sOpt == "enter")
    markOrder.insert(make_pair(enterIndex, sName));
  if (markTimes.find(sName) != markTimes.end())
  {
    markTimes[sName].times.push_back(sT);
  } else
  {
      vector<string> temp;
      temp.push_back(sT);
      Sequence markTemp;
      markTemp.index = 0;
      markTemp.times = temp;
      markTimes.insert(make_pair(sName, markTemp));
  }
}


void dealOutput(unordered_map<int, string> markOrder,
              unordered_map<string, Sequence> markTimes)
{
    for (int i = 0; i < markOrder.size(); i++)
    {
        for (int j = 0; j < i; j++)
            cout << " ";
        cout << markOrder[i] << "(";
        Sequence temp = markTimes[markOrder[i]];
        cout << temp.times[temp.times.size()-1-temp.index];
        cout << "-";
        cout << temp.times[temp.index];
        markTimes[markOrder[i]].index +=1;
        cout << ")";
        cout << endl;
    }
}



int main() {
  char s1[100], s2[100], s3[100];
  string str1, str2, str3;
  unordered_map<int, string> markOrder;
  unordered_map<string, Sequence> markTimes;
  int i = 0;
  int enterIndex = -1;

  while(scanf("%s%s%s",&s1,&s2,&s3)!= EOF)
  {
      str1 = (string)s1;
      str2 = (string)s2;
      str3 = (string)s3;
      if (str3 == "enter")
        enterIndex++;
      dealInput(s1, s2, s3, markOrder, markTimes, enterIndex);
  }
  dealOutput(markOrder, markTimes);
  return 0;
}

/*输入
T1 main enter
T2 foo enter
T3 foo enter
T4 foo exit
T5 foo exit
T6 main exit

输出
main(T6-T1)
  foo(T5-T2)
    foo(T4-T3)
*/