#include "baseTypes.hpp"

point_t::point_t(double x, double y) :
  X(x), Y(y)
{}

rectangle_t::rectangle_t(double width, double height, point_t pos) :
  width_(width), height_(height), pos_(pos)
{}

