
#include <windows.h>
#define CLASSNAME TEXT("className")
#define WINDOWSNAME TEXT("WindowsName")

#define CLASSNAMESON TEXT("classNameSon")
#define WINDOWSNAMESON TEXT("WindowsNameSon")

#if 1
void ShowErrormsg();
#include <stdio.h>
#include "Resource.h"

#ifdef UNICODE
#define _stprintf _swprintf
#else
#define _stprintf sprintf
#endif

INT_PTR CALLBACK CR37DialogProc(HWND hwndDlg,  // handle to dialog box
  UINT uMsg,     // message  
  WPARAM wParam, // first message parameter
  LPARAM lParam  // second message parameter
);

LRESULT CALLBACK WindowProc(HWND hwnd,      // handle to window
  UINT uMsg,      // message identifier
  WPARAM wParam,  // first message parameter
  LPARAM lParam   // second message parameterWindowProc
)
{
  switch (uMsg)
  {
  case WM_CLOSE:
  {
    PostQuitMessage(0);
    return 0;
  }
  case WM_COMMAND:
  {
    WORD wfrom = HIWORD(wParam);
    WORD wID = LOWORD(wParam);
    if (wfrom == 0)
    {
      switch (wID)
      {
      case MN_OPEN:
      {
        MessageBox(NULL, TEXT("打开"), TEXT("heihie"), MB_OK);
        break;
      }
      case MN_DLG_YES:
      {
        DialogBox(GetModuleHandle(NULL),
          MAKEINTRESOURCE(DLG_TEST),
          hwnd, CR37DialogProc);
        break;
      }
      case MN_DLG_NO:
      {

        break;
      }
      default:
        break;
      }
    }
    else if (wfrom == 1)
    {
      switch (wID)
      {
      case ACCEL_CTRLA:
        MessageBox(NULL, TEXT("Ctr a"), TEXT("heihie"), MB_OK);
        break;

      default:
        break;
      }
    }

    return 0;
  }
  case WM_KEYDOWN:
  {
    //TCHAR szBuf[CHAR_MAX] = { 0 };
    //_stprintf(szBuf, L"%c", wParam);
    //OutputDebugString(szBuf);
    //return 0;
  }
  case WM_CHAR:
  {
    TCHAR szBuf[CHAR_MAX] = { 0 };
    _stprintf(szBuf, L"%c", wParam);
    OutputDebugString(szBuf);
    return 0;
  }

  case WM_PAINT:
  {
#if 1
    PAINTSTRUCT ps;
    HDC hDc = BeginPaint(hwnd, &ps);
    HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(ICN_TEST55));
    DrawIcon(hDc, 0, 0 ,hIcon);
    EndPaint(hwnd, &ps);
#endif // 0

    return 0;
  }

  case WM_LBUTTONDOWN:
  {
    InvalidateRect(hwnd, NULL, TRUE);
    //MessageBox(NULL, NULL, NULL, NULL);
    return 0;
  }

  default:
    break;
  }
  return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

