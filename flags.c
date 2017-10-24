#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define NRM  "\e[0m"
#define BLK  "\e[40m"
#define RED  "\e[41m"
#define GRN  "\e[42m"
#define YEL  "\e[43m"
#define BLU  "\e[44m"
#define MAG  "\e[45m"
#define CYN  "\e[36m"
#define WHT  "\e[47m"


char *make_htricolor_flag(int width, int hight, const char *color1,
			  const char *color2, const char *color3)
{
	char *ret = malloc((width + 1) * hight + 6 + (5 * 3));
	if (!ret)
		return NULL;
	int color_len = hight / 3;
	int cursor_pos = 0;
	for (int j = 0; j < hight; ++j) {
		if (!(j % color_len)) {
			if (!(j / color_len)) {
				strcpy(ret + cursor_pos, color1);
				cursor_pos += 5;
			} else if (j / color_len == 1) {
				strcpy(ret + cursor_pos, color2);
				cursor_pos += 5;
			} else if (j / color_len == 2) {
				strcpy(ret + cursor_pos, color3);
				cursor_pos += 5;
			}
		}
		memset(ret + cursor_pos, ' ', width);
		cursor_pos += width;
		ret[cursor_pos] = '\n';
		++cursor_pos;
	}
	strcpy(ret + cursor_pos, NRM);
	cursor_pos += 5;
	ret[cursor_pos] = '\0';
	return ret;
}

char *make_vtricolor_flag(int width, int hight, const char *color1,
			  const char *color2, const char *color3)
{
	char *ret = malloc((width + (5 * 3) + 1) * hight + 6);
	if (!ret)
		return NULL;
	int color_len = width / 3;
	int cursor_pos = 0;
	for (int j = 0; j < hight; ++j) {
		strcpy(ret + cursor_pos, color1);
		cursor_pos += 5;
		memset(ret + cursor_pos, ' ', color_len);
		cursor_pos += color_len;
		strcpy(ret + cursor_pos, color2);
		cursor_pos += 5;
		memset(ret + cursor_pos, ' ', color_len);
		cursor_pos += color_len;
		strcpy(ret + cursor_pos, color3);
		cursor_pos += 5;
		memset(ret + cursor_pos, ' ', color_len);
		cursor_pos += color_len;
		ret[cursor_pos] = '\n';
		++cursor_pos;
	}
	strcpy(ret + cursor_pos, NRM);
	cursor_pos += 5;
	ret[cursor_pos] = '\0';
	return ret;
}

char *make_nordic_flag(int width, int hight, const char *color1,
		       const char *color2, const char *color3)
{
	char *ret = malloc((width + (5 * 5) + 1) * hight + 6);
	if (!ret)
		return NULL;
	int w_color_len = width / 22;
	int h_color_len = hight / 16;
	int cursor_pos = 0;
	for (int j = 0; j < hight; ++j) {
		int j2 = j * 16 / hight;
		if (j2 < 6 || j2 > 9) {
			strcpy(ret + cursor_pos, color1);
			cursor_pos += 5;
			memset(ret + cursor_pos, ' ', w_color_len * 6);
			cursor_pos += w_color_len * 6;

			strcpy(ret + cursor_pos, color2);
			cursor_pos += 5;
			memset(ret + cursor_pos, ' ', w_color_len * 1);
			cursor_pos += w_color_len * 1;

			strcpy(ret + cursor_pos, color3);
			cursor_pos += 5;
			memset(ret + cursor_pos, ' ', w_color_len * 2);
			cursor_pos += w_color_len * 2;

			strcpy(ret + cursor_pos, color2);
			cursor_pos += 5;
			memset(ret + cursor_pos, ' ', w_color_len * 1);
			cursor_pos += w_color_len * 1;

			strcpy(ret + cursor_pos, color1);
			cursor_pos += 5;
			memset(ret + cursor_pos, ' ', w_color_len * 12);
			cursor_pos += w_color_len * 12;
		} else if (j2 < 7 || j2 > 8) {
			strcpy(ret + cursor_pos, color2);
			cursor_pos += 5;
			memset(ret + cursor_pos, ' ', w_color_len * 7);
			cursor_pos += w_color_len * 7;

			strcpy(ret + cursor_pos, color3);
			cursor_pos += 5;
			memset(ret + cursor_pos, ' ', w_color_len * 2);
			cursor_pos += w_color_len * 2;

			strcpy(ret + cursor_pos, color2);
			cursor_pos += 5;
			memset(ret + cursor_pos, ' ', w_color_len * 13);
			cursor_pos += w_color_len * 13;
		} else {
			strcpy(ret + cursor_pos, color3);
			cursor_pos += 5;
			memset(ret + cursor_pos, ' ', w_color_len * 22);
			cursor_pos += w_color_len * 22;
		}

		ret[cursor_pos] = '\n';
		++cursor_pos;
	}
	strcpy(ret + cursor_pos, NRM);
	cursor_pos += 5;
	ret[cursor_pos] = '\0';
	return ret;
}

int main(int ac, char **av)
{
	char *fra = make_vtricolor_flag(80, 25, BLU, WHT, RED);
	char *ita = make_vtricolor_flag(80, 25, GRN, WHT, RED);
	char *rci = make_vtricolor_flag(80, 25, YEL, WHT, GRN);
	char *ger = make_htricolor_flag(80, 25, BLK, RED, YEL);
	char *ndl = make_htricolor_flag(80, 25, RED, WHT, BLU);
	char *nor = make_nordic_flag(80, 20, RED, WHT, BLU);
	char *swe = make_nordic_flag(80, 20, BLU, YEL, YEL);
	char *fin = make_nordic_flag(80, 20, WHT, BLU, BLU);

	if (ac == 2) {
		if (!strcmp(av[1], "ita")) {
			printf("%s", ita);
		} else if (!strcmp(av[1], "fra")) {
			printf("%s", fra);
		} else if (!strcmp(av[1], "rci")) {
			printf("%s", rci);
		} else if (!strcmp(av[1], "ndl")) {
			printf("%s", ndl);
		} else if (!strcmp(av[1], "fin") ||
			   !strcmp(av[1], "myth") ||
			   !strcmp(av[1], "lie")) {
			printf("%s", fin);
		} else if (!strcmp(av[1], "nor")) {
			printf("%s", nor);
		} else if (!strcmp(av[1], "swe")) {
			printf("%s", swe);
		} else if (!strcmp(av[1], "ger")) {
			printf("%s", ger);
		} else {
			goto usage;
		}
	} else {
		goto usage;
	}
	goto exit;

usage:
	printf("usage: %s fra | ita | rci | ndl | ger | nor | swe | lie \n",
	       av[0]);
exit:
	free(fra);
	free(ita);
	free(ndl);
	free(rci);
	free(swe);
	free(ger);
	free(nor);
	free(fin);
	return 0;
}
