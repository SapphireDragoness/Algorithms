/*
 * @LICENSE: This file has no copyright assigned and is placed in the Public Domain.
 * @AUTHOR: Riccardo Giovanni Gualiumi 2024, Linda Monfermoso 2024
 * No Software Warranty. The Software and related documentation are provided “AS IS” and without any warranty of any kind and Seller EXPRESSLY DISCLAIMS ALL WARRANTIES, EXPRESS
 * OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*/

#include "Rick45B-Utils.h"
error_rick45b RICK45B;  //needed for the client to get error info.
free_t freeFun;
malloc_t mallocFun;

char *RICK45B_GetError()
{
    return RICK45B.GetError;
}

void RICK45B_SetError(char *errorMsg)
{
    if (errorMsg!=NULL)
        RICK45B_CopyString(errorMsg, RICK45B.GetError, RICK45B_Strlen(errorMsg));
}

void RICK45B_CopyString(char const *source, char *dest, size_t length){

    if (length>0)
    {
        size_t cnt = 0;
        for (cnt = 0; cnt<length; cnt++)
            dest[cnt] = source[cnt];
        dest[length] = '\0';
    }
}

size_t RICK45B_Strlen(char const *string)
{
     if(*string==0)
      return 0;

    return RICK45B_Strlen(string+1)+1;
}

int RICK45B_Stringcmp(char const *string1, char const *string2)
{
    if (RICK45B_Strlen(string1)!=RICK45B_Strlen(string2))   return -1;  /*an error has occurred*/
    size_t i;
    for (i=0; i<RICK45B_Strlen(string1); i++)
        if (string1[i]!=string2[i]) return 1;   /*strings are different from each other*/
    return 0;   /*strings contain the same characters*/

}

void RICK45B_Memmove(void *a, void *b, size_t size) {
    unsigned char *pa = a;
    unsigned char *pb = b;

    if(a==b) /*nothing to move*/
        return;

    for(size_t i=0; i<size; ++i) { /*swaps contents byte by byte*/
        unsigned char tmp = *pa;
        *pa = *pb;
        *pb = tmp;
        ++pa;
        ++pb;
    }
}

void RICK45B_Memset(void *dest, int ch, size_t count) {
    unsigned char *pdest = dest;

    for(size_t i=0; i<count; ++i) {
        *pdest = ch;
        ++pdest;
    }
}

