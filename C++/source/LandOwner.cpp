#include "C:\Users\admin.000\Desktop\11\include\LandOwner.h"
LandOwner::LandOwner()
{
    SetName("默认地主");
    SetSex("保密");
    SetGold(1000);
    SetEpx(0);
    cout << "LandOwner()" << endl;
}

LandOwner::LandOwner(string name):m_name(name) {
    SetSex("保密");
    SetEpx(0);
    SetGold(1000);
    cout << "LandOwner(string name)" << endl;
}

LandOwner::LandOwner(string name, string sex, int gold, long exp):m_name(name), m_Sex(sex), m_Gold(gold), m_Epx(exp){
    cout << "LandOwner(string name, string sex, int gold, long exp)" << endl;
}

void LandOwner::ShowInfe(){
    cout << "昵称" << GetName() << endl;
    cout << "性别" << GetSex() << endl;
    cout << "金币" << GetGold() << endl;
    cout << "经验" << GetEpx() << endl;
}