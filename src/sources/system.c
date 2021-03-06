#include <clib/system.h>

void* memcpy(void* dest, const void* src, int count)
{
    const char *sp = (const char *)src;
    char *dp = (char *)dest;
    for(;count > 0; count--)
        *dp++ = *sp++;
    return dest;
}

void* memset(void* dest, char val, int count)
{
    char* v = (char*) dest;
    for(;count>0; count--)
       *v++ = val;
    return dest;
}

unsigned short* memsetw(unsigned short* dest, unsigned short val, int count)
{
    int i;
    for(i=0; i < count; i++)
        dest[i] = val;
    return dest;
}

int strlen(const char* str)
{
    int i=0;
    while(*(str++) != '\0')
        i++;
    return i;
}

void strcpy(char* dest, const char* source)
{
    while(*source != '\0')
        *dest++ = *source++;
    *dest = '\0';
}

int strcmp(const char* a, const char* b)
{
    while(*a == *b && *a != '\0' && *b != '\0')
    {
        a++;
        b++;
    }
    return (*a)-(*b);
}

void strcat(char* dest, const char* source)
{
    while(*dest++ != '\0');

    while(*source != '\0')
        *dest++ = *source++;

    *dest = '\0';
}

void strrev(char* str)
{
    int i;
    int len = strlen(str);
    char tmp;
    for(i=0; i < len/2; i++)
    {
        tmp = str[i];
        str[i] = str[(len-1)-i];
        str[(len-1)-i] = tmp;
    }
}

int isdigit(char c)
{
    if(c >= '0' && c <= '9')
        return 1;
    return 0;
}

int atoi(char* str, int* len)
{
    int i=0, ret=0, mul=1;
    if(str[i]=='-')
    {   
        mul=-mul;
        i++;
    }
    
    while(isdigit(str[i]))
    {
        ret*=10;
        ret+=str[i]-'0';
        i++;
    }
    *len=i;
    return ret*mul;
}

int itoa(int number, int base, char* dest)
{
    static char* digits = "0123456789ABCDEF";
    int i=0, negative=0;
    if(number < 0)
    {
        number = -number;
        negative = 1;
    }
    do
    {
        dest[i++] = digits[number%base];
    }while((number /= base) >0);

    if(negative)
        dest[i++] = '-';

    dest[i++] = '\0';

    strrev(dest);
    return i-1;
}

int utoa(unsigned int number, int base, char* dest)
{
    static char* digits = "0123456789ABCDEF";
    int i=0;
    do
    {
        dest[i++] = digits[number%base];
    }while((number /= base) >0);

    dest[i++] = '\0';

    strrev(dest);
    return i-1;
}

int ends_with(const char* src, const char* s)
{
    int len=strlen(src)-strlen(s);
    return (strcmp(&src[len], s)==0) ? 1 : 0;
}

unsigned char inportb (unsigned short _port)
{
    unsigned char rv;
    asm volatile ("inb %1, %0" : "=a" (rv) : "dN" (_port));
    return rv;
}

void outportb (unsigned short _port, unsigned char _data)
{
    asm volatile ("outb %1, %0" : : "dN" (_port), "a" (_data));
}
