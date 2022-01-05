// 5_function5.cpp
#include<iostream>
using namespace std;

//쉽게 사용하도록 만든 것도 중요하지만 잘 못 사용하기 어렵게 만드는것도 중요

int gcd(int a, int b)
{
  return b != 0 ? gcd(b, a % b) : a;
}
// gcd 함수를 double에 대해서 사용할 수 없도록 하고 싶다.
// 1) 의도적으로 함수의 선언부만 제공합니다.
//  => 링킹 오류를 통해 실행 파일 생성이 금지됩니다.
//  => 링킹 오류는 분석이 어렵습니다.
// double gcd(double a, double b); // 핵심: 선언만 합니다.

// 2) C++11 - delete function
//  => 함수를 삭제하는 문법
double gcd(double a, double b) = delete;

int main()
{
  cout << gcd(2, 10) << endl;
  //cout << gcd(2.2, 4.3) << endl;
  // double이 int로 암묵적인 형변환되서 동작합니다.
  // => 동작하면 안되는 코드입니다.
}