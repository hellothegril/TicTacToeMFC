#include <afxwin.h>
#include "TicTac.h"

CMyApp myApp;

BOOL CMyApp::InitInstance ()
{
    m_pMainWnd = new CMainWindow;
    m_pMainWnd->ShowWindow (m_nCmdShow);
    m_pMainWnd->UpdateWindow ();
    return TRUE;
}

BEGIN_MESSAGE_MAP (CMainWindow, CWnd)
    ON_WM_PAINT ()
    //ON_WM_LBUTTONDOWN ()
    //ON_WM_LBUTTONDBLCLK ()
    //ON_WM_RBUTTONDOWN ()
END_MESSAGE_MAP ()

CMainWindow::CMainWindow ()
{
	m_nNextChar = EX;
    ::ZeroMemory (m_nGameGrid, 9 * sizeof (int));

    //
    // Register a WNDCLASS.
    //
    CString strWndClass = AfxRegisterWndClass (
        CS_DBLCLKS,                                     // Class style
        AfxGetApp ()->LoadStandardCursor (IDC_ARROW),   // Class cursor
        (HBRUSH) (COLOR_3DFACE + 1),                    // Background brush
        AfxGetApp ()->LoadStandardIcon (IDI_WINLOGO)    // Class icon
    );

    //
    // Create a window.
    //
    CreateEx (0, strWndClass, _T ("Tic-Tac-Toe"),
        WS_OVERLAPPED | WS_SYSMENU | WS_CAPTION | WS_MINIMIZEBOX,
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
        NULL, NULL);

	//
    // Size the window.
    //
	CRect rect (0, 0, 352, 352);
    CalcWindowRect (&rect);
	SetWindowPos (NULL, 0, 0, rect.Width (), rect.Height (),
        SWP_NOZORDER | SWP_NOMOVE | SWP_NOREDRAW);


}

void CMainWindow::PostNcDestroy ()
{
    delete this;
}

void CMainWindow::OnPaint ()
{
    CPaintDC dc (this);
    DrawBoard (&dc);    
}

void CMainWindow::DrawBoard (CDC* pDC)
{
    //
    // Draw the lines that define the tic-tac-toe grid.
    //
    CPen pen (PS_SOLID, 16, RGB (0, 0, 0));
    CPen* pOldPen = pDC->SelectObject (&pen);

    pDC->MoveTo (120, 16);
    pDC->LineTo (120, 336);

    pDC->MoveTo (232, 16);
    pDC->LineTo (232, 336);

    pDC->MoveTo (16, 120);
    pDC->LineTo (336, 120);

    pDC->MoveTo (16, 232);
    pDC->LineTo (336, 232);

    //
    // Draw the Xs and Os.
    //
	/*
    for (int i=0; i<9; i++) {
        if (m_nGameGrid[i] == EX)
            DrawX (pDC, i);
        else if (m_nGameGrid[i] == OH)
            DrawO (pDC, i);
    }
	*/
    pDC->SelectObject (pOldPen);
}


