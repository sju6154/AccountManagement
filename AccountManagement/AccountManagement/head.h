#ifndef __HEAD__
#define __HEAD__

#include <iostream>
#include <cstring>
#include"class.h"
using namespace std;

// �ſ���
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };

// ������ ����
enum { NORMAL = 1, CREDIT = 2 };

void MakeAccountFunc(AccountHandler *account);
void DepositFunc(AccountHandler *account);
void WithdrawFunc(AccountHandler *account);

#endif 