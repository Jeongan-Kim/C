/*
   API : application program interface (���� ���α׷��ֿ� �ʿ��� �������̽�)

   �̹� ������� �ִ� �Լ����� ȣ���ؼ� �ڵ��ϰ� ��.
   ������ â�� �����ϴ� ���� �ʿ��� �Լ����� ����ϴ� �� -> windowAPI

   ���ݱ����� ����â�� �ܼ�â�� ������� �ʰ� ������ â�� ����� �ȴ�.
   (�Ӽ� -> ��� -> �������� -> ��Ƽ ���� / �Ӽ� -> ��Ŀ -> �ý��� -> �ܼ�â�� â���� ����)
*/

/*
   ���� ���(������ ���α׷����� ���� ���)
   : �޼���(�̺�Ʈ, ���콺�� Ŭ���ϴ� ��),
   �޼��� ť(�޼����� ť �ȿ� �����Ų��. ���Լ���),
   �޼��� ����(ť�� ����ִ� �޼����� �о ó���� ���� ���ν����� �Ѱ��ִ� �ݺ��� ����),
   ������ ���ν���(�������� �˸��� ���·� ��ȯ�� �Ǿ� ���� �޼������� �����ڰ� ���� �Լ�(WndProc)�� �°� ó���� ��.
*/

/*
   LPSTR - long pointer str = char*
   LPCSTR - const char*
   LPWSTR - wchar_t*
   LPCWSTR - const wchar_t*


   �Լ� ȣ�� ���
   - cdecl : c�� c++���� ���
   - stdcall : windowAPI���� ���
   callback�Լ��� stdcall �������� ȣ��Ǵ� �Լ��̴�.
   (�ü���� ���ؼ� �ʿ��Ҷ� ȣ��Ǵ� �Լ�)
*/

#include <Windows.h> //���� �� ����� ���
#include <cassert>
#include <string> //���ݱ��� �� string�� iostream�� �־��� �Ŷ� iostream���� ������ string ������� �ʿ�

LRESULT CALLBACK WndProc(HWND handle, UINT message, WPARAM wParam, LPARAM lParam);


//int main �ϴ� ��, APIENTRY : ���⼭���� �����Ѵ�(������)�� �ǹ�, WinMain : Window ���α׷��� ����
int APIENTRY WinMain(
    HINSTANCE hInstance, //window�� â. �� ��ü�� ��ü�� �ǹ��ϴ� �ĺ���
    HINSTANCE prevInstance,
    LPSTR lpszCmdParam, //LPSTR : ���ڿ��̶�� �����ϸ� �Ǵµ�, �밡�� ������ ���ڿ� �ۼ����� ���Ѵ�.(i_a -> int a)
    int nCmdShow //cmd : command window. � ������ â�� ��Ÿ���� �ٰ��� ���ڿ��� ��Ÿ���� ��.
)
{
    WNDCLASSA wnd_class; // A : ASCII. ������ Ŭ������ �̸� ����� ���� ����ϴ� ��.

    wnd_class.cbClsExtra = 0; //Ȯ��� ������ ����� ���� ������ ���� ����
    wnd_class.cbWndExtra = 0; //���� ����
    wnd_class.hbrBackground = static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH)); // GetStockObject : �� �������� ��Ƴ��� â��. ,â ���� �������.
    //stockobject�� ������ ����ϱ� ���� staticcast ����ȯ�� �Ѵ�.
    wnd_class.hCursor = LoadCursor(nullptr, IDC_CROSS); //Ŀ�� ��� ����. ���� ����� ���ڴ�.
    wnd_class.hIcon = LoadIcon(nullptr, IDI_ERROR); // ���α׷� ����� ������ ������ ��� ����
    wnd_class.hInstance = hInstance;// ������ �ν��Ͻ� �Ҵ� �ް� �ִ� �� �⺻���� �޾� ���ڴ�.
    wnd_class.lpfnWndProc = WndProc; //ó���ǰ� �ִ� �� ���������ִ� ��(�޼��� ó�� �Լ�)
    wnd_class.lpszClassName = "First Window"; // ����ȭ ��Ű�� ��. ���߿� �� ���� �̸����� ã���� �� ����
    wnd_class.lpszMenuName = nullptr;
    wnd_class.style = CS_HREDRAW | CS_VREDRAW; // window ��Ÿ�� �����ִ� ��.

    //�̷��� �⺻ ������ �� ��, ����� ����� ��.
    RegisterClassA(&wnd_class);//����� �ϸ� ���� ��׸� ã�� ���鼭 ����� �� �ְ� ��.

    HWND hwnd = CreateWindowA //�����찡 ����Ǵ� ������ ���� �ֵ��� ����� ��. �������� �־�� �������� ����
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

    assert(hwnd != nullptr); //����� �����ƴ��� ���� Ȯ���� �ִ� �� ����

    ShowWindow(hwnd, nCmdShow); //����������� �����ֱ�
    ShowCursor(TRUE); // Ŀ�� ������ ����

    MSG message;
    ZeroMemory(&message, sizeof(MSG)); // ���θ޸𸮶�� ��ũ�η� ������ message�� �����ϰ� �ʱ�ȭ. ��� 0���� �ʱ�ȭ��.

    while (GetMessage(&message, nullptr, 0, 0)) // GetMessage : �޽����� ��� �ö����� ���.
    {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }

    //����� ��������. �����͵�� �̷���� �ֱ� ������
    DestroyWindow(hwnd);
    UnregisterClassA("First Window", hInstance);

    return 0;
}

