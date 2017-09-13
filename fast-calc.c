#include <stdio.h>
#include <stdlib.h>

#define operation(op) do {			\
		base op##=atoi(av[i+1]);	\
		i += 2;				\
		goto *a [ av[i][0] ];		\
	} while (0)

int exec(int ac, char **av)
{
	int base = atoi(av[1]);
	int i = 2;
	void *a[256];

	for (int j = 0; j < 256; ++j)
		a[j] = &&invalid_arg;

	a['+'] = &&add;
	a['-'] = &&sub;
	a['*'] = &&mult;
	a['/'] = &&div;
	a['e'] = &&end;

	goto *a [ av[i][0] ];
add:
	operation(+);
sub:
	operation(-);
mult:
	operation(*);
div:
	operation(/);
invalid_arg:
	dprintf(2, "invalide argument: %s\n", av[i]);
	return -1;
end:
	return base;
}

int main(int ac, char **av)
{
	if (ac == 1) {
		dprintf(2, "empty arg\n");
		return -1;
	}
	return exec(ac, av);
}
