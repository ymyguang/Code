#include <iostream>
using namespace std;
class LandOwner
{
private:
    /* data */
    string m_name;
    string m_Sex;
    int m_Gold;
    long m_Epx;
public:
    string GetName() {return m_name;};
    void SetName(string val) {m_name = val;};
    string GetSex() {return m_Sex;};
    void SetSex(string val){m_Sex = val;}
    int GetGold() {return m_Gold;};
    void SetGold(int val) {m_Gold = val;};
    long GetEpx() {return m_Epx;};
    void SetEpx(long val) {m_Epx = val;}

    void ShowInfe();
    LandOwner();
    LandOwner(string);
    LandOwner(string, string, int, long);
};


