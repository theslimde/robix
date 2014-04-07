#include "util/ostream.hpp"

int main()
{
	std::ostream cout;

	std::ostream::color c;
	c.text = std::ostream::vga_color::COLOR_GREEN;
	c.background = std::ostream::vga_color::COLOR_BLUE;
	cout << c;
	for(uint64_t i = 0; i < 10000; i++)
		cout << i << '\n';


	while(1);
	return 0;
}
