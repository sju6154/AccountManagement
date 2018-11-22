#ifndef __HEAD__
#define __HEAD__

#include <iostream>
#include <cstring>
#include"class.h"

using namespace std;

// 신용등급
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };

// 계좌의 종류
enum { NORMAL = 1, CREDIT = 2 };

void MakeAccountFunc(AccountHandler *account);
void DepositFunc(AccountHandler *account);
void WithdrawFunc(AccountHandler *account);

#endif 