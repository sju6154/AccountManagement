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
		cout << "1. ���� ����" << endl;
		cout << "2. �Ա�" << endl;
		cout << "3. ���" << endl;
		cout << "4. �������� ��ü ���" << endl;
		cout << "5. ���α׷� ����" << endl;
		cout << "----------------------" << endl;
		cin >> num;
		cout << "���� : " << num << endl;

		if (num == 1) //���� ����
		{
			MakeAccountFunc(&account);
			count++;
		}

		else if (num == 2) //�Ա�
		{
			DepositFunc(&account);
		}

		else if (num == 3) //���
		{
			WithdrawFunc(&account);
		}

		else if (num == 4) //�������� ��ü ���
		{
			account.ShowAllAccountInfo();
		}
		else if (num == 5) //���α׷� ����
			break;
		else
			cout << "�߸��� ���� �Է��޽��ϴ�." << endl;

	}

	return 0;
}


