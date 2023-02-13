#include <Windows.h>
#include <stdlib.h>

#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CLOSE:
        PostQuitMessage(0);
        break;
    case WM_KEYDOWN:
        if (wParam == VK_SPACE)
        {
            MessageBox(hWnd, L"Hello, World!", L"Hello, World!", MB_OK | MB_ICONEXCLAMATION);
        }
        else if (wParam == VK_ESCAPE)
        {
            PostQuitMessage(0);
        }
        else if (wParam == VK_RETURN)
        {
            HDC hdc = GetDC(hWnd);
            POINT points[6] = { {50, 50}, {100, 50}, {150, 100}, {100, 200}, {50, 100}, {50, 50} };
            Polyline(hdc, points, 6);
            ReleaseDC(hWnd, hdc);
        }
        else
        {
            HDC hdc = GetDC(hWnd);
            TextOut(hdc, 0, 0, L"Hello, World!", 13);
            ReleaseDC(hWnd, hdc);
        }
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }

    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASSEX wc = { 0 };
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_3DFACE + 1);
    wc.lpszClassName = L"WindowClass";

    RegisterClassEx(&wc);

    HWND hWnd = CreateWindowEx(0, L"WindowClass", L"Hello, World!", WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
        NULL, NULL, hInstance, NULL);

    if (!hWnd)
        return 1;

    ShowWindow(hWnd, nCmdShow);

    MSG msg = { 0 };

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}
