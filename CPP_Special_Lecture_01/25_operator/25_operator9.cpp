// 25_operator9.cpp

#include <iostream>
using namespace std;

// 1. 생성자를 제공하지 않으면, 컴파일러는 인자가 없는 기본 생성자를 제공합니다.
// 2. 복사 생성자를 제공하지 않으면, 컴파일러는 복사 생성자를 제공합니다.(얕은 복사)
// 3. 소멸자를 제공하지 않으면, 컴파일러는 소멸자를 제공합니다.
// 4. 사용자가 대입 연산자를 제공하지 않으면, 컴파일러는 대입 연산자를 제공합니다.

class Point {
public:
    int x = 0;
    int y = 0;

    // * 대입 연산자
    // 1) 컴파일러가 만들어준 대입 연산자는 얕은 복사를 수행합니다.
    //  => 클래스 내부에 포인터 멤버가 있다면, 문제가 발생할 수 있습니다.
    //    - 깊은 복사
    //    - 참조 계수
    //    - 복사 금지
    //  => 복사 생성자를 구현했다면, 반드시 대입 연산자도 구현해주어야 합니다.
    //
    //  2) 대입 연산자는 반드시 멤버 함수로 구현해야 합니다.
    //     =, (), [], ->

    Point& operator=(const Point& rhs)
    {
        cout << "operator=(const Point&)" << endl;
        x = rhs.x;
        y = rhs.y;
        return *this;
    }
};

// ++++++a;
// Point& operator++() {
//    ...
//    return *this;
// }

// a = b = c = 20
// => 자기 자신의 참조를 반환하도록 만들어야 합니다.

int main()
{
    Point p1;
    Point p2 = p1; // 초기화 - 복사 생성자

    p2 = p1; // 대입 - 대입 연산자
    // p2.operator=(p1)

    int a = 0, b = 0, c = 0;
    a = b = c = 20;
    // 대입 연산자를 오른쪽 결합합니다.
}