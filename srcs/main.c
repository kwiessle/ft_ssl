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
            return 0;
        }
        else if (ft_strcmp(av[1], "sha256") == 0) {
            input = input_init(av[2]);
            sha256_execute(input);
            return 0;
        }
        else if (ft_strcmp(av[1], "sha512") == 0) {
            input = input_init(av[2]);
            sha512_execute(input);
            return 0;
        }
        else {
            ft_putstr("Error : Unkown Command\n");
        }
    }
    ft_putstr("Usage :\n [1] - Cmd  : <md5, sha256>\n [2] - Data : <string>\n");
    return (0);
}
