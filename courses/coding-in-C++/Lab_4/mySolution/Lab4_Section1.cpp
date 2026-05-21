#include <iostream>
#include <cmath>

class Vector2D
{
private: 
    double x;
    double y;

public: 
    Vector2D() : x(0.0), y(0.0) {}

    Vector2D(double x, double y) : x(x), y(y) {}

    double getX() const 
    { 
        return x; 
    }

    double getY() const 
    { 
        return y; 
    }

    void print() const
    {
        std::cout <<"X:" << x << std::endl;
        std::cout <<"Y:" << y << std::endl;
    }

    double getMagnitude() const
    {
        return sqrt((x * x) + (y * y));
    }

    double getMagnitude(int precision) const;

};

double Vector2D::getMagnitude(int precision) const
{
    double factor = std::pow(10.0, precision);
    double length = this->getMagnitude();
    return std::round(length * factor) / factor;
}



int main()
{
    Vector2D vector1(5, 2);
    Vector2D vector2(2, 7);

    std::cout << vector1.getMagnitude() << std::endl;
    std::cout << vector1.getMagnitude(2) << std::endl;


}


