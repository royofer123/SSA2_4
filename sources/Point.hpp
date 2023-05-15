#ifndef POINT_HPP
#define POINT_HPP
namespace ariel{
    class Point{
        private:
        double xCord;
        double yCord;
        
        public:
        double getX() const;
        double getY() const;
        Point(double xCord, double yCord);
        double distance(Point other);
        void print();
        static Point moveTowards(Point &source, Point &destination, double distance);
        friend bool operator==(const Point &pointA, const Point &pointB);
        
    };
};


#endif
