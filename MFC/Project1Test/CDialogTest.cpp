#include "CDialogTest.h"
#include "resource.h"

CDialogTest::CDialogTest(CWnd* pParent /*=nullptr*/)
  : CDialogEx(DLG_TEST, pParent)
{

}
BEGIN_MESSAGE_MAP(CDialogTest, CDialogEx)
  ON_BN_CLICKED(IDOK, &CDialogTest::OnBnClickedOk)
  ON_BN_CLICKED(IDCANCEL, &CDialogTest::OnBnClickedCancel)
  ON_BN_CLICKED(IDC_BUTTON1, &CDialogTest::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CDialogTest::OnBnClickedButton3)
  ON_BN_CLICKED(IDC_BUTTON2, &CDialogTest::OnBnClickedButton2)
END_MESSAGE_MAP()


void CDialogTest::OnBnClickedOk()
{
  // TODO: �ڴ���ӿؼ�֪ͨ����������
  CDialogEx::OnOK();
}


void CDialogTest::OnBnClickedCancel()
{
  // TODO: �ڴ���ӿؼ�֪ͨ����������
  CDialogEx::OnCancel();
}


void CDialogTest::OnBnClickedButton1()
{
  // TODO: �ڴ���ӿؼ�֪ͨ����������  
  CDialogEx::OnOK();
}


void CDialogTest::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
  AfxMessageBox(TEXT("ceshi"));
}


void CDialogTest::OnBnClickedButton2()
{
  // TODO: �ڴ���ӿؼ�֪ͨ����������  // TODO: �ڴ���ӿؼ�֪ͨ����������
  CDialogEx::OnCancel();
}
