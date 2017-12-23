#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> t;
    t.resize(5,1);
    t.resize(3,1);
    for (int i = 0; i < t.size(); i++)
        cout << t[i];
    t.resize(6,1);t.reserve(4);
    for (int i = 0; i < t.size(); i++)
        cout << t[i];    //111111111
    return 0;
}


/*
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> t;
    t.resize(5,2);
    t.resize(3,1);
    for (int i = 0; i < t.size(); i++)
        cout << t[i];
    t.resize(6,3);t.reserve(4);
    for (int i = 0; i < t.size(); i++)
        cout << t[i];    //222222333
    return 0;
}

/*
