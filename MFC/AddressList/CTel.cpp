// CTel.cpp: 实现文件
//

#include "pch.h"
#include "AddressList.h"
#include "CTel.h"


// CTel

IMPLEMENT_DYNAMIC(CTel, CEdit)

CTel::CTel()
{

}

CTel::~CTel()
{
}


BEGIN_MESSAGE_MAP(CTel, CEdit)
	ON_WM_KEYUP()
END_MESSAGE_MAP()



// CTel 消息处理程序

#define TELLENTH 11


void CTel::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
  int nTelLen = GetWindowTextLength();
  CWnd* phParent = GetParent();
  if (nTelLen != TELLENTH)
  {
	HWND hStatic = ::GetDlgItem(phParent->GetSafeHwnd(), STA_TEL);
	::ShowWindow(hStatic, SW_SHOW);
  }
  else
  {
    HWND hStatic = ::GetDlgItem(phParent->GetSafeHwnd(), STA_TEL);
    ::ShowWindow(hStatic, SW_HIDE);
  }
	CEdit::OnKeyUp(nChar, nRepCnt, nFlags);
}
