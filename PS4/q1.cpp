#include <iostream>
#include <string>
#include <vector>

class Vector2D
{
public:
    Vector2D(int x, int y); // constructor
    Vector2D();             // default constructor
    int GetX() const;
    int GetY() const;
    void SetX();
    void SetY();
    const int operator*(Vector2D &vec2) const;

private:
    int m_x;
    int m_y;
};
int main()
{
    // Some test vectors
    Vector2D v1(10, 0), v2(0, 10), v3(10, 10), v4(5, 4);
    std::cout << "(" << v1.GetX() << "," << v1.GetY() << ") * (" << v2.GetX() << "," << v2.GetY() << ") = " << v1 * v2 << std::endl;
    std::cout << "(" << v2.GetX() << "," << v2.GetY() << ") * (" << v3.GetX() << "," << v3.GetY() << ") = " << v2 * v3 << std::endl;
    std::cout << "(" << v3.GetX() << "," << v3.GetY() << ") * (" << v4.GetX() << "," << v4.GetY() << ") = " << v3 * v4 << std::endl;
    return 0;
}

Vector2D::Vector2D(int x, int y)
{
    m_x = x;
    m_y = y;
}
Vector2D::Vector2D()
{
    m_x = 0;
    m_y = 0;
}

int Vector2D::GetX() const
{
    return m_x;
}
int Vector2D::GetY() const
{
    return m_y;
}
const int Vector2D::operator*(Vector2D &vec2) const
{
    int vec2_x = vec2.GetX();
    int vec2_y = vec2.GetY();
    int dot_product = (m_x * vec2_x) + (m_y * vec2_y);
    return dot_product;
}