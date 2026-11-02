#include <iostream>

class Time {
private:
    int h;
    int m;
    int s;
    void Normalization() {
        int total=h*3600+m*60+s;
        total=total%86400;
        if (total<0) {
            total=total+86400;
        }
        h=total/3600;
        m=(total%3600)/60;
        s=total%60;
    }
public:
    Time(int h, int m, int s): h(h), m(m), s(s) {
        Normalization();
    }

    Time(int h,int m): Time(h,m,0) {
    }

    Time(): Time(0,0,0) {
    }

    int Hours() const {
        return h;
    }

    int Minutes() const {
        return m;
    }

    int Seconds() const {
        return s;
    }

    int TotalSeconds() const {
        return h*3600+m*60+s;
    }

    void AddSeconds(int seconds) {
        s=s+seconds;
        Normalization();
    }
};

std::ostream& operator<<(std::ostream& out, const Time& t) {
    if (t.Hours()<10) {
        out << 0;
    }
    out << t.Hours() << ":";

    if (t.Minutes()<10) {
        out << 0;
    }
    out << t.Minutes() << ":";

    if (t.Seconds()<10) {
        out << 0;
    }
    out << t.Seconds();
    return out;
}

std::istream& operator>>(std::istream& in, Time& t) {
    int h,m,s;
    char c1,c2;
    in >>h >> c1 >> m >> c2 >> s;
    if (in) {
        t=Time(h,m,s);
    }
    return in;
}