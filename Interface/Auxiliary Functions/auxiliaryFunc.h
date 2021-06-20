#ifndef PK_MATRIX_CALCULATOR_AUXILIARYFUNC_H
#define PK_MATRIX_CALCULATOR_AUXILIARYFUNC_H
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <synchapi.h>

void genInfoBlock(std::string header, std::vector<std::string> mess);
void sequentialMess(int, std::string mess);
void errorMess(std::string mess, HANDLE& hOut);
std::string saveMtrxInfo(unsigned int& type, unsigned int& val);
unsigned int chooseTypeOfMatrix(HANDLE& hOut);
unsigned int chooseTypeOfNumbers(HANDLE& hOut);

#endif
