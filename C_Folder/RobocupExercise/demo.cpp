#include<cmath>
#include"geometry.hpp"

int main(void) {
    double aFixed, bFixed, cFixed;
    double aTemp, bTemp, cTemp;
    double circleX, circleY, radius;
    double point_ltX, point_ltY, point_lbX, point_lbY, point_rtX, point_rtY, point_rbX, point_rbY;

    cout << "Please input the parameter of your Fixed straight line: ";
    cin >> aFixed >> bFixed >> cFixed;

    cout << "Please input the parameter of your Requested straight line: ";
    cin >> aTemp >> bTemp >> cTemp;

    cout << "Please input the parameter of your circle: ";
    cin >> circleX >> circleY >> radius;

    cout << "Please input the parameter of your rectangle: ";
    cin >> point_ltX >> point_ltY >> point_lbX >> point_lbY 
            >> point_rtX >> point_rtY >> point_rbX >> point_rbY;

    Line fixedLine(aFixed, bFixed, cFixed);
    Line tempLine(aTemp, bTemp, cTemp);
    Circle circle(circleX, circleY, radius);
    Rectangle rectangle(point_ltX, point_ltY, point_lbX, point_lbY, point_rtX, point_rtY, point_rbX, point_rbY);

    //计算两直线的交点
    if (fixedLine.get_a() / fixedLine.get_b() != tempLine.get_a() / tempLine.get_b()) {
        Point llInter;
        double x, y;
        x = (fixedLine.get_b() * tempLine.get_c() - fixedLine.get_c() * tempLine.get_b()) / 
                (fixedLine.get_a() * tempLine.get_b() - fixedLine.get_b() * tempLine.get_a());
        y = (fixedLine.get_a() * tempLine.get_c() - fixedLine.get_c() * tempLine.get_a()) / 
                (fixedLine.get_b() * tempLine.get_a() - fixedLine.get_a() * tempLine.get_b());
        llInter.x = x;
        llInter.y = y;
        cout << "The coordinates of the intersection of the two lines is: (" 
                << llInter.x << ", " << llInter.y << ")" << endl;
    }
    else {
        cout << "The two straight lines have no intersection or they coincide" << endl;
    }

    //计算直线与圆的交点
    double distance = fabs(fixedLine.get_a() * circle.getCenterPoint().x + fixedLine.get_b() * circle.getCenterPoint().y 
            + circle.getRadius()) / pow((pow(fixedLine.get_a(), 2) + pow(fixedLine.get_b(), 2)), 0.5);
    if (distance < circle.getRadius()) {
        Point lcInterFir, lcInterSec;
        double xFir, yFir, xSec, ySec;
    }
    return 0;
}