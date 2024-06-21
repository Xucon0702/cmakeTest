#include <cstdio>
#include <iostream>

#include "Version.h"

#define EXE_NAME "test"
#define EXE_VERSION "1.0.0"

int main(int argc,char* argv[])
{
    printf("%s\n", GetVersionDesc(EXE_NAME, EXE_VERSION));

    return 0;
}