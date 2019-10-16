#pragma once

#if CLV_PLATFORM_LINUX
	#include <X11/keysym.h>
	#include <X11/keysymdef.h>
#endif

namespace clv{
	enum class Key{
		None			= -1,

	#if CLV_PLATFORM_WINDOWS
		//Regular keys
		Space			= VK_SPACE,
		Apostrophe		= VK_OEM_7,
		Comma			= VK_OEM_COMMA,
		Minus			= VK_OEM_MINUS,
		Period			= VK_OEM_PERIOD,
		Slash			= VK_OEM_2,
		_0				= '0',
		_1				= '1',
		_2				= '2',
		_3				= '3',
		_4				= '4',
		_5				= '5',
		_6				= '6',
		_7				= '7',
		_8				= '8',
		_9				= '9',
		Semicolon		= VK_OEM_1,
		A				= 'A',
		B				= 'B',
		C				= 'C',
		D				= 'D',
		E				= 'E',
		F				= 'F',
		G				= 'G',
		H				= 'H',
		I				= 'I',
		J				= 'J',
		K				= 'K',
		L				= 'L',
		M				= 'M',
		N				= 'N',
		O				= 'O',
		P				= 'P',
		Q				= 'Q',
		R				= 'R',
		S				= 'S',
		T				= 'T',
		U				= 'U',
		V				= 'V',
		W				= 'W',
		X				= 'X',
		Y				= 'Y',
		Z				= 'Z',
		Bracket_left	= VK_OEM_4,
		Bracket_right	= VK_OEM_6,
		Backslash		= VK_OEM_5,
		Grave_accent	= VK_OEM_3,

		//Functions keys
		Escape			= VK_ESCAPE,
		Enter			= VK_ACCEPT,
		Tab				= VK_TAB,
		Backspace		= VK_BACK,
		Insert			= VK_INSERT,
		Delete			= VK_DELETE,
		Right			= VK_RIGHT,
		Left			= VK_LEFT,
		Down			= VK_DOWN,
		Up				= VK_UP,
		Page_up			= VK_PRIOR,
		Page_down		= VK_NEXT,
		Home			= VK_HOME,
		End				= VK_END,
		Caps_lock		= VK_CAPITAL,
		Scroll_lock		= VK_SCROLL,
		Num_lock		= VK_NUMLOCK,
		Print_screen	= VK_PRINT,
		Pause			= VK_PAUSE,
		F1				= VK_F1,
		F2				= VK_F2,
		F3				= VK_F3,
		F4				= VK_F4,
		F5				= VK_F5,
		F6				= VK_F6,
		F7				= VK_F7,
		F8				= VK_F8,
		F9				= VK_F9,
		F10				= VK_F10,
		F11				= VK_F11,
		F12				= VK_F12,
		F13				= VK_F13,
		F14				= VK_F14,
		F15				= VK_F15,
		F16				= VK_F16,
		F17				= VK_F17,
		F18				= VK_F18,
		F19				= VK_F19,
		F20				= VK_F20,
		F21				= VK_F21,
		F22				= VK_F22,
		F23				= VK_F23,
		F24				= VK_F24,
		NumPad_0		= VK_NUMPAD0,
		NumPad_1		= VK_NUMPAD1,
		NumPad_2		= VK_NUMPAD2,
		NumPad_3		= VK_NUMPAD3,
		NumPad_4		= VK_NUMPAD4,
		NumPad_5		= VK_NUMPAD5,
		NumPad_6		= VK_NUMPAD6,
		NumPad_7		= VK_NUMPAD7,
		NumPad_8		= VK_NUMPAD8,
		NumPad_9		= VK_NUMPAD9,
		NumPad_Decimal	= VK_DECIMAL,
		NumPad_Divide	= VK_DIVIDE,
		NumPad_Multiply	= VK_MULTIPLY,
		NumPad_Subtract	= VK_SUBTRACT,
		NumPad_Add		= VK_ADD,
		Shift_Left		= VK_SHIFT,
		Shift_Right		= VK_SHIFT,
		Control_Left	= VK_CONTROL,
		Control_Right	= VK_CONTROL,
		Alt_Left		= VK_MENU,
		Alt_Right		= VK_MENU,
		Super_Left		= VK_LWIN,
		Super_Right		= VK_RWIN
	#elif CLV_PLATFORM_LINUX || CLV_PLATFORM_MACOS
		//Regular keys
		Space			= XK_space,
		Apostrophe		= XK_apostrophe,
		Comma			= XK_comma,
		Minus			= XK_minus,
		Period			= XK_period,
		Slash			= XK_slash,
		_0				= XK_0,
		_1				= XK_1,
		_2				= XK_2,
		_3				= XK_3,
		_4				= XK_4,
		_5				= XK_5,
		_6				= XK_6,
		_7				= XK_7,
		_8				= XK_8,
		_9				= XK_9,
		Semicolon		= XK_semicolon,
		A				= XK_a,
		B				= XK_b,
		C				= XK_c,
		D				= XK_d,
		E				= XK_e,
		F				= XK_f,
		G				= XK_g,
		H				= XK_h,
		I				= XK_i,
		J				= XK_k,
		K				= XK_k,
		L				= XK_l,
		M				= XK_m,
		N				= XK_n,
		O				= XK_o,
		P				= XK_p,
		Q				= XK_q,
		R				= XK_r,
		S				= XK_s,
		T				= XK_t,
		U				= XK_u,
		V				= XK_v,
		W				= XK_w,
		X				= XK_x,
		Y				= XK_y,
		Z				= XK_z,
		Bracket_left	= XK_bracketleft,
		Bracket_right	= XK_bracketright,
		Backslash		= XK_backslash,
		Grave_accent	= XK_grave,

