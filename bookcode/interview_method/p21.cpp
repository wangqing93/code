#include <iostream>
#include <bitset>

using namespace std;

#define word unsigned short  //must mark word
#define byte unsigned char
#define word_hi(x) ((byte)((word)(x)>>8))
#define word_lo(x) ((byte)((word)(x) & 255))


int main()
{
    word x = 1000;
    cout << x << endl;
    printf("%u\n",word_hi(x));    //3*256+232
    printf("%u\n",word_lo(x));  // %u unsigned int 32
    cout << "Hello world!" << endl;
    return 0;
}
