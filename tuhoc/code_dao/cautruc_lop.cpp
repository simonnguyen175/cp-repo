#include <iostream>
using namespace std;

struct Vector {
    double x;
    double y;
    Vector () {x = 0; y = 0;}
    Vector (const double _x, const double _y){
        x = _x;
        y = _y;
    }
    void printVector(){
        cout << x << " " << y << endl;
    }
};

Vector addVector(Vector v1, Vector v2)
{
    return Vector(v1.x + v2.x, v1.y + v2.y);
}

int main()
{
    Vector v1, v2;
    cin >> v1.x >> v1.y >> v2.x >> v2.y;
    Vector v3 = addVector(v1, v2);
    v3.printVector();
    return 0;
}
