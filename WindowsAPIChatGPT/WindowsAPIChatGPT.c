#include <Windows.h>
#include <stdlib.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MessageBox(NULL, L"Hello, World!", L"Hello, world!", MB_OK | MB_ICONEXCLAMATION);
	return EXIT_SUCCESS;
}
