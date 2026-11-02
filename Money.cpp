#include <iostream>

class Money {
private:
    long long total;
public:
    Money(): total(0) {
    }

    Money(long long rubles): total(rubles*100) {
    }

    Money(long long rubles, int kopecks):
        total(rubles*100+kopecks) {
    }

    long long Rubles() const {
        return total/100;
    }

    int Kopecks() const {
        return total%100;
    }

    long long Total() const {
        return total;
    }

    Money& operator+=(const Money& other) {
        total=total+other.total;
        return *this;
    }
};

Money operator+(const Money& a ,const Money& b) {
    long long sum = a.Total()+b.Total();
    return Money(sum/100,sum%100);
}

Money operator*(const Money& a ,long long b) {
    long long sum = a.Total()*b;
    return Money(sum/100,sum%100);
}

Money operator*(long long a, const Money& b) {
    return b*a;
}

bool operator==(const Money& a, const Money& b) {
    return a.Total()==b.Total();
}

bool operator<(const Money& a, const Money& b) {
    return a.Total()<b.Total();
}

std::ostream& operator<<(std::ostream& os, const Money& p) {
    os << p.Rubles() << ".";
    if (p.Kopecks()<10) {
        os << "0";
    }
    os << p.Kopecks();
    return os;
}