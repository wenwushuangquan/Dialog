
// CommonControlDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "CommonControl.h"
#include "CommonControlDlg.h"
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


// CCommonControlDlg 对话框



CCommonControlDlg::CCommonControlDlg(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_COMMONCONTROL_DIALOG, pParent)
    , m_strName(_T(""))
  , m_nGender(0)
  , m_bCode(FALSE)
  , m_bDebug(FALSE)
  , m_bReverse(FALSE)
{
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCommonControlDlg::DoDataExchange(CDataExchange* pDX)
{
  CDialogEx::DoDataExchange(pDX);
  DDX_Text(pDX, EDT_NAME, m_strName);
  DDX_Radio(pDX, RAD_MAN, m_nGender);
  DDX_Check(pDX, CEK_CODE, m_bCode);
  DDX_Check(pDX, CEK_DEBUG, m_bDebug);
  DDX_Check(pDX, CEK_REVERSE, m_bReverse);
  DDX_Control(pDX, COM_FROM, m_comFrom);
  DDX_Control(pDX, LIS_TEST, m_lisTest);
}

BEGIN_MESSAGE_MAP(CCommonControlDlg, CDialogEx)
    ON_WM_SYSCOMMAND()
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(BTN_ADD, &CCommonControlDlg::OnBnClickedAdd)
  ON_BN_CLICKED(BTN_SELECTED, &CCommonControlDlg::OnBnClickedSelected)
  ON_BN_CLICKED(BTN_DELETE, &CCommonControlDlg::OnBnClickedDelete)
  ON_BN_CLICKED(BTN_TEST, &CCommonControlDlg::OnBnClickedTest)
  ON_BN_CLICKED(BTN_MODIY, &CCommonControlDlg::OnBnClickedModiy)
END_MESSAGE_MAP()


// CCommonControlDlg 消息处理程序

BOOL CCommonControlDlg::OnInitDialog()
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
    int nIdx = 0;
    nIdx = m_comFrom.AddString(_T("山东"));
    m_comFrom.SetItemData(nIdx, 0x10000001);
    nIdx = m_comFrom.AddString(_T("湖北"));
    m_comFrom.SetItemData(nIdx, 0x10000002);
    nIdx = m_comFrom.AddString(_T("湖南"));
    m_comFrom.SetItemData(nIdx, 0x10000003);
    nIdx = m_comFrom.AddString(_T("上海"));
    m_comFrom.SetItemData(nIdx, 0x10000004);
    nIdx = m_comFrom.AddString(_T("北京"));
    m_comFrom.SetItemData(nIdx, 0x10000005);
    m_comFrom.SetCurSel(0);  //程序运行，会默认显示nIdx索引对应的值。

    int nColIdx = 0;
    m_lisTest.InsertColumn(nColIdx++, TEXT("学号"));
    m_lisTest.InsertColumn(nColIdx++, TEXT("姓名"));
    m_lisTest.InsertColumn(nColIdx++, TEXT("性别"));
    m_lisTest.InsertColumn(nColIdx++, TEXT("爱好"));
    m_lisTest.InsertColumn(nColIdx++, TEXT("班级"));
    for (int i = 0; i < nColIdx; ++i)
    {
      m_lisTest.SetColumnWidth(i, LVSCW_AUTOSIZE_USEHEADER);
    }

     m_lisTest.SetExtendedStyle(m_lisTest.GetExtendedStyle() |
   LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
   

    return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCommonControlDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCommonControlDlg::OnPaint()
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
HCURSOR CCommonControlDlg::OnQueryDragIcon()
{
    return static_cast<HCURSOR>(m_hIcon);
}


//int nItemIdx = 9;

void CCommonControlDlg::OnBnClickedAdd()
{
    // TODO: 在此添加控件通知处理程序代码
  int nColIdx = 0;  
  m_lisTest.InsertItem(m_nItemIdx, TEXT("10001"));
  m_lisTest.SetItemText(m_nItemIdx, ++nColIdx, TEXT("小红"));
  m_lisTest.SetItemText(m_nItemIdx, ++nColIdx, TEXT("女"));   
  m_lisTest.SetItemText(m_nItemIdx, ++nColIdx, TEXT("debug"));
  m_lisTest.SetItemText(m_nItemIdx++, ++nColIdx, TEXT("1班")); 


  nColIdx = 0;  
  m_lisTest.InsertItem(m_nItemIdx, TEXT("10002"));
  m_lisTest.SetItemText(m_nItemIdx, ++nColIdx, TEXT("琪琪"));
  m_lisTest.SetItemText(m_nItemIdx, ++nColIdx, TEXT("女"));
  m_lisTest.SetItemText(m_nItemIdx, ++nColIdx, TEXT("干饭"));
  m_lisTest.SetItemText(m_nItemIdx++, ++nColIdx, TEXT("7班"));


  nColIdx = 0;  //一个数据添加完成后，需要加加
  m_lisTest.InsertItem(m_nItemIdx, TEXT("10003"));
  m_lisTest.SetItemText(m_nItemIdx, ++nColIdx, TEXT("露露"));
  m_lisTest.SetItemText(m_nItemIdx, ++nColIdx, TEXT("女"));
  m_lisTest.SetItemText(m_nItemIdx, ++nColIdx, TEXT("武武"));
  m_lisTest.SetItemText(m_nItemIdx++, ++nColIdx, TEXT("五班"));

  //获得总列数
  CHeaderCtrl *pHeadCtrl = m_lisTest.GetHeaderCtrl();
  nColIdx = pHeadCtrl->GetItemCount();


  for (int i = 0; i < nColIdx; ++i)
  {
    m_lisTest.SetColumnWidth(i, LVSCW_AUTOSIZE);
  }

}


void CCommonControlDlg::OnBnClickedSelected()
{
  // TODO: 在此添加控件通知处理程序代码
  int nIdx = m_lisTest.GetSelectionMark();
  int nColIdx = 0;
  CString strID = m_lisTest.GetItemText(nIdx, nColIdx++);
  CString strName   = m_lisTest.GetItemText(nIdx, nColIdx++);
  CString strGender = m_lisTest.GetItemText(nIdx, nColIdx++);
  CString strHobby  = m_lisTest.GetItemText(nIdx, nColIdx++);
  CString strClass  = m_lisTest.GetItemText(nIdx, nColIdx++);
  CString strFmt;
  strFmt.Format(TEXT("索引:%d 学号:%s 姓名:%s 性别:%s 爱好:%s 班级:%s"), 
    nIdx,
    strID.GetString(),
    strName.GetString(),
    strGender.GetString(),
    strHobby.GetString(),
    strClass.GetString());
  AfxMessageBox(strFmt);
}


void CCommonControlDlg::OnBnClickedDelete()
{
  // TODO: 在此添加控件通知处理程序代码
  int nIdx = m_lisTest.GetSelectionMark();
  m_lisTest.DeleteItem(nIdx);
}

void CCommonControlDlg::OnBnClickedModiy()
{
  // TODO: 在此添加控件通知处理程序代码
  int nIdx = m_lisTest.GetSelectionMark();
  int nColIdx = 0;
  m_lisTest.SetItemText(nIdx, nColIdx++, TEXT("ceshi"));
  m_lisTest.SetItemText(nIdx, nColIdx++, TEXT("ceshi"));
  m_lisTest.SetItemText(nIdx, nColIdx++, TEXT("ceshi"));
  m_lisTest.SetItemText(nIdx, nColIdx++, TEXT("ceshi"));
  m_lisTest.SetItemText(nIdx, nColIdx++, TEXT("ceshi"));
}

void CCommonControlDlg::OnBnClickedTest()
{
  // TODO: 在此添加控件通知处理程序代码
  UpdateData();
  //AfxMessageBox(m_strName); //文本框测试
#if 0
  switch (m_nGender)
  {
  case 0:
    AfxMessageBox(TEXT("男"));
    break;
  case 1:
    AfxMessageBox(TEXT("女"));
    break;
  case 2:
    AfxMessageBox(TEXT("其他"));
    break;
  case 3:
    AfxMessageBox(TEXT("未知"));
    break;
  default:
    break;
  }
#endif // 性别测试

#if 0
  if (m_bCode)
  {
    AfxMessageBox(TEXT("写代码"));
  }
  if (m_bReverse)
  {
    AfxMessageBox(TEXT("逆向"));
  }
  if (m_bDebug)
  {
    AfxMessageBox(TEXT("调试代码"));
  }
#endif // 爱好测试

#if 0
  int nIdx = m_comFrom.GetCurSel();
  CString str, str1;
  m_comFrom.GetLBText(nIdx, str);
  DWORD dwItem = m_comFrom.GetItemData(nIdx);//获取额外的一组数据
  str1.Format(TEXT("%s %08X"), str.GetString(), dwItem);
  AfxMessageBox(str1);
#endif // Combobox测试

}



