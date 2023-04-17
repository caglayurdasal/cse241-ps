#include <cmath>
#include <iostream>
#include <string>
#include <vector>

class MyInteger
{
public:
    MyInteger(int num) : m_num(num){};
    MyInteger() : m_num(0){};
    int getNum() { return m_num; };
    void setNum(){};
    const int operator[](int index);

private:
    int m_num;
};

const int MyInteger::operator[](int index)
{
    int nDigit = 0;
    int temp = m_num;
    do
    {
        temp /= 10;
        nDigit++;
    } while (temp != 0);

    if (index < 0 || index >= nDigit)
    {
        return -1;
    }
    return static_cast<int>(m_num / pow(10, index)) % 10;
}
int main()
{
    // Some test numbers
    MyInteger num(418);
    std::cout << num[0] << " " << num[1] << " " << num[2] << std::endl;
    std::cout << num[3] << std::endl;
    std::cout << num[-1] << std::endl;
    return 0;
}

/*
PSEUDOCODE FOR "MyInteger::operator[](int index)" FUNCTION
418[0] ->8
if index=0:
    418 / 1(=10^0) -> 418
    return 418 % 10 ===> 8
if index=1:
    418 / 10 -> 41
    return 41 % 10 ===> 1
if index=2:
    418/10 ->41
    41/10=4
    return 4%10 ===> 4

num times /10 = 10^index
return (num/10^index)%10
*/