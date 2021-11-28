#include <stdio.h>
#include "dynstr.h"

int test1(void) {
	struct Dynstr string;				// char string[];
	ds_create(&string);				// string = char[?];

	ds_setc(&string, 0, 'H');			// string[0] = 'H';
	ds_setc(&string, 1, 'e');			// string[1] = 'e';
	ds_setc(&string, 2, 'l');			// string[2] = 'l';
	ds_setc(&string, 3, 'l');			// string[3] = 'l';
	ds_setc(&string, 4, 'o');			// string[4] = 'o';

	char cstring[6];
	ds_tocstr(&string, cstring);
	fputs(cstring, stdout);

	printf(
	"\n"
	"length:\t\t%u\n"
	"capacity:\t%u\n",
	string.length, string.capacity);

	ds_destroy(&string);
	return 0;
}

int test2(void) {
	struct Dynstr string;
	ds_fromcstr(&string, "12345678901234567890123456789012");

	for (int i = 0; i < string.length; ++i) {
		char ch = string.strarr[i];
		putchar(ch);
	}

	printf(
	"\n"
	"length:\t\t%u\n"
	"capacity:\t%u\n",
	string.length, string.capacity);

	ds_destroy(&string);
	return 0;
}

int main(void) {
	test1();
	puts("");
	test2();
	return 0;
}
