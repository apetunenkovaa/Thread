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
        printf("Выберите действие: \n 1-посмотреть значение счетчика \n 2-поставить рабочий поток на паузу \n 3-снять рабочий поток с паузы \n 4 - завершить все потоки \n ");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            printf("Значение счетчика равно %d\n", work);
            break;
        case 2:
            printf("Рабочий поток поставлен на паузу\n");
            SuspendThread(hF[0]);
            break;
        case 3:
            printf("Рабочий поток снят с паузы\n");
            ResumeThread(hF[0]);
            break;
        case 4:
            printf("Все потоки завершили работу\n");
            TerminateThread(hF[0], 0);
            ExitThread(0);
            break;
        default:
            printf("Ничего не изменилось\n");
            break;
        }
    }
}

