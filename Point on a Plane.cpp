#include <iostream>

class Point {
private:
    long long x;
    long long y;
public:
    Point(): x(0), y(0) {
    }

    Point(long long x, long long y): x(x), y(y) {
    }

    long long X() const {
        return x;
    }

    long long Y() const {
        return y;
    }

    void Move(long long dx, long long dy) {
        x=x+dx;
        y=y+dy;
    }

    long long Dist2(const Point& other) const {
        long long dx=x-other.x;
        long long dy=y-other.y;
        return dx*dx+dy*dy;
    }
};

bool operator==(const Point& a, const Point& b) {
    return a.X()==b.X() && a.Y()==b.Y();
}

bool operator!=(const Point& a, const Point& b) {
    return a.X()!=b.X() || a.Y()!=b.Y();
}

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.X() << ", " << p.Y() << ")";
    return os;
}
