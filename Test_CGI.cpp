// Test_CGI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, wchar_t* argv[])
{
    printf("Content-type:text/plain\n\n");  // http header : MIME type
    printf("Hello CGI World!");             // content

    //printf("%s\n\n", getenv("QUERY_STRING"));     // depriccated

    char* buf = nullptr;
    size_t sz = 0;
    if (_dupenv_s(&buf, &sz, "EnvVarName") == 0 && buf != nullptr)
    {
        printf("EnvVarName = %s\n", buf);
        free(buf);
    }

    int len;
    //char* lenstr = getenv("CONTENT_LENGTH");      // depricated

    char* lenstr = nullptr;
    _dupenv_s(&lenstr, &sz, "ContLen");
    if (lenstr != NULL && (len = atoi(lenstr)) != 0)
    {
        char* post_data = new char[len];
        fgets(post_data, len + 1, stdin);
        printf("ContLen = %d\n%s\n", len, post_data);
    }

    return 0;
}