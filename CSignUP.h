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
public:
	afx_msg void OnBnClickedButtonRegister();

	afx_msg void OnBnClickedButtonCancle();
	CEdit m_fname;
	CEdit m_lastname;
	CEdit m_email;
	CEdit m_mobno;
	CComboBox m_ccode;
	CEdit m_username;
	CEdit m_pass;
	CEdit m_otp;
	CButton m_malel;
	CButton m_male;
	CButton m_female;
	CButton m_other;

	CString csGenerateOTP;
	virtual BOOL OnInitDialog();

	// Validation functions
	BOOL ValidateFname(const CString& fname);
	BOOL ValidateLname(const CString& lname);
	BOOL ValidateEmail(const CString& email);
	BOOL ValidateUsername(const CString& username);
	BOOL ValidatePassword(const CString& pass);
	BOOL ValidateMobno(const CString& mobno);
	BOOL IsNumeric(const CString& str);

	void WriteToLog(const char* message);
	afx_msg void OnBnClickedButtonOtp();
	afx_msg void OnBnClickedRadioOther();
	
};
