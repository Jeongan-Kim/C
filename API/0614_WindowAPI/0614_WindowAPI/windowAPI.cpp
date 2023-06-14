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

LRESULT CALLBACK WndProc(HWND handle, UINT message, WPARAM wParam, LPARAM lParam);


//int main �ϴ� ��, APIENTRY : ���⼭���� �����Ѵ�(������)�� �ǹ�, Winmain : Window ���α׷��� ����
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
    case WM_LBUTTONDOWN:
        MessageBoxA(nullptr, "Hello, Window!", "ERROR!!", MB_OKCANCEL);
        break;
        //���α׷� ���� ���̽� 2����
    case WM_CLOSE:
        PostQuitMessage(0);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProcA(handle, message, wParam, lParam); // ó���� �ȵ� �κ� ���⼭ ����
    }


    return 0;
}