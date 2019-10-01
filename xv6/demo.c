#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[])
{
    int n;
    if(argc < 2)
        n = 1;  // default value
    else
        n = atoi(argv[1]);  // from user input
    if(n<0 || n>100)
        n = 2;

    int id = 0;
    for(int k=0; k<n; k++)
    {
        double x=0;
        id = fork();
        if(id < 0)
            printf(1, "%d failed in fork!\n", getpid());
        else if(id > 0)
        {
            printf(1, "Parent %d creating child %d\n", getpid(), id);
            wait();
            printf(1,"Demo Process Ends\n");
        }
        else
        {   // Child
            printf(1, "Child %d created\n", getpid());
            for( double z=0;z<1600000.0;z+=0.001)
                x = x + 3.14*89.64; // Useless calculations to consume CPU time
            break;
        }
    }
    printf(1,"Demo Process Ended\n");
    exit();
}