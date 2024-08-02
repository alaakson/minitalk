#include "minitalk.h"

void    client_signal(int pid, char *message)
{
    size_t letter;
    int i;

    letter = 0;
    while (message[letter])
    {
        i = 0;
        while (i < 8)
        {
            if ((message[letter] >> (7 - i)) & 1)
                kill(pid, SIGUSR2);
            else
                kill(pid, SIGUSR1);
            i++;
            usleep(300);
        }
    letter++;
    }
}

int main(int argc, char**argv)
{
    char    *message;
    int     server_id;
    
    if (argc == 3)
    {
        server_id = ft_atoi(argv[1]);
        message = argv[2];
        if (message[0] == 0)
        {
            ft_printf ("Empty message not allowed\n");
            return (1);
        }
        client_signal(server_id, message);
    }
    else
    {
        ft_printf("Enter arguments: ./client <PID> <MESSAGE> \n");
        return (1);
    }
    return (0);
}
