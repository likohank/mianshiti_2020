#include <assert.h>
#include <stdio.h>

char* strcpy(char* strDest,const char* strSrc){
    char* strRes = strDest;
    assert( (strDest!=NULL) && (strSrc!=NULL));
    while( (*strDest++=*strSrc++)!='\0' );
    return strRes;
}


int strlen(const char* str){
    assert(str != NULL);
    int len = 0;
    while( (*str++) != '\0')
        ++len;
    return len;
}

char* strcat(char* des,const char* src){
    assert( (des!=NULL) && (src!=NULL) );

    char* address = des;
    while(*des != '\0')
        ++des;
    while(*des++ = *src++);
    return address;
}

int strcmp(const char* s1,const char* s2){
    assert( (s1!=NULL) && (s2!=NULL) );

    while(*s1 == *s2){
        if(*s1 == '\0')
            return 0;
        s1++;
        s2++;
    }
    return *s1-*s2;

}

int main()
{
    char a[50] = "Hello";
    char b[] = "world";

    printf("%s",strcat(a,b));

    return 0;
}


