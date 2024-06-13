#include <Windows.h> /*dependencies from windows and imgui files for dx11 and windows32 (unsure if this will break 64)*/

#include <imgui/imgui.h>
#include <imgui/imgui_impl_dx11.h>
#include <imgui/imgui_impl_win32.h>

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam); /*tells visual studio that we want to use the ImGui function that it calls*/

LRESULT CALLBACK windows_procedure(HWND window, UINT message, WPARAM w_param, LPARAM l_param) { /*receives messages being sent to the window aka the windowsprocedure*/
	if (ImGui_ImplWin32_WndProcHandler(window, message, w_param, l_param)) { /*If this returns true exits out of the function*/
		return 0L; /*0L is equal to 0. Basically means long 0 bytes or true 0*/
	}

	if (message == WM_DESTROY) { /*if window is closed out (WM_DESTROY) exits out of the function and posts quit message*/
		PostQuitMessage(0); /*This is a windows function that occurs when WM_DESTROY happens that does as the title suggests*/
		return 0L;
	}
	
	return DefWindowProc(window, message, w_param, l_param); /*DefWindowProc ensures every message is processed, if first two ifs dont occur, then it proccesses all messages*/
}

INT APIENTRY WinMain(HINSTANCE instance, HINSTANCE, PSTR, INT cmd_Show ) { /*prevInstance and PSTR parameter not needed. This is the windows entry.*/
	WNDCLASSEXW wc{}; /*Initalizing window class wc of 0*/
	wc.cbSize = sizeof(WNDCLASSEXW); /*slowly adding to wc, keeping window size to the size of the windowclass*/
	wc.style = CS_HREDRAW | CS_VREDRAW; /*Telling windows to redraw if the window is moved left or right or up and down*/
	wc.lpfnWndProc = windows_procedure; /* lpfnWndProc = function to point to windows_procedure*/
	wc.hInstance = instance; /*Letting wc identify the executable when loaded into memory through the instance*/
	wc.lpszClassName = L"External Overlay Class"; /*Long string that identifies the window class*/

	RegisterClassExW(&wc);

	const HWND window = CreateWindowExW( /*window handler to create a ExW window*/

	)



	return 0;
}

/*Video link: https://www.youtube.com/watch?v=aY8MNCNN-cY 15:45 9:16 PM 6/8/24 */