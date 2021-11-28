#ifndef DYNSTR_H
#define DYNSTR_H

struct Dynstr {
	unsigned int capacity;
	unsigned int length;
	char *strarr;
};

int ds_create(struct Dynstr *pstr);
int ds_destroy(struct Dynstr *pstr);
int ds_getc(struct Dynstr *pstr, unsigned int index, char *value);
int ds_setc(struct Dynstr *pstr, unsigned int index, char value);
int ds_fromcstr(struct Dynstr *pstr, char *cstr);
int ds_tocstr(struct Dynstr *pstr, char *cstr);

#endif // DYNSTR_H
