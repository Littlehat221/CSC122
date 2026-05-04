#include "dish.hpp"

Dish::Dish(std::string description) {
   this->description = description;
}

std::string Dish::get_description() {
   return description;
}
