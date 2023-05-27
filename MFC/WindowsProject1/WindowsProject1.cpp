// WindowsProject1.cpp : 定义应用程序的入口点。
//

#include "framework.h"
#include "WindowsProject1.h"

INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

WNDPROC g_oldProce = NULL;
WNDPROC g_oldProce1 = NULL;
HINSTANCE g_hInstance = NULL;
int g_i = 0;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
  g_hInstance = hInstance;
  return DialogBox(hInstance, MAKEINTRESOURCE(IDD_ABOUTBOX), NULL, About);
}

LRESULT CALLBACK MyPro(HWND hEdit, UINT message, WPARAM wParam, LPARAM lParam)
{
  if (message == WM_CHAR)
  {
    if (
      (('0' <= wParam) && (wParam <= '9')) ||
      (('a' <= wParam) && (wParam <= 'z')) ||
      (('A' <= wParam) && (wParam <= 'Z'))
      )
    {
      return g_oldProce(hEdit, message, wParam, lParam);
    }
    else
    {
      return 0;
    }
  }
  return g_oldProce(hEdit, message, wParam, lParam);
}

LRESULT CALLBACK MyPro1(HWND hEdit, UINT message, WPARAM wParam, LPARAM lParam)
{
  if (message == WM_CHAR)
  {
    if (
      (('0' <= wParam) && (wParam <= '9')) ||
      (('a' <= wParam) && (wParam <= 'z')) ||
      (('A' <= wParam) && (wParam <= 'Z'))
      )
    {
      return g_oldProce1(hEdit, message, wParam, lParam);
    }
    else
    {
      return 0;
    }
  }
  return g_oldProce1(hEdit, message, wParam, lParam);
}


// “关于”框的消息处理程序。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        else if (LOWORD(wParam) == BTN_TEST)
        {
          HWND hEdit = GetDlgItem(hDlg, EDT_TEST);
          if (g_oldProce == NULL)
          {
            g_oldProce = (WNDPROC)GetWindowLong(hEdit, GWL_WNDPROC);
            SetWindowLong(hEdit, GWL_WNDPROC, (LONG)MyPro);
          }
        }
        else if (LOWORD(wParam) == BTN_TEST1)
        {
          HWND hEdit1 = GetDlgItem(hDlg, EDT_TEST1);
          if (g_oldProce1 == NULL)
          {
            g_oldProce1 = (WNDPROC)GetClassLong(hEdit1, GCL_WNDPROC);
            SetClassLong(hEdit1, GCL_WNDPROC, (LONG)MyPro1);
          }
        }
        else if (LOWORD(wParam) == BTN_TEST2)
        {
          //MessageBox(NULL, NULL, NULL, NULL);
          
          HWND hEdit = CreateWindow(TEXT("EDIT"), TEXT("嘿嘿"), 
            WS_CHILDWINDOW,
            41, 230+g_i, 150, 14, hDlg, NULL, g_hInstance, NULL);
          ShowWindow(hEdit, SW_SHOW);
          g_i += 30;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
