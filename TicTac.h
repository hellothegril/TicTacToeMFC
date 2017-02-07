#define EX 1
#define OH 2

class CMyApp : public CWinApp
{
public:
	virtual BOOL InitInstance();
};

class CMainWindow : public CWnd
{
protected:
	void DrawBoard (CDC* pDC);
	int m_nGameGrid[9];                 // Grid contents
	int m_nNextChar;                    // Next character (EX or OH)
	void DrawX (CDC* pDC, int nPos);
    void DrawO (CDC* pDC, int nPos);


public:
    CMainWindow ();

protected:
	virtual void PostNcDestroy ();

	afx_msg void OnPaint ();
	DECLARE_MESSAGE_MAP ()
};