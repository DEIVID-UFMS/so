
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// If you want to see the debug messages, let the line below uncommented
// #define DEBUG
#ifdef DEBUG
#define pdebug printf
#else
#define pdebug(...)
#endif


struct FCFS
{
    char p[100];
    int t;
    int t_wait;
};

void FCFS(char *file_in)
{
    printf("FCFS\n");

    /*** READ FILE ***/
    FILE *input_arq;

    input_arq = fopen(file_in, "r");
    if (input_arq == NULL)
    {
        printf("Erro ao abrir o arquivo de entrada %s.\n", file_in);
        exit(1);
    }

    int n;
    fscanf(input_arq, "%d", &n);

    struct FCFS *process = (struct FCFS *) malloc(n * sizeof(struct FCFS));
    for (int i = 0; i < n; i++)
    {
        fscanf(input_arq, "%s %d", process[i].p, &process[i].t);
        if (i == 0)
            process[i].t_wait = 0;
        else
            process[i].t_wait = process[i - 1].t + process[i - 1].t_wait;
    }

    fclose(input_arq);

    // Print the process
    printf("Processo | Tempo_de_Chegada | Tempo_de_Execucao\n");
    for (int i = 0; i < n; i++)
    {
        printf("   %s    |        %d        |         %d       \n", process[i].p, process[i].t, process[i].t_wait);
    }
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
