// CMyEdit.cpp: 实现文件
//

#include "pch.h"
#include "Dialog.h"
#include "CMyEdit.h"


// CMyEdit

IMPLEMENT_DYNAMIC(CMyEdit, CEdit)

CMyEdit::CMyEdit()
{

}

CMyEdit::~CMyEdit()
{
}


BEGIN_MESSAGE_MAP(CMyEdit, CEdit)
	ON_WM_CHAR()
END_MESSAGE_MAP()



// CMyEdit 消息处理程序




void CMyEdit::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
  if (
    (('0' <= nChar) && (nChar <= '9')) ||
    (('a' <= nChar) && (nChar <= 'z')) ||
    (('A' <= nChar) && (nChar <= 'Z'))
    )
  {
    return CEdit::OnChar(nChar, nRepCnt, nFlags);
  }
  CEdit::OnChar(nChar, nRepCnt, nFlags);
}
