#include "Point.hpp"
#include <cmath>
#include <iostream>
#include <math.h>
#include <memory>
#include <ostream>
using namespace ariel;
using namespace std;
#include <cmath>

 Point::Point(double xCord, double yCord) : xCord(xCord), yCord(yCord) {}
   
 double Point::distance(Point other)const{
    double xDiff=other.getX()-this->xCord;
    double yDiff=other.getY()-this->yCord;
    return sqrt(xDiff*xDiff+yDiff*yDiff);
 }

 Point  Point::moveTowards(Point source, Point destination, double distance){
    if (distance<0) throw invalid_argument("distance cannot be smaller than 0");
    double dx = destination.getX() - source.getX();
    double dy = destination.getY() - source.getY();
    double magnitude = sqrt(dx * dx + dy * dy);
    if (magnitude <= distance) {
        return destination;
    } else {
        double ratio = distance / magnitude;
        return {source.getX() + ratio * dx, source.getY() + ratio * dy};
    }
}
void Point :: print () const {
    cout << "(" << xCord << ", " << yCord << ")";
}
string Point :: toString () const {
    string info;
    info = "(" +  to_string(xCord) + ", " +  to_string(yCord) + ")";
    return info;
}
