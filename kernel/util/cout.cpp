#include "cout.hpp"

namespace std
{
	cout::cout() noexcept :
	 	terminalRow_(0),
		terminalColumn_(0),
		terminalColor_(),
		videoMemory_(reinterpret_cast<uint16_t*>(0xB8000))
	{
	}

	uint8_t cout::colorToTerminalColor(color c) const noexcept
	{
		return c.text | c.background << 4;
	}

	uint16_t cout::textAndColorToVGA(char ch, color co) const noexcept
	{
		uint16_t ch16 = ch;
		uint16_t co16 = colorToTerminalColor(co);
		return ch16 | co16 << 8;
	}

	void cout::printCharAt(char c, size_t row, size_t column) const noexcept
	{
		const size_t pos = row * DISPLAY_WIDTH + column;
		videoMemory_[pos] = textAndColorToVGA(c, terminalColor_);
	}
	
}