// CSignUP.cpp : implementation file
//

#include "pch.h"
#include "usrlgn_exe.h"
#include "afxdialogex.h"
#include "CSignUP.h"


// CSignUP dialog

IMPLEMENT_DYNAMIC(CSignUP, CDialogEx)

CSignUP::CSignUP(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SIGNUP, pParent)
{

}

CSignUP::~CSignUP()
{
}

void CSignUP::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_FIRSTNAME, m_fname);
	DDX_Control(pDX, IDC_EDIT2, m_lastname);
	DDX_Control(pDX, IDC_EDIT3, m_email);
	DDX_Control(pDX, IDC_EDIT4, m_mobno);
	DDX_Control(pDX, IDC_COMBO1, m_ccode);
	DDX_Control(pDX, IDC_EDIT5, m_username);
	DDX_Control(pDX, IDC_EDIT6, m_pass);
	DDX_Control(pDX, IDC_EDIT7, m_otp);

	DDX_Control(pDX, IDC_RADIO1, m_male);
	DDX_Control(pDX, IDC_RADIO2, m_female);
	DDX_Control(pDX, IDC_RADIO3, m_other);
}


BEGIN_MESSAGE_MAP(CSignUP, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_REGISTER, &CSignUP::OnBnClickedButtonRegister)
	ON_BN_CLICKED(IDC_BUTTON_CANCLE, &CSignUP::OnBnClickedButtonCancle)
	ON_BN_CLICKED(IDC_BUTTON_OTP, &CSignUP::OnBnClickedButtonOtp)
	ON_BN_CLICKED(IDC_RADIO_OTHER, &CSignUP::OnBnClickedRadioOther)
END_MESSAGE_MAP()


// CSignUP message handlers


BOOL CSignUP::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_fname.SetCueBanner(_T("First Name"));
	m_lastname.SetCueBanner(_T("Last Name"));
	m_email.SetCueBanner(_T("Email"));
	m_username.SetCueBanner(_T("Username"));
	m_pass.SetCueBanner(_T("Password"));
	m_mobno.SetCueBanner(_T("Mobile Number"));
	m_otp.SetCueBanner(_T("OTP"));

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CSignUP::OnBnClickedButtonRegister()
{
	CString csFname, csLname, csEmail, csGender, csUsername, csPass, csMobno;

	// Get values
	m_fname.GetWindowTextW(csFname);
	m_lastname.GetWindowTextW(csLname);
	m_email.GetWindowTextW(csEmail);
	m_username.GetWindowTextW(csUsername);
	m_pass.GetWindowTextW(csPass);
	GetDlgItemText(IDC_EDIT4, csMobno);

	// Gender
	if (m_male.GetCheck() == BST_CHECKED)
		csGender = _T("Male");
	else if (m_female.GetCheck() == BST_CHECKED)
		csGender = _T("Female");
	else
		csGender = _T("Other");

	if (!ValidateFname(csFname)) return;
	if (!ValidateLname(csLname)) return;
	if (!ValidateEmail(csEmail)) return;
	if (!ValidateUsername(csUsername)) return;
	if (!ValidatePassword(csPass)) return;
	if (!ValidateMobno(csMobno)) return;

}




void CSignUP::OnBnClickedButtonCancle()
{
	// TODO: Add your control notification handler code here
	OnCancel();
}


BOOL CSignUP::ValidateFname(const CString& fname)
{
	if (fname.IsEmpty()) {
		m_fname.SetWindowTextW(_T(""));
		m_fname.SetCueBanner(_T("First name is required"));
		AfxMessageBox(_T("First name is required."));
		return FALSE;
	}
	return TRUE;
}

BOOL CSignUP::ValidateLname(const CString& lname)
{
	if (lname.IsEmpty()) {
		m_lastname.SetWindowTextW(_T(""));
		m_lastname.SetCueBanner(_T("Last name is required"));
		AfxMessageBox(_T("Last name is required."));
		return FALSE;
	}
	return TRUE;
}

BOOL CSignUP::ValidateEmail(const CString& email)
{
	if (email.IsEmpty() || email.Find(_T("@")) == -1) {
		m_email.SetWindowTextW(_T(""));
		m_email.SetCueBanner(_T("Enter valid email"));
		AfxMessageBox(_T("Valid email is required."));
		return FALSE;
	}
	return TRUE;
}

BOOL CSignUP::ValidateUsername(const CString& username)
{
	if (username.IsEmpty()) {
		m_username.SetWindowTextW(_T(""));
		m_username.SetCueBanner(_T("Username is required"));
		AfxMessageBox(_T("Username is required."));
		return FALSE;
	}
	return TRUE;
}

BOOL CSignUP::ValidatePassword(const CString& pass)
{
	if (pass.IsEmpty() || pass.GetLength() < 6) {
		m_pass.SetWindowTextW(_T(""));
		m_pass.SetCueBanner(_T("Min 6 characters required"));
		AfxMessageBox(_T("Password must be at least 6 characters."));
		return FALSE;
	}
	return TRUE;
}

BOOL CSignUP::ValidateMobno(const CString& mobno)
{
	if (mobno.GetLength() != 10 || !IsNumeric(mobno)) {
		m_mobno.SetWindowTextW(_T(""));
		m_mobno.SetCueBanner(_T("Enter 10-digit mobile no"));
		AfxMessageBox(_T("Mobile number must be 10 digits."));
		return FALSE;
	}
	return TRUE;
}

BOOL CSignUP::IsNumeric(const CString& str)
{
	for (int i = 0; i < str.GetLength(); ++i)
	{
		if (!isdigit(str[i]))
			return FALSE;
	}
	return TRUE;
}





void CSignUP::OnBnClickedButtonOtp()
{
	// TODO: Add your control notification handler code here
	CString btnText;
	GetDlgItem(IDC_BUTTON_OTP)->GetWindowText(btnText);

	if (btnText == _T("Send OTP"))
	{
		// 1. Generate OTP
		int otp = rand() % 9000 + 1000;  // 4-digit random OTP
		csGenerateOTP.Format(_T("%d"), otp);

		// 2. Simulate sending (you can later replace this with SMS API)
		AfxMessageBox(_T("OTP Sent: ") + csGenerateOTP);

		// 3. Enable OTP input field
		GetDlgItem(IDC_EDIT7)->EnableWindow(TRUE);

		// 4. Change button text to "Verify OTP"
		GetDlgItem(IDC_BUTTON_OTP)->SetWindowText(_T("Verify OTP"));
	}
	else if (btnText == _T("Verify OTP"))
	{
		// 5. Get user input from edit box
		CString userInput;
		GetDlgItem(IDC_EDIT7)->GetWindowText(userInput);

		// 6. Compare input OTP with generated OTP
		if (userInput == csGenerateOTP)
		{
			AfxMessageBox(_T("✅ OTP Verified Successfully!"));
		}
		else
		{
			AfxMessageBox(_T("❌ Invalid OTP. Try again."));
		}

		// 7. Reset button and input field
		GetDlgItem(IDC_BUTTON_OTP)->SetWindowText(_T("Send OTP"));
		GetDlgItem(IDC_EDIT7)->SetWindowText(_T(""));
		GetDlgItem(IDC_EDIT7)->EnableWindow(FALSE);
	}
}


void CSignUP::OnBnClickedRadioOther()
{
	// TODO: Add your control notification handler code here
}
