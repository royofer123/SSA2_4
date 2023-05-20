#ifndef POINT_HPP
#define POINT_HPP
#include <string>
namespace ariel{
    class Point{
        private:
        double xCord;
        double yCord;
        
        public:
        double getX () const { return xCord; }
        double getY () const { return yCord; }
        void setX (double new_x) { xCord = new_x; }
        void setY (double new_y ) { yCord = new_y; }
        Point(double xCord, double yCord);
        double distance(Point other) const;
        void print() const;
        static Point moveTowards(Point source, Point destination, double distance);
        std::string toString() const;
        //operators
        friend bool operator == (const Point& left, const Point& right) {
            return (left.xCord == right.xCord) && (left.yCord == right.yCord);
        }
        friend bool operator != (const Point& left, const Point& right) {
            return !(left == right);
        }
    };        
    };
#endif
