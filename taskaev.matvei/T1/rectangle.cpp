#include <iostream>
#include "rectangle.hpp"

taskaev::Rectangle::Rectangle(point_t leftpoint, point_t rightpoint) :
  leftPoint_(leftpoint), rightPoint_(rightpoint)
{}

double taskaev::Rectangle::getArea()
{
  return (rightPoint_.X - leftPoint_.X) * (rightPoint_.Y - leftPoint_.Y);
}

rectangle_t taskaev::Rectangle::getFrameRect()
{
  double width = std::abs(rightPoint_.X - leftPoint_.X);
  double height = std::abs(rightPoint_.Y - leftPoint_.Y);
  point_t pos(((rightPoint_.X + leftPoint_.X) / 2), ((rightPoint_.Y + leftPoint_.Y)));
  return rectangle_t(width, height, pos);
 }

void taskaev::Rectangle::move(double x, double y)
{
  rightPoint_ = point_t(rightPoint_.X + x, rightPoint_.Y + y);
  leftPoint_ = point_t(leftPoint_.X + x, leftPoint_.Y + y);
}

void taskaev::Rectangle::move(point_t center)
{
  double d_x = (center.X - ((rightPoint_.X + leftPoint_.X) / 2));
  double d_y = (center.Y - ((rightPoint_.Y + leftPoint_.Y) / 2));
  move(d_x, d_y);

}

void taskaev::Rectangle::scale(double k)
{
  double width = std::abs(rightPoint_.X - leftPoint_.X);
  double height = std::abs(rightPoint_. Y- leftPoint_.Y);
  rightPoint_.X = ((rightPoint_.X + leftPoint_.X) / 2) - (width * k) / 2;
  rightPoint_.Y = ((rightPoint_.Y + leftPoint_.Y) / 2) - (height * k) / 2;
  leftPoint_.X = ((rightPoint_.X + leftPoint_.X) / 2) + (width * k) / 2;
  leftPoint_.Y = ((rightPoint_.Y + leftPoint_.Y) / 2) + (height * k) / 2;
}
