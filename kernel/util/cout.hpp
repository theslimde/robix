#include <stddef.h>
#include <stdint.h>

namespace std
{
	class cout
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

		cout() noexcept;

		void clear() noexcept;


	private:

		uint8_t		colorToTerminalColor(color c) const noexcept;
		uint16_t	textAndColorToVGA(char ch, color co) const noexcept;
		void		printCharAt(char c, size_t row, size_t column) const noexcept;

		size_t	 	terminalRow_;
		size_t		terminalColumn_;
		color		terminalColor_;
		uint16_t* 	videoMemory_;
	};
}