#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <time.h>


HANDLE hF[2];
int work = 0;
VOID Upravlenie(VOID)
{
    system("chcp 1251");

    hF[0] = CreateThread(NULL, 0, TreadWorker, NULL, 0, 0);
    hF[1] = CreateThread(NULL, 0, TreadManager, NULL, 0, 0);
    WaitForMultipleObjects(2, hF, TRUE, INFINITE);
}

DWORD WINAPI TreadWorker(LPVOID param)
{
    while (TRUE)
    {
        Sleep(100);
        work++;
    }
}
DWORD WINAPI TreadManager(LPVOID param)
{
    int i;
    while (TRUE)
    {
        printf("�������� ��������: \n 1-���������� �������� �������� \n 2-��������� ������� ����� �� ����� \n 3-����� ������� ����� � ����� \n 4 - ��������� ��� ������ \n ");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            printf("�������� �������� ����� %d\n", work);
            break;
        case 2:
            printf("������� ����� ��������� �� �����\n");
            SuspendThread(hF[0]);
            break;
        case 3:
            printf("������� ����� ���� � �����\n");
            ResumeThread(hF[0]);
            break;
        case 4:
            printf("��� ������ ��������� ������\n");
            TerminateThread(hF[0], 0);
            ExitThread(0);
            break;
        default:
            printf("������ �� ����������\n");
            break;
        }
    }
}

