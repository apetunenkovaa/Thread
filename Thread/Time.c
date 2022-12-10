#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <malloc.h>
HANDLE	hThread[4];
int main() 
{
	system("chcp 1251>nul");

	hThread[0] = CreateThread(NULL, 0, hhh, 0, 0);


	printf("Введеите номер задачи: \n 1 - включение секундомера \n 2 - включение таймера \n 3 - просмотр часов \n 4 - пауза \n 5 - снять с паузы");
	int z = 0;
	switch (z)
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	default:
		break;
	}

}
