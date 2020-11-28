#include <iostream>
#include "include\LandOwner.h"
using namespace std;
int main()
{
    LandOwner* ptr_landOwner1 = new LandOwner();
    LandOwner *ptr_landOwner2 = new LandOwner("刘彪");
    LandOwner *ptr_landOwner3 = new LandOwner("王谦");

    return 0;
}
