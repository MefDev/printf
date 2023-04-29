#ifndef _MAIN_H
#define _MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZEBUF 1024

/**
 * struct specif_types - Struct specifiers
 *
 * @specif: The  specifier
 * @f: The function associated
 */

typedef struct specif_types
{
	char *specif;
	char *(*f)();
} specif_t;


int _printf(const char *format, ...);

/** Those are function helpers */
int _putchar(char c);
int _puts(const char *str, int size);
int _strlen(const char *str);
char *chartos(char c);
char *_memcpy(char *dest, char *src, unsigned int n, unsigned int dest_len);

/** get specifiers function */
char *(*get_specif_func(char str))(va_list);

/** specifiers functions */
char *char_specif(va_list c);
char *string_specif(va_list s);
char *percent_specif(void);
char *notexist_specif(char c);
char *integer_specif(va_list npnt);
char *binary_specif(va_list nump);


#endif /** _MAIN_H */
