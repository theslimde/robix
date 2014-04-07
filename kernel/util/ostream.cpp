#include "ostream.hpp"

namespace std
{
	ostream::ostream() noexcept :
	 	terminalRow_(0),
		terminalColumn_(0),
		terminalColor_(),
		videoMemory_(reinterpret_cast<uint16_t*>(0xB8000))
	{
	}

	ostream& ostream::operator<<(const char* string) noexcept
	{
		for(size_t i = 0; string[i] != '\0'; i++)
			appendChar(string[i]);
		
		return *this;
	}

	ostream& ostream::operator<<(const char c) noexcept
	{
		appendChar(c);

		return *this;
	}

	ostream& ostream::operator<<(const uint64_t ui64) noexcept
	{
		// The largest 64 bit number has 20 digits
		char result[20];
		uint64_t temp = ui64;
		int8_t i;
		for(i = 19; i >= 0; i--)
		{
			result[i] = 48; // ASCII 0

			uint64_t modulo = temp % 10;

			result[i] += modulo;

			temp -= modulo;

			if(temp == 0)
				break;

			temp /= 10;
		}

		int8_t j;
		for(j = 0; j < 20 - i; j++)
		{
			result[j] = result[i+j];
		}
		result[j+1] = '\0';

		return operator<<(result);
	}

	ostream& ostream::operator<<(const int32_t i32) noexcept
	{
		 return operator<<((uint64_t) i32);
	}

	ostream& ostream::operator<<(color c) noexcept
	{
		terminalColor_ = c;
		return *this;
	}

	uint8_t ostream::colorToTerminalColor(color c) const noexcept
	{
		return c.text | c.background << 4;
	}

	uint16_t ostream::textAndColorToVGA(char ch, color co) const noexcept
	{
		uint16_t ch16 = ch;
		uint16_t co16 = colorToTerminalColor(co);
		return ch16 | co16 << 8;
	}

	void ostream::printCharAt(char c, size_t row, size_t column) const noexcept
	{
		const size_t pos = row * DISPLAY_WIDTH + column;
		videoMemory_[pos] = textAndColorToVGA(c, terminalColor_);
	}
	
	void ostream::appendChar(char c) noexcept
	{
		if (c == '\n')
		{
			terminalColumn_ = 0;
			terminalRow_++;
		}
		else
		{
			printCharAt(c, terminalRow_, terminalColumn_);
			terminalColumn_++;
		}

		sanitizeTerminal();
	}

	void ostream::sanitizeTerminal() noexcept
	{
		if(terminalColumn_ >= DISPLAY_WIDTH)
		{
			terminalColumn_ = 0;
			terminalRow_++;
		}
		// if we are in the last writeable row
		if(terminalRow_ >= DISPLAY_HEIGHT - 1)
		{
			for(size_t i = 0; i < terminalRow_; i++)
			{
				for(size_t j = 0; j < DISPLAY_WIDTH; j++)
				{
					videoMemory_[i * DISPLAY_WIDTH + j] = videoMemory_[(i + 1) * DISPLAY_WIDTH + j];
				}
			}

			terminalRow_--;
		}
	}

}