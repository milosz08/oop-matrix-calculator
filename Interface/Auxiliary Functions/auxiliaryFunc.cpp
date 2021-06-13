#include <iostream>
#include <string>
#include <initializer_list>
#include "auxiliaryFunc.h"

void matrixFinalInfo(std::initializer_list<std::string> list) {
  for(auto elm : list) {
    std::cout << elm << "\n";
  }
}