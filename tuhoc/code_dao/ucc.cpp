#include <iostream>
#include <vector>
using namespace std;

class student
{
int marks;
public: student(){}
student(int x)
{
marks=x;
}
};
int main()
{
student s1(100);
student s2();
student s3=100;
return 0;
}