		//Functions keys
		Escape			= XK_Escape,
		Enter			= XK_Return,
		Tab				= XK_Tab,
		Backspace		= XK_BackSpace,
		Insert			= XK_Insert,
		Delete			= XK_Delete,
		Right			= XK_Right,
		Left			= XK_Left,
		Down			= XK_Down,
		Up				= XK_Up,
		Page_up			= XK_Page_Up,
		Page_down		= XK_Page_Down,
		Home			= XK_Home,
		End				= XK_End,
		Caps_lock		= XK_Caps_Lock,
		Scroll_lock		= XK_Scroll_Lock,
		Num_lock		= XK_Num_Lock,
		Print_screen	= XK_Print,
		Pause			= XK_Pause,
		F1				= XK_F1,
		F2				= XK_F2,
		F3				= XK_F3,
		F4				= XK_F4,
		F5				= XK_F5,
		F6				= XK_F6,
		F7				= XK_F7,
		F8				= XK_F8,
		F9				= XK_F9,
		F10				= XK_F10,
		F11				= XK_F11,
		F12				= XK_F12,
		F13				= XK_F13,
		F14				= XK_F14,
		F15				= XK_F15,
		F16				= XK_F16,
		F17				= XK_F17,
		F18				= XK_F18,
		F19				= XK_F19,
		F20				= XK_F20,
		F21				= XK_F21,
		F22				= XK_F22,
		F23				= XK_F23,
		F24				= XK_F24,
		NumPad_0		= XK_KP_0,
		NumPad_1		= XK_KP_1,
		NumPad_2		= XK_KP_2,
		NumPad_3		= XK_KP_3,
		NumPad_4		= XK_KP_4,
		NumPad_5		= XK_KP_5,
		NumPad_6		= XK_KP_6,
		NumPad_7		= XK_KP_7,
		NumPad_8		= XK_KP_8,
		NumPad_9		= XK_KP_9,
		NumPad_Decimal	= XK_KP_Decimal,
		NumPad_Divide	= XK_KP_Divide,
		NumPad_Multiply	= XK_KP_Multiply,
		NumPad_Subtract	= XK_KP_Subtract,
		NumPad_Add		= XK_KP_Add,
		Shift_Left		= XK_Shift_L,
		Shift_Right		= XK_Shift_R,
		Control_Left	= XK_Control_L,
		Control_Right	= XK_Control_R,
		Alt_Left		= XK_Alt_L,
		Alt_Right		= XK_Alt_L,
		Super_Left		= XK_Super_L,
		Super_Right		= XK_Super_R
	#endif
	};

	inline std::ostream& operator <<(std::ostream& os, Key key){
		return os << static_cast<int32>(key);
	}
}
