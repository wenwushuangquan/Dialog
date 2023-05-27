// CPassWord.cpp: 实现文件
//

#include "pch.h"
#include "MFC_QQ.h"
#include "CPassWord.h"


// CPassWord

IMPLEMENT_DYNAMIC(CPassWord, CEdit)

CPassWord::CPassWord()
{

}

CPassWord::~CPassWord()
{
}


BEGIN_MESSAGE_MAP(CPassWord, CEdit)
	ON_WM_CHAR()
END_MESSAGE_MAP()



// CPassWord 消息处理程序




void CPassWord::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
  if (('!' <= nChar) && (nChar <= '~')||
    //为了能够修改、清除数据
    VK_LEFT == nChar ||
    VK_RIGHT == nChar ||
    VK_BACK == nChar ||
    VK_DELETE == nChar)
  {
     CEdit::OnChar(nChar, nRepCnt, nFlags);
  }
  else
  {

    CWnd* phParent = GetParent();
    HWND hParent = ::GetDlgItem(phParent->GetSafeHwnd(), EDT_PASSWORD);
    ShowBalloonTip(hParent, _T("你只能在此键入大小写和特殊字符"), _T("不能接受的字符"), TTI_WARNING);

#if 0
    CString strTip;
    CWnd* pWnd = GetDlgItem(EDT_PASSWORD); // 取得控件的指针
    HWND hwnd = pWnd->GetSafeHwnd(); // 取得控件的句柄
    strTip.Format(_T("密码为空"));
    ShowBalloonTip(hwnd, strTip, _T("提示"), TTI_INFO);
#endif // 自建的MFC类中，this指针不是父类的，存的窗口句柄不是父类。所以不能直接使用MFC

  }
}

void CPassWord::ShowBalloonTip(HWND hWnd, LPCTSTR lpszText, LPCTSTR lpszTittle, int nTTIcon)
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
  //Song();  //发出声音

#else
  MessageBox(lpszText, lpszTittle);
#endif

  ((CEdit*)CWnd::FromHandle(hWnd))->SetSel(0, -1);
}
