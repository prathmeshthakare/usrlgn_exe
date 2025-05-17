#pragma once
#include "afxdialogex.h"


// CSignUP dialog

class CSignUP : public CDialogEx
{
	DECLARE_DYNAMIC(CSignUP)

public:
	CSignUP(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CSignUP();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SIGNUP };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
