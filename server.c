//#include "ft_printf/ft_printf.h"
#include "minitalk.h"

char *letter_to_string(char const *s1, char const letter)
{
    int j;
    int k;
    char    *dest;

    j = 0;
    k = 0;

    dest = malloc((ft_strlen(s1) + 2) * sizeof(char));
    if (!dest)
        return (NULL);
    while (s1[k])
        dest[j++] = s1[k++];
    dest[j++] = letter;
    dest[j] = '\0';
    free ((void*)(s1));
    return (dest);
} 

void    signal_handler(int signum)
{
    static int  counter;
    static int  result;
    static char  *final;

    counter = 0;
    result = 0;
    final = NULL;

    if (!final)
    {
        final = ft_strdup("");
        if (!final)
            return ;
    }
    if (signum == SIGUSR1)
        result |= (1 << (7 - counter));
    counter++;
    if (counter == 8)
    {
        final = letter_to_string(final, result);
        if (result == '\0')
        {
          //  ft_printf("%s\n", final);
            write(1, final, ft_strlen(final));
            write(1, "\n", 1);
            free (final),
            final = NULL;
        }
        result = 0;
        counter = 0;
    }
}

/*void    print_error(const char *msg)
{
    const char *error_msg;

    error_msg = strerror(errno);
    write(STDERR_FILENO, msg, ft_strlen(msg));
    write(STDERR_FILENO, ":", 2);
    write(STDERR_FILENO, error_msg, ft_strlen(error_msg));
    write(STDERR_FILENO, "\n", 1);
}

int main()
{
   struct   sigaction sa;

   sa.sa_handler = &signal_handler;
   sa.sa_flags = SA_RESTART;
   sigemptyset(&sa.sa_mask);

   if (sigaction(SIGUSR1, &sa, NULL) == -1)
   {
    print_error("Error with SIGUSR1");
    return (1);
   }

   if (sigaction(SIGUSR2, &sa, NULL) == -1)
   {
    print_error("Error with SIGUSR2");
    return (1);
   }

   ft_printf("Server PID: [%d]\n", getpid());
   while (1)
        pause();
    return (0);
}*/

int	main(void)
{
	ft_printf("Welcome To Alaakson's Server!\n");
	ft_printf("The Server PID is now: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR2, signal_handler);
		signal(SIGUSR1, signal_handler);
		pause();
	}
	return (0);
}
