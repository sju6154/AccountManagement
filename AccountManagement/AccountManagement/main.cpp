#include "head.h"

int main(void)
{
	int i = 0;
	int num = 0;
	int count = 0;
	AccountHandler account;

	while (1)
	{
		cout << "---------Menu---------" << endl;
		cout << "1. 계좌 개설" << endl;
		cout << "2. 입금" << endl;
		cout << "3. 출금" << endl;
		cout << "4. 계좌정보 전체 출력" << endl;
		cout << "5. 프로그램 종료" << endl;
		cout << "----------------------" << endl;
		cin >> num;
		cout << "선택 : " << num << endl;

		if (num == 1) //계좌 개설
		{
			MakeAccountFunc(&account);
			count++;
		}

		else if (num == 2) //입금
		{
			DepositFunc(&account);
		}

		else if (num == 3) //출금
		{
			WithdrawFunc(&account);
		}

		else if (num == 4) //계좌정보 전체 출력
		{
			account.ShowAllAccountInfo();
		}
		else if (num == 5) //프로그램 종료
			break;
		else
			cout << "잘못된 값을 입력햇습니다." << endl;

	}

	return 0;
}


