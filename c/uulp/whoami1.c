/******************************************************
 *  whoami1.c - get the user id of the current user.  *
 *      solution for 2.10 in uulp                     *
 ******************************************************/
#include <unistd.h>
#include <pwd.h>
#include <sys/types.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    uid_t uid;
    struct passwd *pwd;
    uid = getuid();
    pwd = getpwuid(uid);
    if (pwd == NULL)
        perror("uid not found in password database");
        exit(1);
    printf("%s\n", pwd->pw_name);
    return 0;
}
