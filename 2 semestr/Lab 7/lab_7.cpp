#include <iostream>
#include <vector>
#include "math.h"

const double PI = acos(-1.0);

struct Color {
    int r;
    int g;
    int b;
};

struct Coords {
    double x;
    double y;
};

class Shape {
protected:
    Color _color;
    std::vector<Coords> _coords;
    Coords _center;
    double _area = -1;
    std::vector<int> _sizes;
public:
    Shape(Color color, std::vector<Coords> coords, std::vector<int> sizes, Coords center) : _color(color),
                                                                                            _coords(coords),
                                                                                            _sizes(sizes),
                                                                                            _center(center) {}

    Coords Get_Center() {
        return _center;
    }

    Color Get_Color() {
        return _color;
    };

    virtual void get_Area() {
        std::cout << _area;
    }


    ~Shape() = default;
};

class Rectangle : public Shape {
public:

    Rectangle(Color color, std::vector<Coords> coords, std::vector<int> sizes, Coords center) : Shape(color, coords,
                                                                                                      sizes, center) {}

    virtual void get_Area() override {
        if (_sizes.size() >= 2)
            std::cout << (_sizes[0] * _sizes[1]) << "\n";
        else std::cout << "error" << std::endl;
    }


    ~Rectangle() {};
};

class Circle : public Shape {
public:

    Circle(Color color, std::vector<Coords> coords, std::vector<int> sizes, Coords center) : Shape(color, coords, sizes,
                                                                                                   center) {
    }

    virtual void get_Area() override {
        if (!_sizes.empty())
            std::cout << 2 * PI * _sizes[0] << "\n";
        else std::cout << "error" << std::endl;
    }

    ~Circle() {};
};

class Triangle : public Shape {
public:
    Triangle(Color color, std::vector<Coords> coords, std::vector<int> sizes, Coords center) : Shape(color, coords,
                                                                                                     sizes, center) {};

    virtual void get_Area() override {
        if (_coords.size() >= 3)
            std::cout << abs(((_coords[1].x - _coords[0].x) * (_coords[2].y - _coords[0].y) -
                              (_coords[2].x - _coords[0].x) * (_coords[1].y - _coords[0].y))) / 2;
        else std::cout << "error" << std::endl;
    }

    ~Triangle() {};
};


int main() {
    std::vector<Coords> coords1 = {{0, 0},
                                   {0, 1},
                                   {1, 1},
                                   {1, 0}};
    std::vector<int> sizes1 = {1, 1};
    Rectangle rect({0, 0, 0}, coords1, sizes1, {0.5, 0.5});
    rect.get_Area();
    std::vector<Coords> coords2 = {{0, 0}};
    std::vector<int> sizes2 = {1};
    Circle circle({255, 0, 0}, coords2, sizes2, {0, 0});
    circle.get_Area();
    std::vector<Coords> coords3 = {{0, 0},
                                   {0, 3},
                                   {4, 0}};
    std::vector<int> sizes3 = {3, 4, 5};
    Triangle tri({0, 255, 255}, coords3, sizes3, {1.33, 1});
    tri.get_Area();
}
