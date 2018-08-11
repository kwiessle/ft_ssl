#ifndef FT_SSL
# define FT_SSL

# define STDIN 0

# include "libft.h"
# include <stdio.h>
# include "struct.h"
# include "define.h"


t_input         *input_init(char *message);
char            *get_input(int fd);
size_t          get_padding_size(size_t len);
int             little_endian(uint32_t h);
void            print_hex(unsigned int n);


/*
 *  M   D   5
*/

t_md5               *md5_init(t_input *input);
void                md5_run(t_md5 *md5);
void                md5_execute(t_input *input);
void                md5_padding(t_md5 *md5);
void                md5_hash(t_md5 *md5);
void                md5_process_1(t_md5 *md5, int pos);
void                md5_process_2(t_md5 *md5, int pos);
void                md5_process_3(t_md5 *md5, int pos);
void                md5_process_4(t_md5 *md5, int pos);
void                md5_output(t_md5 *md5);
uint32_t            md5_r(int index);
uint32_t            md5_k(int index);


#endif
