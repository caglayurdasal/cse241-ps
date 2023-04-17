#include <iostream>
#include <string>
#include <vector>

class HotDogStand
{
public:
    HotDogStand(int id, int nSold); // constructor
    HotDogStand(int id);            // constructor
    HotDogStand();                  // default constructor
    void JustSold();
    int getNumSold();
    int getId();

private:
    int m_id;
    int m_nSold;
};
static int totalSold{0};
static int getTotalSold();

int main()
{
    HotDogStand s0(0), s1(1), s2(2, 4), s3(3, 19);
    for (int i = 0; i < 3; i++)
    {
        s0.JustSold();
        s1.JustSold();
        s1.JustSold();
        s2.JustSold();
        s0.JustSold();
        s0.JustSold();
        s1.JustSold();
        s2.JustSold();
        s3.JustSold();
    }
    std::cout << "Stand #" << s0.getId() << " sold " << s0.getNumSold()
              << std::endl;
    std::cout << "Stand #" << s1.getId() << " sold " << s1.getNumSold()
              << std::endl;
    std::cout << "Stand #" << s2.getId() << " sold " << s2.getNumSold()
              << std::endl;
    std::cout << "Stand #" << s3.getId() << " sold " << s3.getNumSold()
              << std::endl;
    std::cout << "Total number of sold hotdogs: " << getTotalSold() << std::endl;
    return 0;
}

HotDogStand::HotDogStand(int id, int nSold)
{
    m_id = id;
    m_nSold = nSold;
    totalSold += m_nSold;
}
HotDogStand::HotDogStand(int id)
{
    m_id = id;
    m_nSold = 0;
}

HotDogStand::HotDogStand()
{
    m_id = 0;
    m_nSold = 0;
}

int HotDogStand::getNumSold() { return m_nSold; }
int HotDogStand::getId() { return m_id; }
void HotDogStand::JustSold()
{
    m_nSold++;
    totalSold++;
}
static int getTotalSold() { return totalSold; }