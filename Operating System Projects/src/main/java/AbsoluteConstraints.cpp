#include <iostream>
#include <string>

// Assuming Point and Dimension classes are defined and included appropriately

class AbsoluteConstraints {
public:
    int x;
    int y;
    int width;
    int height;

    AbsoluteConstraints(int x, int y) : x(x), y(y), width(-1), height(-1) {}

    AbsoluteConstraints(int x, int y, int width, int height)
        : x(x), y(y), width(width), height(height) {}

    AbsoluteConstraints(Point pos) : AbsoluteConstraints(pos.x, pos.y) {}

    AbsoluteConstraints(Point pos, Dimension size)
        : AbsoluteConstraints(pos.x, pos.y, size.width, size.height) {}

    int getX() const { return x; }

    int getY() const { return y; }

    int getWidth() const { return width; }

    int getHeight() const { return height; }

    std::string toString() const {
        return "[x=" + std::to_string(x) + ", y=" + std::to_string(y) +
               ", width=" + std::to_string(width) + ", height=" +
               std::to_string(height) + "]";
    }
};
