#include <cmath>

const float PI = 3.1415926;
class Point{
    private:
      float x;
      float y;
    public:
      Point(float a = 0.0,float b = 0.0)
      {
          x = a;
          y = b;
      }
      void setX(float a)
      {
          x = a;
      }
      void setY(float b)
      {
          y = b;
      }
      float getX()
      {
          return x;
      }
      float getY()
      {
          return y;
      }
};
class Circle:public Point{
    private:
      float radius;
    public:
      Circle(float a=0.0,float b=0.0,float c=0.0):Point(a,b)
      {
          radius = c;
      }
      void setRadius(float r)
      {
          radius = r;
      }
      float getRadius()
      {
          return radius;
      }
      float computArea()
      {
          return PI * radius * radius;
      }
      float computPerimeter()
      {
          return 2 * PI * radius;
      }
};