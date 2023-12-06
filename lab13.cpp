#include <iostream>
#include <locale>
#include <string>
#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

class CShape
{
    protected:
    double width;
    double height;

    public:
    CShape(){}
    CShape(double w, double h) {
        width = w;
        height = h;
    }

    // 가상함수(Virtual Functions) 선언 : 자식 클래스에서 오버라이드 가능함
    virtual double get_area() { return 0; }
    void set_width(double w) { width = w; }
    void set_height(double h) { height = h; }
};

class CCircle : public CShape
{
    public:
    CCircle(double w, double h) : CShape(w,h)
    {
        wprintf(L"CCircle 생성자 실행\n");
    }

    // 부모한테 물려받은 get_area() 함수를 오버라이드하여 원의 면적을 구하는 기능으로 개조한다
    double get_area() {
        return M_PI * pow(width/2, 2);
    }
};

class CTriangle : public CShape
{
    public:
    CTriangle(double w, double h) : CShape(w,h) // 상위 클래스의 파라미터 있는 생성자 호출
    {
        wprintf(L"CTriangle 생성자 실행\n");
    }

    // 부모한테 물려받은 get_area() 함수를 오버라이드하여 삼각형에 면적을 구하는 기능으로 개조한다
    double get_area() {
        return width * height / 2;
    }
};

int main() {
    setlocale(LC_ALL, "");

    wcout << L"C++ 다형성(Polymorphism)" << endl;

    CShape shape;
    CCircle circle(5,5);
    CTriangle tri(5,5);

    // 동일한 CShape 포인터 변수에 각각 다른 자료형의 주소가 할당된다
    CShape* pShape = &shape;
    CShape* pShape1 = &circle;
    CShape* pShape2 = &tri;

    // 모두 CShape* 형의 변수를 이용한 함수의 호출이지만 서로 다른 기능을 보인다
    // 모두 CShape* 형이지만 실제 런타임 타입(Runtime Types)은 서로 다르다
    double shape_area = pShape->get_area();
    double circle_area = pShape1->get_area();
    double tri_area = pShape2->get_area();

    wcout << L"도형의 면적=" << shape_area << endl;
    wcout << L"원의 면적=" << circle_area << endl;
    wcout << L"삼각형 면적=" << tri_area << endl;

    return 0;
}