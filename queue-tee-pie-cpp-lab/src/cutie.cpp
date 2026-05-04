#include "cutie.hpp"
#include <iostream>

Cutie::Cutie(std::string description, int cuteness_rating) {
    this->description = description;
    this->cuteness_rating = cuteness_rating;
}
std::string Cutie::get_description() {
    return description;
}
int Cutie::get_cuteness_rating() {
    return cuteness_rating;
}
Puppy::Puppy() : Cutie("puppy", 10) {
}
Kitty::Kitty() : Cutie("kitty", 4) {
}
PygmyMarmoset::PygmyMarmoset() : Cutie("PygmyMarmoset", 1) {
}


