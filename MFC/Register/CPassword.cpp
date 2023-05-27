// CPassword.cpp: 实现文件
//

#include "pch.h"
#include "CPassword.h"
#include "Register.h"

#pragma once

// CPassword

IMPLEMENT_DYNAMIC(CPassword, CEdit)

CPassword::CPassword()
{

}

CPassword::~CPassword()
{
}


BEGIN_MESSAGE_MAP(CPassword, CEdit)
	ON_WM_CHAR()
END_MESSAGE_MAP()



// CPassword 消息处理程序




void CPassword::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
  // TODO: 在此添加消息处理程序代码和/或调用默认值
  if (
    (('!' <= nChar) && (nChar <= '~')) ||
    //为了能够修改、清除数据
    VK_LEFT == nChar ||
    VK_RIGHT == nChar ||
    VK_BACK == nChar ||
    VK_DELETE == nChar 
    )
  {
    CEdit::OnChar(nChar, nRepCnt, nFlags);
  }
  else
  {
    CWnd* phParent = GetParent();
    HWND hParent = ::GetDlgItem(phParent->GetSafeHwnd(), EDT_PASSWORD);
    ::ShowBalloonTip(hParent, _T("你只能在此键入大小写和特殊字符"), _T("不能接受的字符"), TTI_WARNING);
  }
}
