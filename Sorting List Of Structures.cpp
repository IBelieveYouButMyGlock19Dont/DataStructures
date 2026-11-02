#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

struct Student {
    std::string first_name;
    std::string last_name;
    int day;
    int month;
    int year;
};

bool date(const Student& a, const Student& b) {
    if (a.year != b.year) {
        return a.year < b.year;
    }
    if (a.month != b.month) {
        return a.month < b.month;
    }
    if (a.day != b.day) {
        return a.day < b.day;
    }
    if (a.last_name != b.last_name) {
        return a.last_name < b.last_name;
    }

    return a.first_name < b.first_name;
}

bool name(const Student& a, const Student& b) {
    if (a.last_name != b.last_name) {
        return a.last_name < b.last_name;
    }
    if (a.first_name != b.first_name) {
        return a.first_name < b.first_name;
    }
    if (a.year != b.year) {
        return a.year < b.year;
    }
    if (a.month != b.month) {
        return a.month < b.month;
    }

    return a.day < b.day;
}

int main() {
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");
    int n;
    in >> n;
    std::vector<Student> arr(n);

    for (int i=0; i<n;i++) {
        in >> arr[i].first_name >> arr[i].last_name >> arr[i].day >> arr[i].month >> arr[i].year;
    }

    std::string method;
    in >> method;

    if (method == "date") {
        sort(arr.begin(),arr.end(),date);
    }
    else {
        sort(arr.begin(),arr.end(),name);
    }

    for (int i=0; i<n;i++) {
        out << arr[i].first_name << " " << arr[i].last_name << " " << arr[i].day << "." << arr[i].month << "." << arr[i].year << "\n";
    }

    return 0;
}
