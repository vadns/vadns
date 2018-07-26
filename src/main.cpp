
#include <vadns.h>
#include <cstdio>

int main(int argc, char** argv)
{
    printf("version %d.%d.%d (%s)\ngit commit %s from branch %s\n",
        VADNS_VERSION_MAJOR, VADNS_VERSION_MINOR, VADNS_VERSION_PATCH, VADNS_VERSION_SUFFIX,
        VADNS_GIT_COMMIT_HASH, VADNS_GIT_BRANCH);

    return 0;
}
