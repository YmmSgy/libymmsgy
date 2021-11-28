#include "dynstr.h"

#include <stdlib.h>
#include <errno.h>
#include <limits.h>

#define DS_CAPACITY_INIT	(1)
#define DS_CAPACITY_MAX		(UINT_MAX)

extern int ds_create(struct Dynstr *pstr) {
	pstr->capacity = DS_CAPACITY_INIT;
	pstr->length = 0;
	errno = 0;
	pstr->strarr = malloc(pstr->capacity);
	if (pstr->strarr == NULL) return errno ? errno : 1;
	return 0;
}

extern int ds_destroy(struct Dynstr *pstr) {
	free(pstr->strarr);
	return 0;
}

extern int ds_getc(struct Dynstr *pstr, unsigned int index, char *value) {
	if (index + 1 > DS_CAPACITY_MAX) return 1;

	if (index + 1 > pstr->length) return 1;

	*value = pstr->strarr[index];
	return 0;
}

extern int ds_setc(struct Dynstr *pstr, unsigned int index, char value) {
	if (index + 1 > DS_CAPACITY_MAX) return 1;

	if (index + 1 > pstr->capacity) {
		do {
			pstr->capacity = pstr->capacity > DS_CAPACITY_MAX / 2
				? DS_CAPACITY_MAX
				: pstr->capacity * 2;
		} while (index + 1 > pstr->capacity);

		errno = 0;
		char *buf = realloc(pstr->strarr, pstr->capacity);
		if (buf == NULL) return errno ? errno : 1;
		pstr->strarr = buf;
	}

	if (index + 1 > pstr->length) pstr->length = index + 1;

	pstr->strarr[index] = value;
	return 0;
}

extern int ds_fromcstr(struct Dynstr *pstr, char *cstr) {
	int ret = 0;

	ret = ds_create(pstr);
	if (ret) return ret;

	char ch;
	for (unsigned int i = 0; (ch = cstr[i]) != '\0'; ++i) {
		if (i == UINT_MAX) return 1;
		ret = ds_setc(pstr, i, ch);
		if (ret) return ret;
	}

	return 0;
}

extern int ds_tocstr(struct Dynstr *pstr, char *cstr) {
	for (unsigned int i = 0; i < pstr->length; ++i) {
		cstr[i] = pstr->strarr[i];
	}

	cstr[pstr->length] = '\0';

	return 0;
}
