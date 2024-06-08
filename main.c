
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// If you want to see the debug messages, let the line below uncommented
#define DEBUG
#ifdef DEBUG
#define pdebug printf
#else
#define pdebug(...)
#endif


void FCFS(char *file_in)
{
    pdebug("FCFS\n");
}

void SJF(char *file_in)
{
    pdebug("SJF\n");
}

void Priority(char *file_in)
{
    pdebug("Priority\n");
}

void RoundRobin(char *file_in)
{
    pdebug("RoundRobin\n");
}

int main(int argc, char *argv[])
{
    // Handling the arguments
    char alg[100], file_in[100];

    if (argc != 3)
        perror("Erro: Argumentos insuficientes.\n \
                Use: ./main <algorithm> <file_in>\n\n \
                <algorithm> (Only Number):\n \
                \t1 - FCFS – First-Como, first-Served;\n \
                \t2 - SJF – Shortest Job First;\n \
                \t3 - Priority;\n \
                \t4 - Round Robin;\n \
        ");


    strcpy(alg, argv[1]);
    strcpy(file_in, argv[2]);

    pdebug("alg: %s\n", alg);
    pdebug("file_in: %s\n", file_in);

    // Handle algorithm choosed
    switch (atoi(alg))
    {
        case 1:
            // FCFS – First-Como, first-Served;
            FCFS(file_in);
            break;

        case 2:
            // SJF – Shortest Job First;
            SJF(file_in);
            break;

        case 3:
            // Priority;
            Priority(file_in);
            break;

        case 4:
            // Round Robin;
            RoundRobin(file_in);
            break;

        default:
            break;
    }
}
