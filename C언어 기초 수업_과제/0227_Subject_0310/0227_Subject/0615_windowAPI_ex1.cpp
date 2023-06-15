#include <Windows.h>
#include <cassert>
#include <string>

LRESULT CALLBACK WndProc(HWND handle, UINT message, WPARAM wParam, LPARAM lParam);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
    WNDCLASSA wnd_class; 

    wnd_class.cbClsExtra = 0;
    wnd_class.cbWndExtra = 0;
    wnd_class.hbrBackground = static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH)); 
    wnd_class.hCursor = LoadCursor(nullptr, IDC_CROSS); 
    wnd_class.hIcon = LoadIcon(nullptr, IDI_ERROR); 
    wnd_class.hInstance = hInstance;
    wnd_class.lpfnWndProc = WndProc; 
    wnd_class.lpszClassName = "First Window"; 
    wnd_class.lpszMenuName = nullptr;
    wnd_class.style = CS_HREDRAW | CS_VREDRAW; 


    RegisterClassA(&wnd_class);

    HWND hwnd = CreateWindowA 
    (
        "First Window",
        "Hello, Window!",
        WS_OVERLAPPEDWINDOW,
        0,
        0,
        1080,
        720,
        nullptr,
        nullptr,
        hInstance,
        nullptr
    );

    assert(hwnd != nullptr); 

    ShowWindow(hwnd, nCmdShow); 
    ShowCursor(TRUE); 

    MSG message;
    ZeroMemory(&message, sizeof(MSG));

    while (GetMessage(&message, nullptr, 0, 0)) 
    {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }

    DestroyWindow(hwnd);
    UnregisterClassA("First Window", hInstance);

    return 0;
}

LRESULT CALLBACK WndProc(HWND handle, UINT message, WPARAM wParam, LPARAM lParam)
{
    static POINT position; 
    static POINT start;
    static POINT end;
    static BOOL is_clicked = FALSE; 

    static RECT rect1 = { 100, 100, 200, 200 }; 
    static RECT rect2 = { 300, 300, 400, 400 };
    static BOOL is_intersect = FALSE;

    switch (message)
    {
    case WM_KEYDOWN:
    {
        if (wParam == VK_UP) position.y -= 10;
        else if (wParam == VK_DOWN) position.y += 10;
        if (wParam == VK_LEFT) position.x -= 10;
        else if (wParam == VK_RIGHT) position.x += 10;

        InvalidateRect(handle, nullptr, TRUE);
    }
    break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(handle, &ps);
        std::string str = "Bang!!!";
        std::string str1 = "";

        Rectangle(hdc, position.x, position.y, position.x + 100, position.y + 100);
        Rectangle(hdc, 100, 100, 200, 200);

        if ((position.x > 0 && position.x < 200) && (position.y > 0 && position.y < 200))
            TextOut(hdc, 100, 100, str.c_str(), str.length());
        else
            TextOut(hdc, 100, 100, str1.c_str(), str1.length());       
    }
    break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProcA(handle, message, wParam, lParam);
    }

    return 0;
}