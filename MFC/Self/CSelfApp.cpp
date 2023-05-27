#include "CSelfApp.h"

#include "CSelfDialog.h"

CSelfApp g_SelApp;

BOOL CSelfApp::InitInstance()
{
  CSelfDialog dlg;
  dlg.DoModal();
  return 0;
}
