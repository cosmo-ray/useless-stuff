/* BFF: Brain Fuck Functions */
/* similar to bf, exept '[' and ',' doesn't existe, and ']' jmp to last do_bff call */
/* you're limitate to 18 operations per do_bff call */
#include <stdio.h>
#include <setjmp.h>

typedef  void *(*bff_f0)(int);
typedef  bff_f0(*bff_f1)(int);
typedef  bff_f1(*bff_f2)(int);
typedef  bff_f2(*bff_f3)(int);
typedef  bff_f3(*bff_f4)(int);
typedef  bff_f4(*bff_f5)(int);
typedef  bff_f5(*bff_f6)(int);
typedef  bff_f6(*bff_f7)(int);
typedef  bff_f7(*bff_f8)(int);
typedef  bff_f8(*bff_f9)(int);
typedef  bff_f9(*bff_f10)(int);
typedef  bff_f10(*bff_f11)(int);
typedef  bff_f11(*bff_f12)(int);
typedef  bff_f12(*bff_f13)(int);
typedef  bff_f13(*bff_f14)(int);
typedef  bff_f14(*bff_f15)(int);
typedef  bff_f15(*bff_f16)(int);
typedef  bff_f16(*bff_f17)(int);
typedef  bff_f17(*bff_f)(int);

extern jmp_buf env;

#define do_bff(ins) setjmp(env);do_bff_int(ins)

static inline bff_f do_bff_int(int ins)
{
	static int vals[10];
	static int i = 0;

	switch (ins) {
	case '+':
		++vals[i];
		break;
	case '-':
		--vals[i];
		break;
	case ']':
		if (vals[i]) {
			longjmp(env, 0);
		}
		break;
	case '>':
		++i;
		break;
	case '<':
		--i;
		break;
	case '.':
		printf("%c", vals[i]);
		break;
	}
	return (void *)do_bff_int;
}
