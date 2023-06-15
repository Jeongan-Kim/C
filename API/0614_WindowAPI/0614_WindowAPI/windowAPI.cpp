/*
   API : application program interface (응용 프로그래밍에 필요한 인터페이스)

   이미 만들어져 있는 함수들을 호출해서 코딩하게 됨.
   윈도우 창을 개발하는 데에 필요한 함수들을 사용하는 것 -> windowAPI

   지금까지의 실행창인 콘솔창을 사용하지 않고 윈도우 창을 만들게 된다.
   (속성 -> 고급 -> 문자집합 -> 멀티 문자 / 속성 -> 링커 -> 시스템 -> 콘솔창을 창으로 변경)
*/

/*
   구성 요소(윈도우 프로그래밍의 동작 방식)
   : 메세지(이벤트, 마우스를 클릭하는 등),
   메세지 큐(메세지를 큐 안에 저장시킨다. 선입선출),
   메세지 루프(큐에 들어있는 메세지를 읽어서 처리를 위해 프로시저로 넘겨주는 반복문 형태),
   윈도우 프로시저(루프에서 알맞은 형태로 변환이 되어 받은 메세지들을 개발자가 만든 함수(WndProc)에 맞게 처리해 줌.
*/

/*
   LPSTR - long pointer str = char*
   LPCSTR - const char*
   LPWSTR - wchar_t*
   LPCWSTR - const wchar_t*


   함수 호출 방식
   - cdecl : c나 c++에서 사용
   - stdcall : windowAPI에서 사용
   callback함수는 stdcall 형식으로 호출되는 함수이다.
   (운영체제에 의해서 필요할때 호출되는 함수)
*/

#include <Windows.h> //이제 이 헤더를 사용
#include <cassert>
#include <string> //지금까지 쓴 string은 iostream에 있었던 거라 iostream없을 때에는 string 헤더파일 필요

LRESULT CALLBACK WndProc(HWND handle, UINT message, WPARAM wParam, LPARAM lParam);


//int main 하던 거, APIENTRY : 여기서부터 진입한다(진입점)는 의미, WinMain : Window 프로그램의 메인
int APIENTRY WinMain(
    HINSTANCE hInstance, //window의 창. 그 자체의 실체를 의미하는 식별자
    HINSTANCE prevInstance,
    LPSTR lpszCmdParam, //LPSTR : 문자열이라고 생각하면 되는데, 헝가리 형식의 문자열 작성법을 말한다.(i_a -> int a)
    int nCmdShow //cmd : command window. 어떤 식으로 창에 나타내어 줄건지 문자열로 나타내는 것.
)
{
    WNDCLASSA wnd_class; // A : ASCII. 윈도우 클래스를 미리 만들어 놓고 사용하는 것.

    wnd_class.cbClsExtra = 0; //확장된 정보를 사용할 건지 유무에 대한 정보
    wnd_class.cbWndExtra = 0; //위와 동일
    wnd_class.hbrBackground = static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH)); // GetStockObject : 색 정보들을 담아놓은 창고. ,창 색을 흰색으로.
    //stockobject를 변수로 사용하기 위해 staticcast 형변환을 한다.
    wnd_class.hCursor = LoadCursor(nullptr, IDC_CROSS); //커서 모양 설정. 십자 모양을 쓰겠다.
    wnd_class.hIcon = LoadIcon(nullptr, IDI_ERROR); // 프로그램 실행시 나오는 아이콘 모양 설정
    wnd_class.hInstance = hInstance;// 위에서 인스턴스 할당 받고 있는 걸 기본으로 받아 오겠다.
    wnd_class.lpfnWndProc = WndProc; //처리되고 있는 걸 연동시켜주는 것(메세지 처리 함수)
    wnd_class.lpszClassName = "First Window"; // 문서화 시키는 것. 나중에 이 파일 이름으로 찾아줄 수 있음
    wnd_class.lpszMenuName = nullptr;
    wnd_class.style = CS_HREDRAW | CS_VREDRAW; // window 스타일 정해주는 것.

    //이렇게 기본 설정을 한 후, 등록을 해줘야 함.
    RegisterClassA(&wnd_class);//등록을 하면 이제 얘네를 찾아 쓰면서 사용할 수 있게 됨.

    HWND hwnd = CreateWindowA //윈도우가 실행되는 순간에 들어가는 애들을 만드는 것. 여러가지 넣어보며 만들어봐도 좋음
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

    assert(hwnd != nullptr); //제대로 생성됐는지 자주 확인해 주는 게 좋음

    ShowWindow(hwnd, nCmdShow); //만들어졌으면 보여주기
    ShowCursor(TRUE); // 커서 보일지 설정

    MSG message;
    ZeroMemory(&message, sizeof(MSG)); // 제로메모리라는 매크로로 윈도우 message를 안전하게 초기화. 모두 0으로 초기화됨.

    while (GetMessage(&message, nullptr, 0, 0)) // GetMessage : 메시지가 들어 올때까지 대기.
    {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }

    //만들고 해제까지. 포인터들로 이루어져 있기 때문에
    DestroyWindow(hwnd);
    UnregisterClassA("First Window", hInstance);

    return 0;
}

