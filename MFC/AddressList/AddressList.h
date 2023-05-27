
// AddressList.h: PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"		// 主符号


// CAddressListApp:
// 有关此类的实现，请参阅 AddressList.cpp
//

class CAddressListApp : public CWinApp
{
public:
	CAddressListApp();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CAddressListApp theApp;

#if 0
static void ShowBalloonTip(HWND hWnd, LPCTSTR lpszText, LPCTSTR lpszTittle, int nTTIcon)
{
#ifdef _UNICODE
  EDITBALLOONTIP tagTip;
  tagTip.cbStruct = sizeof(EDITBALLOONTIP);
  tagTip.pszText = lpszText;
  tagTip.pszTitle = lpszTittle;
  tagTip.ttiIcon = nTTIcon;
  Edit_ShowBalloonTip(hWnd, &tagTip);
  MessageBeep(MB_ICONASTERISK);  //发出声音
#else
  MessageBox(lpszText, lpszTittle);
#endif

  ((CEdit*)CWnd::FromHandle(hWnd))->SetSel(0, -1);
}
#endif // 0

