#include <iostream>

using namespace std;

//Task 1.1------------------------------------------------------
template <class T>
class Pair1 {
private:
    T t_1;
    T t_2;

public:
    Pair1(T x, T y) {
   t_1 = x;
   t_2 = y;
    }

T first() const {
return t_1;
    }

T second() const {
return t_2;
    }
};

//Task 2.1------------------------------------------------------
template <class D1, class D2>
class Pair {
private:
    D1 d_1;
    D2 d_2;

public:
    Pair(D1 x, D2 y) {
    d_1 = x;
    d_2 = y;
    }

D1 first() const {
    return d_1;
}

D2 second() const {
    return d_2;
}

};

//Task 3.1------------------------------------------------------
template <class F>
class StringValuePair : public Pair<string, F> {
public:
StringValuePair(string x, F y) : Pair<string, F>(x, y) {
    }
};


int main()
{

//Task 1.2------------------------------------------------------
    Pair1<int> p1(6, 9);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair1<double> p2(3.4, 7.8);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
    cout << endl;

//Task 2.2------------------------------------------------------
    Pair<int, double> p(6, 7.8);
    cout << "Pair: " << p.first() << ' ' << p.second() << '\n';

    const Pair<double, int> p3(3.4, 5);
    cout << "Pair: " << p3.first() << ' ' << p3.second() << '\n';
    cout << endl;

//Task 3.2------------------------------------------------------
    StringValuePair<int> svp("Amazing", 7);
    cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';


    return 0;
}
