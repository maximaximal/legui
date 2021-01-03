#pragma once

#include <exception>

namespace legui {
class WidgetNotListedException : public std::exception {
  public:
  WidgetNotListedException() {}
  virtual const char* what() const throw() {
    return ("The widget queried for deletion is not in the container!");
  }
};
}
