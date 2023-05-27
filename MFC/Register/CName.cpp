// CName.cpp: 实现文件
//

#include "pch.h"
#include "Register.h"
#include "CName.h"


// CName

IMPLEMENT_DYNAMIC(CName, CEdit)

CName::CName()
{

}

CName::~CName()
{
}


BEGIN_MESSAGE_MAP(CName, CEdit)
  ON_WM_CHAR()
END_MESSAGE_MAP()



// CName 消息处理程序




void CName::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
  // TODO: 在此添加消息处理程序代码和/或调用默认值
  if (
    (('0' <= nChar) && (nChar <= '9')) ||
    (('a' <= nChar) && (nChar <= 'z')) ||
    (('A' <= nChar) && (nChar <= 'Z')) || 
    //为了能够修改、清除数据
    VK_LEFT == nChar ||
    VK_RIGHT == nChar||
    VK_BACK == nChar ||
    VK_DELETE == nChar ||
    nChar == 01 || nChar == 03 || //ctrl + a c
    nChar == 24 || nChar == 22 //ctrl + x v 
    )
  {
    CEdit::OnChar(nChar, nRepCnt, nFlags);
  }
  else
  {
    CWnd* phParent = GetParent();
    HWND hParent = ::GetDlgItem(phParent->GetSafeHwnd(), EDT_NAME);
    ShowBalloonTip(hParent, _T("你不能在此键入空格和特殊字符"), _T("不能接受的字符"), TTI_WARNING);
  }
}

void CName::ShowBalloonTip(HWND hWnd, LPCTSTR lpszText, LPCTSTR lpszTittle, int nTTIcon)
{
  // TODO: 在此处添加实现代码.
#ifdef _UNICODE
  EDITBALLOONTIP tagTip;
  tagTip.cbStruct = sizeof(EDITBALLOONTIP);
  tagTip.pszText = lpszText;
  tagTip.pszTitle = lpszTittle;
  tagTip.ttiIcon = nTTIcon;
  Edit_ShowBalloonTip(hWnd, &tagTip);
  MessageBeep(MB_ICONASTERISK);

#else
  MessageBox(lpszText, lpszTittle);
#endif

  ((CEdit*)CWnd::FromHandle(hWnd))->SetSel(0, -1);
}

