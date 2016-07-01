#include <stdio.h>
#include <stdlib.h>

#define operation(op) do {			\
		base op##=atoi(av[i+1]);	\
		i += 2;				\
		goto *a [ av[i][0] ];		\
	} while (0)

int main(int ac, char **av)
{
	int base = atoi(av[1]);
	int i = 2;
	void *a[] = {
		['+'] = &&add,
		['-'] = &&sub,
		['*'] = &&mult,
		['/'] = &&div,
		['e'] = &&end
	};

	goto *a [ av[i][0] ];
add:
	operation(+);
sub:
	operation(-);
mult:
	operation(*);
div:
	operation(/);
end:
	return base;
}
