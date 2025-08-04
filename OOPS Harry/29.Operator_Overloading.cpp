#include <iostream>

/*
This allows you to change the behavior of operators (like +, -, ==, <<) for your custom classes.
This makes your code more readable.
*/

class Vector2D
{
public:
    int x, y;

    Vector2D(int x_val, int y_val) : x(x_val), y(y_val) {}

    // Overload the '+' operator.
    // This function defines how two Vector2D objects are added.
    Vector2D operator+(const Vector2D &other)
    {
        return Vector2D(x + other.x, y + other.y);
    }
};

int main()
{
    Vector2D v1(1, 2);
    Vector2D v2(3, 4);

    // The overloaded operator is called here.
    Vector2D v3 = v1 + v2;

    std::cout << "v3 = (" << v3.x << ", " << v3.y << ")" << std::endl;
    // Output: v3 = (4, 6)
}