//对话框回调函数
INT_PTR CALLBACK CR37DialogProc(HWND hwndDlg,  // handle to dialog box
  UINT uMsg,     // message  
  WPARAM wParam, // first message parameter
  LPARAM lParam  // second message parameter
)
{
  switch (uMsg)
  {
  case WM_INITDIALOG:
  {
    EnableWindow(GetParent(hwndDlg), TRUE);
    return TRUE;
  }
  case WM_COMMAND:
  {
    WORD wNotiID = HIWORD(wParam);
    WORD wBTNID = LOWORD(wParam);
    switch (wNotiID)
    {
    case BN_CLICKED:
    {
      switch (wBTNID)
      {
      case BTN_TEST:
      {
        MessageBox(NULL, TEXT("ceshi"), NULL, NULL);
        break;
      }
      case BTN_TEST1:
      {
        MessageBox(NULL, TEXT("ceshi1"), NULL, NULL);
        break;
      }
      case BTN_TEST2:
      {
        HWND hTest1 = GetDlgItem(hwndDlg, BTN_TEST1);
        SendMessage(hTest1, BM_CLICK, 0, 0);
        break;
      }
      case BTN_GETTEXT:
      {
        HWND hEdit = GetDlgItem(hwndDlg, EDT_TEST);
        TCHAR szBuf[MAXBYTE] = { 0 };
        //方法一
        //*(WORD*)szBuf = sizeof(szBuf);
        //SendMessage(hEdit, EM_GETLINE, 0, (LPARAM)szBuf);      
        // 
        //方法二 获取窗口的标题
        //SendMessage(hEdit, WM_GETTEXT, sizeof(szBuf), (LPARAM)szBuf);
        
        //方法三  获取窗口的标题
        //GetWindowText(hEdit, szBuf, sizeof(szBuf));

        //方法四
        GetDlgItemText(hwndDlg, EDT_TEST, szBuf, sizeof(szBuf));
        MessageBox(NULL, szBuf, NULL, NULL);
        break;
      }

      default:
        break;
      }//switch (wBTNID)
    }//BN_CLICKED
    default:
      break;
    }//  switch (wNotiID)
    return TRUE;
  }//case WM_COMMAND:
  case WM_CLOSE:
  {
    //DestroyWindow(hwndDlg); 不能在模态对话框中使用。
    EndDialog(hwndDlg, 0);
    //PostQuitMessage(0);  //这个太猛，进程都会被干掉的
    return TRUE;
  }
  }//  switch (uMsg)
  return FALSE;
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
  _In_opt_ HINSTANCE hPrevInstance,
  _In_ LPWSTR    lpCmdLine,
  _In_ int       nCmdShow)
{
  WNDCLASS wc;
  wc.style = CS_VREDRAW | CS_HREDRAW;
  wc.lpfnWndProc = WindowProc;
  wc.cbClsExtra = 0;
  wc.cbWndExtra = 0;
  wc.hInstance = hInstance;
  wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(ICN_TEST));
  wc.hCursor = LoadCursor(hInstance, MAKEINTRESOURCE(CUR_TEST));
  wc.hbrBackground = (HBRUSH)COLOR_ACTIVEBORDER + 1;
  wc.lpszMenuName = MAKEINTRESOURCE(MN_TEST_212);
  //wc.lpszMenuName = NULL;
  wc.lpszClassName = CLASSNAME;

  ATOM ret = RegisterClass(&wc);
  if (ret == 0)
  {
    DWORD dwret = GetLastError();
    ShowErrormsg();
    return 0;
  } //注册窗口

  HWND hWnd = CreateWindow(CLASSNAME, WINDOWSNAME, WS_OVERLAPPEDWINDOW,
    100, 100, 600, 800, NULL, /*LoadMenu(hInstance, MAKEINTRESOURCE(MN_TEST1))*/
    NULL, hInstance, NULL);
  if (hWnd == NULL)
  {
    DWORD dwret = GetLastError();
    ShowErrormsg();
  }
  else
  {
    ShowWindow(hWnd, SW_SHOW);
    UpdateWindow(hWnd);

    HACCEL hAccel = LoadAccelerators(hInstance, MAKEINTRESOURCE(ACCEL_TEST));


    MSG msg;
    BOOL bRet;
    while (bRet = GetMessage(&msg, NULL, 0, 0))
    {
      if (bRet == -1)
      {
        // handle the error and possibly exit
        DWORD dwret = GetLastError();
        ShowErrormsg();
      }
      else
      {
        if (!TranslateAccelerator(hWnd, hAccel, &msg))
        {
          TranslateMessage(&msg);
          DispatchMessage(&msg);
        }
      }

    }
  }

  return 0;
}

void ShowErrormsg()
{
  LPVOID lpMsgBuf;
  FormatMessage(
    FORMAT_MESSAGE_ALLOCATE_BUFFER |
    FORMAT_MESSAGE_FROM_SYSTEM |
    FORMAT_MESSAGE_IGNORE_INSERTS,
    NULL,
    GetLastError(),
    0, // Default language
    (LPTSTR)&lpMsgBuf,
    0,
    NULL
  );
  // Process any inserts in lpMsgBuf.
  // ...
  // Display the string.
  MessageBox(NULL, (LPCTSTR)lpMsgBuf, TEXT("Error"), MB_OK | MB_ICONINFORMATION);
  // Free the buffer.
  LocalFree(lpMsgBuf);

}

#endif // 1
