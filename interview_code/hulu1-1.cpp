#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stdio.h>

using namespace std;


struct View
{
    int x, y, width, height;
    vector<View*>  children;
    void onTouch()
    {
        //
        return;
    };
};

struct Point
{
   int x, y;
};

// To execute C++, please define "int main()"

bool judge(View* root, Point p)
{
  int x = root->x;
  int y = root->y;
  int width = root->width;
  int height = root->height;

  int xMax = root->x +width;
  int yMax = root->y + height;

  if ((p.x >= x && p.x <= xMax) && (p.y >= y && p.y <= yMax))
    return true;
  return false;
}

void oneTouch(View* root, Point p)
{
  bool flag = false;
  if (judge(root, p))
  {
    for (int i = 0; i < root->children.size(); i++) //如果孩子都不包含这个点，应该调用touch
    {
      if (judge(root->children[i], p))
      {
        oneTouch(root->children[i], p);
        flag = true;
        break;
      }
    }
    if (flag == false)
      root->onTouch();
  }
}


void multipleTouch(View& root, const vector<Point>& points)
{
  View* panel = &root;
  for (int i = 0; i < points.size(); i++)
  {
    oneTouch(panel, points[i]);
  }

}



int main() {
  return 0;
}
/*
struct View
  {
    int x, y, width, height;
    vector<View*>  children;
    void onTouch();
  }
  struct Point
  {
   int x, y;
  }
实现 void multipleTouch(View& root, const vector<Point>& points); //使每个view都能调用对应的onTouch

*/
