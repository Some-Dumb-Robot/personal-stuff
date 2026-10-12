#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    //grab command line arguments. Was usefull for debugging, but now is best just commented out::
    // printf("argc: %d\n", argc);
    // printf("argv0: %s\n", argv[0]);
    // printf("argv1: %s\n", argv[1]);


    // Step 1
    // Pass in your student id via command line argument.
    // Set environment variable USER_ID to your student ID.
    // Print USER_ID

    int setenv_results = setenv("USER_ID", argv[1], 1);
    char *env_results = getenv("USER_ID");
    printf("USER_ID: %s\n", env_results);

    // Step 2
    // Set environment variable ASSIGNMENT3 to "Environment Variables and Process IDs"
    // Print ASSIGNMENT3

    int setenv_results2 = setenv("ASSIGNMENT3", "Environment Variables and Process IDs", 1);
    char *env_results2 = getenv("ASSIGNMENT3");
    printf("ASSIGNMENT3: %s\n", env_results2);

    // Step 3
    // Write code to get your process's ID (PID)
    // Example code to convert int to char[]
    // char pid_str[8] = {0};
    // sprintf(pid_str, "%d", <variable used for getpid>);

    // get process id
    char buff[10] = {0};
    int pid = getpid();
    sprintf(buff, "%d", pid);
    //printf("my process id is: %s\n", buff);


    // Step 4
    // Set environment variable MY_PID to the PID found above
    // Print the PID

    int setenv_results3 = setenv("MY_PID", buff, 1);
    char *env_results3 = getenv("MY_PID");
    printf("MY_PID: %s\n", env_results3);


    // Step 5
    // An environment variable named "COURSE_NAME" is available
    // Print the value
    // Change it to the correct course name (EE3233 Systems Programming)
    // Print it again

    //original value print
    char *env_results4 = getenv("COURSE_NAME");
    printf("COURSE_NAME: %s\n", env_results4);

    //change value and printt
    int setenv_results5 = setenv("COURSE_NAME", "EE3233 Systems Programming", 1);
    char *env_results5 = getenv("COURSE_NAME");
    printf("COURSE_NAME: %s\n", env_results5);
    printf("MY_PID: %s\n", env_results3);



    //I had to changed line 6 of run_assignment_update.sh to ./assignment3.out abc123. 
    return 0;
}