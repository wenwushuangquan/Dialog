
// MFC_QQDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFC_QQ.h"
#include "MFC_QQDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
    CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_ABOUTBOX };
#endif

    protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
    DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCQQDlg 对话框



CMFCQQDlg::CMFCQQDlg(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_MFC_QQ_DIALOG, pParent)
  , m_strPassWord(_T(""))
{
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCQQDlg::DoDataExchange(CDataExchange* pDX)
{
  CDialogEx::DoDataExchange(pDX);
  DDX_Control(pDX, EDT_PASSWORD, m_passWord);
  DDX_Text(pDX, EDT_PASSWORD, m_strPassWord);
}

BEGIN_MESSAGE_MAP(CMFCQQDlg, CDialogEx)
    ON_WM_SYSCOMMAND()
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(BTN_LOGOIN, &CMFCQQDlg::OnBnClickedLogoin)
END_MESSAGE_MAP()


// CMFCQQDlg 消息处理程序

BOOL CMFCQQDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // 将“关于...”菜单项添加到系统菜单中。

    // IDM_ABOUTBOX 必须在系统命令范围内。
    ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
    ASSERT(IDM_ABOUTBOX < 0xF000);

    CMenu* pSysMenu = GetSystemMenu(FALSE);
    if (pSysMenu != nullptr)
    {
        BOOL bNameValid;
        CString strAboutMenu;
        bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
        ASSERT(bNameValid);
        if (!strAboutMenu.IsEmpty())
        {
            pSysMenu->AppendMenu(MF_SEPARATOR);
            pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
        }
    }

    // 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
    //  执行此操作
    SetIcon(m_hIcon, TRUE);			// 设置大图标
    SetIcon(m_hIcon, FALSE);		// 设置小图标

    // TODO: 在此添加额外的初始化代码

    return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCQQDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
    if ((nID & 0xFFF0) == IDM_ABOUTBOX)
    {
        CAboutDlg dlgAbout;
        dlgAbout.DoModal();
    }
    else
    {
        CDialogEx::OnSysCommand(nID, lParam);
    }
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCQQDlg::OnPaint()
{
    if (IsIconic())
    {
        CPaintDC dc(this); // 用于绘制的设备上下文

        SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

        // 使图标在工作区矩形中居中
        int cxIcon = GetSystemMetrics(SM_CXICON);
        int cyIcon = GetSystemMetrics(SM_CYICON);
        CRect rect;
        GetClientRect(&rect);
        int x = (rect.Width() - cxIcon + 1) / 2;
        int y = (rect.Height() - cyIcon + 1) / 2;

        // 绘制图标
        dc.DrawIcon(x, y, m_hIcon);
    }
    else
    {
        CDialogEx::OnPaint();
    }
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCQQDlg::OnQueryDragIcon()
{
    return static_cast<HCURSOR>(m_hIcon);
}

void CMFCQQDlg::ShowBalloonTip(HWND hWnd, LPCTSTR lpszText, LPCTSTR lpszTittle, int nTTIcon)
{
    // TODO: 在此处添加实现代码.
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


void CMFCQQDlg::OnBnClickedLogoin()
{
    // TODO: 在此添加控件通知处理程序代码
  UpdateData();
  bool bRtn = m_strPassWord.IsEmpty();
  if (bRtn)
  {
    CString strTip;
    CWnd* pWnd = GetDlgItem(EDT_PASSWORD); // 取得控件的指针
    HWND hwnd = pWnd->GetSafeHwnd(); // 取得控件的句柄
    strTip.Format(_T("密码为空"));
    ShowBalloonTip(hwnd, strTip, _T("提示"), TTI_INFO);
  }
  else
  {
    if (!Filter())
    {
      CString strTip;
      CWnd* pWnd = GetDlgItem(EDT_PASSWORD); // 取得控件的指针
      HWND hwnd = pWnd->GetSafeHwnd(); // 取得控件的句柄
      strTip.Format(_T("密码必须有大小写和特殊字符"));
      ShowBalloonTip(hwnd, strTip, _T("提示"), TTI_INFO);
    }
    else
    {
      AfxMessageBox(TEXT("登录成功！"));
    }

  }


}


// 筛选有大小写和特殊字符
bool CMFCQQDlg::Filter()
{
  // TODO: 在此处添加实现代码.
  m_nFlag = 0;
  SpecialCharacter();
  CapitalLetter();
  LowerCase();
  if (m_nFlag == 3)
  {
    return true;
  }

  return false;
}


// 特殊字符的筛选
void CMFCQQDlg::SpecialCharacter()
{
  // TODO: 在此处添加实现代码.
  
#if 0
  CHAR c = '!';
  for (; c <= '/'; ++c)
  {
    int nFindRtn = m_strPassWord.Find(c, 0);
    if (nFindRtn >= 0)
    {
      m_nFlag += 1;
      goto EXIT;
    }
    if (c == '/')
    {
      c = ':';
      for (; c <= '@'; ++c)
      {
        int nFindRtn = m_strPassWord.Find(c, 0);
        if (nFindRtn >= 0)
        {
          m_nFlag += 1;
          goto EXIT;
        }
        if (c == '@')
        {
          c = '[';
          for (; c <= '`'; ++c)
          {
            int nFindRtn = m_strPassWord.Find(c, 0);
            if (nFindRtn >= 0)
            {
              m_nFlag += 1;
              goto EXIT;
            }
            if (c == '`')
            {
              c = '{';
              for (; c <= '~'; ++c)
              {
                int nFindRtn = m_strPassWord.Find(c, 0);
                if (nFindRtn >= 0)
                {
                  m_nFlag += 1;
                  goto EXIT;
                }
                if (c == '~')
                {
                  goto EXIT;
                }
              }
            }
          }
        }
      }
    }
  }
EXIT:
  return -1;
#endif // “屎山代码”

  char cTmp = '!';
  while (true)
  {
    if (
      (('0' <= cTmp) && (cTmp <= '9')) ||
      (('a' <= cTmp) && (cTmp <= 'z')) ||
      (('A' <= cTmp) && (cTmp <= 'Z'))
      )
    {
      cTmp++;
      continue;
    }
    int nFind = m_strPassWord.Find(cTmp, 0);
    if (nFind >= 0)
    {
      m_nFlag += 1;
      break;
    }
    else
    {
      cTmp++;
      if (cTmp == '~' + 1)
      {
        break;
      }
    }
  }
}


// 大写字符
void CMFCQQDlg::CapitalLetter()
{
  // TODO: 在此处添加实现代码.
  CHAR c = 'A';
  for (; c <= 'Z'; ++c)
  {
    int nFindRtn = m_strPassWord.Find(c, 0);
    if (nFindRtn >= 0)
    {
      m_nFlag += 1;
      break;
    }
  }
}


// 小写字符
void CMFCQQDlg::LowerCase()
{
  // TODO: 在此处添加实现代码.
  CHAR c = 'a';
  for (; c <= 'z'; ++c)
  {
    int nFindRtn = m_strPassWord.Find(c, 0);
    if (nFindRtn >= 0)
    {
      m_nFlag += 1;
      break;
    }
  }
}
