#include <Windows.h>
#include "resource.h"

LRESULT CALLBACK fVentana1(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, PSTR cmdLine, int cShow) {
	HWND hVentana1 = CreateDialog(hInst, MAKEINTRESOURCE(IDD_DIALOG1), NULL, fVentana1);
	/*Agregamos los elementos del combobox*/
	HWND hComboName = GetDlgItem(hVentana1, IDC_COMBO1);
	SendMessage(hComboName, CB_ADDSTRING, NULL, (LPARAM)"1");
	SendMessage(hComboName, CB_ADDSTRING, NULL, (LPARAM)"2");
	SendMessage(hComboName, CB_ADDSTRING, NULL, (LPARAM)"3");
	SendMessage(hComboName, CB_ADDSTRING, NULL, (LPARAM)"4");
	SendMessage(hComboName, CB_ADDSTRING, NULL, (LPARAM)"5");
	SendMessage(hComboName, CB_ADDSTRING, NULL, (LPARAM)"6");
	SendMessage(hComboName, CB_ADDSTRING, NULL, (LPARAM)"7");
	SendMessage(hComboName, CB_ADDSTRING, NULL, (LPARAM)"8");
	SendMessage(hComboName, CB_ADDSTRING, NULL, (LPARAM)"9");
	SendMessage(hComboName, CB_ADDSTRING, NULL, (LPARAM)"10");

	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));
	ShowWindow(hVentana1, cShow);
	while (GetMessage(&msg, NULL, NULL, NULL)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}

LRESULT CALLBACK fVentana1(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {

	case WM_COMMAND: {
		
		if (LOWORD(wParam) == IDC_BUTTON1 && HIWORD(wParam) == BN_CLICKED) {
			HWND hComboName = GetDlgItem(hwnd, IDC_COMBO1);
			int iComboLength = GetWindowTextLength(hComboName);
			char comboText[100];
			GetWindowText(hComboName, comboText, ++iComboLength);
			//MessageBox(NULL, comboText, "Dato del combo box", MB_OK);

		}
	}break;

	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(117);
		break;
	}
	return FALSE;
}