//handle은 간단하게 윈도우에서 포인터.
//message는 이벤트의 종류를 받는 변수
//wParam, lParam. 부가적인 정보를 받는 변수
LRESULT CALLBACK WndProc(HWND handle, UINT message, WPARAM wParam, LPARAM lParam)
{
    static POINT position; //마우스 위치
    static POINT start;
    static POINT end;
    static BOOL is_clicked = FALSE; //마우스 클릭됐는지에 대한 정보

    static RECT rect1 = { 100, 100, 200, 200 }; // 마우스로 그리는 사각형. 값은 좌표값
    static RECT rect2 = { 300, 300, 400, 400 };
    static BOOL is_intersect = FALSE;

    //들어온 메세지 처리 
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

    //    HDC hdc = GetDC(handle); // GetDC를 통해 핸들을 받아오는 것.. HDC : Handle to Device Context (텍스트를 띄우거나 그림들을 그리기 위해 필요한 정보가 담긴 곳)
    //    TextOutA(hdc, 500, 300, str.c_str(), str.length()); //텍스트 출력 함수/ str.c_str() 은 문자열을 char형으로 가져오라는 뜻
    //    ReleaseDC(handle, hdc); //해제 하기
    //}
    //break;

    //case WM_PAINT: //윈도우가 가려졌을 때 실행되는데, 다시 나타났을 때 글씨가 안보이는 것을 방지하고자 호출됨.(화면이 계속 유지되도록 갱신해서 그려주는 장치이다)
    //{
    //    std::string str = "WM_PAINT message occurred!!";

    //    PAINTSTRUCT ps;
    //    HDC hdc = BeginPaint(handle, &ps); //그리려면 HDC가 필요하므로!
    //    TextOutA(hdc, 500, 350, str.c_str(), str.length());

    //    EndPaint(handle, &ps); //해체 하기
    //}
    //break;
#pragma endregion
#pragma region Text Moving
    //case WM_KEYDOWN:
    //    if      (wParam == VK_UP)    position.y -= 10;
    //    else if (wParam == VK_DOWN)  position.y += 10;
    //    if      (wParam == VK_RIGHT) position.x += 10;
    //    else if (wParam == VK_LEFT)  position.x -= 10;

    //    InvalidateRect(handle, nullptr, TRUE); //무효화 영역(창크기가 변경되거나 가려졌을때)에 대해서 지정해주는 함수
    //    //그림이 창을 나갔을때(무효화 영역으로 나갔을떄) 다시 돌아와도 나와야 하니 갱신해 주는 코드
    //    break;

    //case WM_PAINT:
    //{
    //    PAINTSTRUCT ps; //그리기를 담당하는 구조체.
    //    HDC hdc = BeginPaint(handle, &ps);
    //    TextOut(hdc, position.x, position.y, "♥", 2);
    //    EndPaint(handle, &ps);
    //}
    //break;
#pragma endregion
#pragma region Mouse Moving
    //case WM_MOUSEMOVE: //마우스의 좌표 정보 받아오는 것
    //    position.x = LOWORD(lParam);
    //    position.y = HIWORD(lParam);

    //    InvalidateRect(handle, nullptr, TRUE);
    //    break;

    //case WM_PAINT:
    //{
    //    std::string str = "";
    //    str += std::to_string(position.x); //to_string : 정수열을 문자열로 변경시켜주는 stoi와 반대
    //    str += ", ";
    //    str += std::to_string(position.y);

    //    PAINTSTRUCT ps;
    //    HDC hdc = BeginPaint(handle, &ps);
    //    TextOutA(hdc, position.x, position.y, str.c_str(), str.length());

    //    //Line
    //    MoveToEx(hdc, 100, 100, nullptr); //커서를 움직여서 특정 위치로 이동 시키는 것
    //    LineTo(hdc, 500, 500); //라인 그리는 함수

    //    //도형
    //    Rectangle(hdc, 500, 500, 600, 600); //사각형
    //    Ellipse(hdc, 300, 300, 400, 400); //원

    //    EndPaint(handle, &ps);
    //}
    //    break;
#pragma endregion
#pragma region Paint Brush
    //case WM_LBUTTONDOWN: //마우스 버튼 누르기
    //    position.x = LOWORD(lParam);
    //    position.y = HIWORD(lParam);
    //    is_clicked = TRUE;
    //    break;
    //    
    //case WM_MOUSEMOVE:
    //    if (is_clicked) //마우스가 클릭됐을때 작업됨
    //    {
    //        HDC hdc = GetDC(handle);

    //        MoveToEx(hdc, position.x, position.y, nullptr);
    //        //움직인 위치 업데이트
    //        position.x = LOWORD(lParam);
    //        position.y = HIWORD(lParam);

    //        //움직인데까지 선그리기
    //        LineTo(hdc, position.x, position.y);
    //        ReleaseDC(handle, hdc); //해제
    //    }
    //    break;

    //case WM_LBUTTONUP: //마우스 버튼 떼기
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
            InvalidateRect(handle, nullptr, TRUE); // 값을 안줄거면 nullptr로 넣는 것.
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
        HBRUSH old_brush = static_cast<HBRUSH>(SelectObject(hdc, cur_brush)); //다른 무늬로 채우고 싶을때

        Rectangle(hdc, start.x, start.y, end.x, end.y);
        SelectObject(hdc, old_pen); //올드 펜 정보 넣고, 
        DeleteObject(cur_pen);//현재 팬 정보 삭제

        SelectObject(hdc, old_brush);
        DeleteObject(cur_brush);

        EndPaint(handle, &ps);
    }
    break;
#pragma endregion

    //프로그램 종료 케이스 2가지
    case WM_CLOSE:
        //PostQuitMessage(0);
        //break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProcA(handle, message, wParam, lParam); // 처리가 안된 부분 여기서 해제
    }


    return 0;
}