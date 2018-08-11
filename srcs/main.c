#include "ft_ssl.h"


int     main(int ac, char **av)
{
    (void)ac;
    (void)av;

    t_input     *input;

    // input = input_init(get_input(STDIN));

    if (ac > 2) {
        if (ft_strcmp(av[1], "md5") == 0) {
            input = input_init(av[2]);
            md5_execute(input);
        }
    }
    return (0);
}
