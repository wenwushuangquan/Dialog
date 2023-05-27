// CSearch.cpp: 实现文件
//

#include "pch.h"
#include "AddressList.h"
#include "CSearch.h"


// CSearch

IMPLEMENT_DYNAMIC(CSearch, CEdit)

CSearch::CSearch()
{

}

CSearch::~CSearch()
{
}


BEGIN_MESSAGE_MAP(CSearch, CEdit)
	ON_WM_CHAR()
END_MESSAGE_MAP()



// CSearch 消息处理程序




void CSearch::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
  if (('a' <= nChar && nChar <= 'z') ||
    ('A' <= nChar && nChar <= 'z'))
  {
    CEdit::OnChar(nChar, nRepCnt, nFlags);
  }
  else
  {
    ShowBalloonTip(TEXT("不能接受的字符"), TEXT("您只能在此键入英文"), TTI_ERROR);
  }
}
