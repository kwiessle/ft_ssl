#include "ft_ssl.h"


int     main(int ac, char **av)
{
    if (ac > 1) {
        if (ft_strcmp(av[1], "md5") == 0) {
            hash_engine(av, &md5_execute, "MD5");
        }
        else if (ft_strcmp(av[1], "sha256") == 0) {
            hash_engine(av, &sha256_execute, "SHA256");
        }
        else if (ft_strcmp(av[1], "sha512") == 0) {
            hash_engine(av, &sha512_execute, "sha512");
        }
        else
            throw_error(ERR_CMD, "");
    }
    else {
        throw_error(ERR_NCMD, "");
        ft_putstr("Usage :\n [1] - Cmd  : <md5, sha256, sha512>\n [2] - Options : [ -p, -r, -q]\n [3] - String : -s <string> \n [4] - File : <file>\n");
    }
    return (0);
}
