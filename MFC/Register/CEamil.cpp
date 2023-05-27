// CEamil.cpp: 实现文件
//
#pragma once
#include "pch.h"
#include "Register.h"
#include "CEamil.h"



// CEamil

IMPLEMENT_DYNAMIC(CEamil, CEdit)

CEamil::CEamil()
{

}

CEamil::~CEamil()
{
}


BEGIN_MESSAGE_MAP(CEamil, CEdit)
	ON_WM_CHAR()
END_MESSAGE_MAP()



// CEamil 消息处理程序




void CEamil::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
  // TODO: 在此添加消息处理程序代码和/或调用默认值
  if (
    (('0' <= nChar) && (nChar <= '9')) ||
    (('a' <= nChar) && (nChar <= 'z')) ||
    (('A' <= nChar) && (nChar <= 'Z')) ||
    //为了能够修改、清除数据
    VK_LEFT == nChar ||
    VK_RIGHT == nChar ||
    VK_BACK == nChar ||
    VK_DELETE == nChar || '@' == nChar || '.' == nChar
    ) 
  {
    CEdit::OnChar(nChar, nRepCnt, nFlags);
  }
  else
  {
    CWnd* phParent = GetParent();
    HWND hParent = ::GetDlgItem(phParent->GetSafeHwnd(), EDT_EMAIL);
    ::ShowBalloonTip(hParent, _T("你只能在此键入字母或数字还有@."), _T("不能接受的字符"), TTI_WARNING);
  }
}

