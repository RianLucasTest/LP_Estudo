#include<stdlib.h>
#include<Windows.h>

int main(){
    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_HIDE);

    system("cd C:\\Users\\User\\Documents\\LP_Estudo\\LP3 && python testeNoti.py");

    return 0;
}