//handle�� �����ϰ� �����쿡�� ������.
//message�� �̺�Ʈ�� ������ �޴� ����
//wParam, lParam. �ΰ����� ������ �޴� ����
LRESULT CALLBACK WndProc(HWND handle, UINT message, WPARAM wParam, LPARAM lParam)
{
    static POINT position; //���콺 ��ġ
    static POINT start;
    static POINT end;
    static BOOL is_clicked = FALSE; //���콺 Ŭ���ƴ����� ���� ����

    static RECT rect1 = { 100, 100, 200, 200 }; // ���콺�� �׸��� �簢��. ���� ��ǥ��
    static RECT rect2 = { 300, 300, 400, 400 };
    static BOOL is_intersect = FALSE;

    //���� �޼��� ó�� 
    switch (message)
    {
#pragma region Message Box
        //case WM_LBUTTONDOWN:
        //    MessageBoxA(nullptr, "Hello, Window!", "ERROR!!", MB_OKCANCEL);
        //    break;
#pragma endregion
#pragma region Text
    //case WM_LBUTTONDOWN:
    //{
    //    std::string str = "Mouse Clicked!!";

    //    HDC hdc = GetDC(handle); // GetDC�� ���� �ڵ��� �޾ƿ��� ��.. HDC : Handle to Device Context (�ؽ�Ʈ�� ���ų� �׸����� �׸��� ���� �ʿ��� ������ ��� ��)
    //    TextOutA(hdc, 500, 300, str.c_str(), str.length()); //�ؽ�Ʈ ��� �Լ�/ str.c_str() �� ���ڿ��� char������ ��������� ��
    //    ReleaseDC(handle, hdc); //���� �ϱ�
    //}
    //break;

    //case WM_PAINT: //�����찡 �������� �� ����Ǵµ�, �ٽ� ��Ÿ���� �� �۾��� �Ⱥ��̴� ���� �����ϰ��� ȣ���.(ȭ���� ��� �����ǵ��� �����ؼ� �׷��ִ� ��ġ�̴�)
    //{
    //    std::string str = "WM_PAINT message occurred!!";

    //    PAINTSTRUCT ps;
    //    HDC hdc = BeginPaint(handle, &ps); //�׸����� HDC�� �ʿ��ϹǷ�!
    //    TextOutA(hdc, 500, 350, str.c_str(), str.length());

    //    EndPaint(handle, &ps); //��ü �ϱ�
    //}
    //break;
#pragma endregion
#pragma region Text Moving
    //case WM_KEYDOWN:
    //    if      (wParam == VK_UP)    position.y -= 10;
    //    else if (wParam == VK_DOWN)  position.y += 10;
    //    if      (wParam == VK_RIGHT) position.x += 10;
    //    else if (wParam == VK_LEFT)  position.x -= 10;

    //    InvalidateRect(handle, nullptr, TRUE); //��ȿȭ ����(âũ�Ⱑ ����ǰų� ����������)�� ���ؼ� �������ִ� �Լ�
    //    //�׸��� â�� ��������(��ȿȭ �������� ��������) �ٽ� ���ƿ͵� ���;� �ϴ� ������ �ִ� �ڵ�
    //    break;

    //case WM_PAINT:
    //{
    //    PAINTSTRUCT ps; //�׸��⸦ ����ϴ� ����ü.
    //    HDC hdc = BeginPaint(handle, &ps);
    //    TextOut(hdc, position.x, position.y, "��", 2);
    //    EndPaint(handle, &ps);
    //}
    //break;
#pragma endregion
#pragma region Mouse Moving
    //case WM_MOUSEMOVE: //���콺�� ��ǥ ���� �޾ƿ��� ��
    //    position.x = LOWORD(lParam);
    //    position.y = HIWORD(lParam);

    //    InvalidateRect(handle, nullptr, TRUE);
    //    break;

    //case WM_PAINT:
    //{
    //    std::string str = "";
    //    str += std::to_string(position.x); //to_string : �������� ���ڿ��� ��������ִ� stoi�� �ݴ�
    //    str += ", ";
    //    str += std::to_string(position.y);

    //    PAINTSTRUCT ps;
    //    HDC hdc = BeginPaint(handle, &ps);
    //    TextOutA(hdc, position.x, position.y, str.c_str(), str.length());

    //    //Line
    //    MoveToEx(hdc, 100, 100, nullptr); //Ŀ���� �������� Ư�� ��ġ�� �̵� ��Ű�� ��
    //    LineTo(hdc, 500, 500); //���� �׸��� �Լ�

    //    //����
    //    Rectangle(hdc, 500, 500, 600, 600); //�簢��
    //    Ellipse(hdc, 300, 300, 400, 400); //��

    //    EndPaint(handle, &ps);
    //}
    //    break;
#pragma endregion
#pragma region Paint Brush
    //case WM_LBUTTONDOWN: //���콺 ��ư ������
    //    position.x = LOWORD(lParam);
    //    position.y = HIWORD(lParam);
    //    is_clicked = TRUE;
    //    break;
    //    
    //case WM_MOUSEMOVE:
    //    if (is_clicked) //���콺�� Ŭ�������� �۾���
    //    {
    //        HDC hdc = GetDC(handle);

    //        MoveToEx(hdc, position.x, position.y, nullptr);
    //        //������ ��ġ ������Ʈ
    //        position.x = LOWORD(lParam);
    //        position.y = HIWORD(lParam);

    //        //�����ε����� ���׸���
    //        LineTo(hdc, position.x, position.y);
    //        ReleaseDC(handle, hdc); //����
    //    }
    //    break;

    //case WM_LBUTTONUP: //���콺 ��ư ����
    //    is_clicked = FALSE;
    //    break;
#pragma endregion
#pragma region Draw polygon
    case WM_LBUTTONDOWN:
        start.x = LOWORD(lParam);
        start.y = HIWORD(lParam);
        is_clicked = TRUE;
        break;

    case WM_MOUSEMOVE:
        if (is_clicked)
        {
            end.x = LOWORD(lParam);
            end.y = HIWORD(lParam);
            InvalidateRect(handle, nullptr, TRUE); // ���� ���ٰŸ� nullptr�� �ִ� ��.
        }
        break;

    case WM_LBUTTONUP:
        is_clicked = FALSE;
        break;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(handle, &ps);

        HPEN cur_pen = CreatePen(PS_DOT, 1, RGB(255, 0, 0)); //pen style
        HPEN old_pen = static_cast<HPEN>(SelectObject(hdc, cur_pen));

        //      HBRUSH cur_brush = CreateSolidBrush((RGB(255, 0, 255)));
        HBRUSH cur_brush = CreateHatchBrush(HS_CROSS, RGB(255, 0, 255));
        HBRUSH old_brush = static_cast<HBRUSH>(SelectObject(hdc, cur_brush)); //�ٸ� ���̷� ä��� ������

        Rectangle(hdc, start.x, start.y, end.x, end.y);
        SelectObject(hdc, old_pen); //�õ� �� ���� �ְ�, 
        DeleteObject(cur_pen);//���� �� ���� ����

        SelectObject(hdc, old_brush);
        DeleteObject(cur_brush);

        EndPaint(handle, &ps);
    }
    break;
#pragma endregion

    //���α׷� ���� ���̽� 2����
    case WM_CLOSE:
        //PostQuitMessage(0);
        //break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProcA(handle, message, wParam, lParam); // ó���� �ȵ� �κ� ���⼭ ����
    }


    return 0;
}