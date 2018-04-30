// demo.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "demo.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

enum Colors{ EMPTY = 0, RED = RGB(0xff, 0, 0), GREEN = RGB(0, 0xff, 0), BLUE = RGB(0, 0, 0xff) };

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_DEMO, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DEMO));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = 0;// CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DEMO));
	wcex.hCursor =  LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = CreateSolidBrush(RGB(0, 0, 100));//(HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName = 0;// MAKEINTRESOURCE(IDC_DEMO);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   //hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
   //   CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   hWnd = CreateWindow(szWindowClass, szTitle, WS_POPUP | WS_CAPTION ,
	   0, 0, 20*10+6, 20*10+6, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);
   ShowCursor(FALSE);
   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static UINT msgDim = RegisterWindowMessageA("Dimensions");
	static UINT msgColor = RegisterWindowMessageA("Color");
	static UINT mTestDims = RegisterWindowMessageA("TestDimensions");

	//static Color color;
	static bool flag;
	static COLORREF color = RGB(255, 0, 0);
	static  int Rows = 10, Columns = 10;
	const int width = 20;
	static int* p/* = new int[Rows * Columns]*/;
	static int** pp /*= new int*[Rows]*/;
	//if (flag == false)
	//{
	//	flag = true;
	//	for (int i = 0; i < Rows * Columns; i++)
	//	{
	//		p[i] = EMPTY;
	//	}
	//	
	//	for (int i = 0; i < Rows; i++)
	//	{
	//		pp[i] = p + i*Columns;
	//	}
	//}
	if (message == msgDim)
	{
		flag = true;
		Rows = (int)wParam;
		Columns = (int)lParam;
		RECT rClient;
		GetClientRect(hWnd, &rClient);
		RECT rWindow;
		GetWindowRect(hWnd, &rWindow);

		RECT r;
		r.left = rWindow.left;
		r.top = rWindow.top;
		//r.right = r.left + Rows*width + ((rWindow.right - rWindow.left)-(rClient.right - rClient.left));//NN
		//r.bottom = r.top + Columns*width +((rWindow.bottom - rWindow.top) - (rClient.bottom - rClient.top)); //толщина рамки + заголовок//NN
		r.right = r.left + Columns*width + ((rWindow.right - rWindow.left) - (rClient.right - rClient.left));
		r.bottom = r.top + Rows*width + ((rWindow.bottom - rWindow.top) - (rClient.bottom - rClient.top)); //толщина рамки + заголовок
		delete[] p;
		p = new int[Rows * Columns];
		delete[] pp;
		pp = new int*[Rows];

			for (int i = 0; i < Rows * Columns; i++)
			{
				p[i] = EMPTY;
			}

			for (int i = 0; i < Rows; i++)
			{
				pp[i] = p + i*Columns;
			}
		
		
		//SetWindowPos(hWnd, HWND_NOTOPMOST, r.left, r.top, r.right - r.left, r.bottom - r.top, SWP_SHOWWINDOW | SWP_NOACTIVATE);
		MoveWindow(hWnd, r.left, r.top, r.right - r.left, r.bottom - r.top, TRUE);
		InvalidateRect(hWnd, 0, FALSE);
		UpdateWindow(hWnd);
	}
	else if (message == mTestDims)
	{
		return ((Rows == (int)wParam) && (Columns == (int)lParam));
	}

	else{

		int wmId, wmEvent;
		PAINTSTRUCT ps;
		HDC hdc;

		switch (message)
		{
		
		case WM_COMMAND:
			wmId = LOWORD(wParam);
			wmEvent = HIWORD(wParam);
			// Parse the menu selections:
			switch (wmId)
			{
			case IDM_ABOUT:
				//DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
				break;
			case IDM_EXIT:
				DestroyWindow(hWnd);
				break;
			default:
				return DefWindowProc(hWnd, message, wParam, lParam);
			}
			break;
		case WM_PAINT:
		{
						 hdc = BeginPaint(hWnd, &ps);
						 HDC memDC = CreateCompatibleDC(hdc);
						 RECT r;
						 GetClientRect(hWnd, &r);
						 HBITMAP memBM = CreateCompatibleBitmap(hdc, r.right-r.left, r.bottom - r.top);
						 SelectObject(memDC, memBM);

						 //Рисуем фон
						 {
							 HBRUSH hbrush = CreateSolidBrush(RGB(0, 0, 100));
							 HGDIOBJ oldbrush = SelectObject(memDC, hbrush);
							 Rectangle(memDC, 0,0,r.right, r.bottom);
							 SelectObject(memDC, oldbrush);
							 DeleteObject(hbrush);
						 }
						 if (flag)
						 {

							 //Рисуем сетку
							 HPEN hpen = CreatePen(PS_SOLID, 1, RGB(200, 200, 200));
							 HGDIOBJ oldpen = SelectObject(memDC, hpen);;


							 //int w = width;
							 //for (int i = 1; i < Rows; i++)
							 //{
								// MoveToEx(memDC, w, 0, 0);
								// LineTo(memDC, w, Rows * i * width);
								//// LineTo(memDC, w, Columns * i * width);//NK
								// w += width;
							 //}
							 //int h = width;
							 //for (int i = 1; i < Rows; i++)
							 //{
								// MoveToEx(memDC, 0, h, 0);
								// LineTo(memDC, Columns * i * width, h);
								// h += width;
							 //}
							 int w = width;
							 for (int i = 1; i < Columns; i++)
							 {
							  MoveToEx(memDC, w, 0, 0);
							  LineTo(memDC, w, Rows * i * width);
							 // LineTo(memDC, w, Columns * i * width);//NK
							  w += width;
							 }
							 int h = width;
							 for (int i = 1; i < Rows; i++)
							 {
							  MoveToEx(memDC, 0, h, 0);
							  LineTo(memDC, Columns * i * width, h);
							  h += width;
							 }

							 SelectObject(memDC, oldpen);
							 DeleteObject(hpen);

							 //Рисуем шарики
							 for (int i = 0; i < Rows; i++)
							 {
								 for (int j = 0; j < Columns; j++)
								 {

									 if (pp[i][j] != EMPTY)
									 {
										 HBRUSH hbrush = CreateSolidBrush(pp[i][j]);
										 HGDIOBJ oldbrush = SelectObject(memDC, hbrush);
										 Ellipse(memDC, j*width + 1, i*width + 1, (j + 1)*width, (i + 1)*width);
										 SelectObject(memDC, oldbrush);
										 DeleteObject(hbrush);
									 }
								 }
							 }

						 }

						 BitBlt(hdc, 0, 0, r.right - r.left, r.bottom - r.top, memDC, 0, 0, SRCCOPY);
						 // TODO: Add any drawing code here...
						 DeleteObject(memDC);
						 EndPaint(hWnd, &ps);
		}
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		case WM_COPYDATA:
		{
							
							COPYDATASTRUCT* pcd = (COPYDATASTRUCT*)lParam;
							if (pcd->dwData == 33)
							{
								memcpy(p, pcd->lpData, pcd->cbData);
								InvalidateRect(hWnd, 0, FALSE);
								UpdateWindow(hWnd);
							}

		}
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	return 0;
}

// Message handler for about box.
//INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
//{
//	UNREFERENCED_PARAMETER(lParam);
//	switch (message)
//	{
//	case WM_INITDIALOG:
//		return (INT_PTR)TRUE;
//
//	case WM_COMMAND:
//		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
//		{
//			EndDialog(hDlg, LOWORD(wParam));
//			return (INT_PTR)TRUE;
//		}
//		break;
//	}
//	return (INT_PTR)FALSE;
//}
