#include "bff.h"

jmp_buf env;

int main()
{
	do_bff('+')('+')('+')('+')('+')('+')('+')('+')('+')('+');
	do_bff('>')('+')('+')('+')('+')('+')('+')('+')('+')('+')('+')('>')
		('+')('<')('<')
		('-')(']');
	do_bff('>')('+')('+')('+')('+')('.')('+')('.')('>')('.');
	return 0;
}