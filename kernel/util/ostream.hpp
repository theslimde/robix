#include <stddef.h>
#include <stdint.h>

namespace std
{
	class ostream
	{
	public:

		const size_t DISPLAY_WIDTH = 80;
		const size_t DISPLAY_HEIGHT = 24;

		enum vga_color
		{
			COLOR_BLACK = 0,
			COLOR_BLUE = 1,
			COLOR_GREEN = 2,
			COLOR_CYAN = 3,
			COLOR_RED = 4,
			COLOR_MAGENTA = 5,
			COLOR_BROWN = 6,
			COLOR_LIGHT_GREY = 7,
			COLOR_DARK_GREY = 8,
			COLOR_LIGHT_BLUE = 9,
			COLOR_LIGHT_GREEN = 10,
			COLOR_LIGHT_CYAN = 11,
			COLOR_LIGHT_RED = 12,
			COLOR_LIGHT_MAGENTA = 13,
			COLOR_LIGHT_BROWN = 14,
			COLOR_WHITE = 15,
		};

		struct color
		{
			color() :
				text(COLOR_WHITE),
				background(COLOR_BLACK)
			{}

			vga_color text;
			vga_color background;
		};

		ostream() noexcept;

		void clear() noexcept;
		ostream& operator<<(const char* string) noexcept;
		ostream& operator<<(const char c) noexcept;
		ostream& operator<<(const uint64_t ui64) noexcept;
		ostream& operator<<(const int32_t i32) noexcept;
/*		ostream& operator<<(const size_t i) noexcept; 
		ostream& operator<<(const float f) const noexcept;
		ostream& operator<<(const double d) const noexcept;
		ostream& operator<<(const uint8_t ui8) const noexcept;
		ostream& operator<<(const uint16_t ui16) const noexcept;
		ostream& operator<<(const uint32_t ui32) const noexcept;
		
		ostream& operator<<(const int8_t i8) const noexcept;
		ostream& operator<<(const int16_t i16) const noexcept;
		ostream& operator<<(const int32_t i32) const noexcept;
		ostream& operator<<(const int64_t i64) const noexcept;*/
		ostream& operator<<(color c) noexcept;





	private:

		uint8_t		colorToTerminalColor(color c) const noexcept;
		uint16_t	textAndColorToVGA(char ch, color co) const noexcept;
		void		printCharAt(char c, size_t row, size_t column) const noexcept;
		void 		appendChar(char c) noexcept;
		void		sanitizeTerminal() noexcept;

		size_t	 	terminalRow_;
		size_t		terminalColumn_;
		color		terminalColor_;
		uint16_t* 	videoMemory_;
	};
}