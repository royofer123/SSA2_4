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
 double Point::getX() const{
    return this->xCord; 
 }
  double Point::getY() const{
    return this->yCord; 
 }
   
 double Point::distance(Point &other){
    double xDiff=other.getX()-this->xCord;
    double yDiff=other.getY()-this->yCord;
    return sqrt(xDiff*xDiff+yDiff*yDiff);
 }
 void Point:: print(){
    cout<< "(" << this->xCord << "," <<this->yCord <<")"<<endl;
 }
 Point moveTowards(Point &source, Point &destination, double distance){
    double totalDistance=source.distance(destination);
    if(totalDistance<=distance) return destination;
    else {
        // Calculate the ratio to move towards the destination
        double ratio = distance / totalDistance;

        // Calculate the new coordinates based on the ratio
        double newX = source.getX() + (destination.getX() - source.getX()) * ratio;
        double newY = source.getY() + (destination.getY() - source.getY()) * ratio;

        return Point(newX, newY);
    }
    }
 bool operator==(const Point &PointA, const Point &PointB){
    if(PointA.getX()==PointB.getY() && PointA.getY()==PointB.getY()) return true;
    else return false;
 }