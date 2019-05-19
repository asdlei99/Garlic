#pragma once

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
		Shift			= VK_SHIFT,
		Control			= VK_CONTROL,
		Alt				= VK_MENU,
		Left_Super		= VK_LWIN,
		Right_Super		= VK_RWIN
	#endif
	};

	inline std::ostream& operator <<(std::ostream& os, Key key){
		return os << static_cast<int>(key);
	}
}