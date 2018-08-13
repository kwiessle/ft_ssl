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

/*
**  -----------------------------------------------------
**                      M   D   5
**  -----------------------------------------------------
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


/*
**  -----------------------------------------------------
**                  S  H  A  2  5  6
**  -----------------------------------------------------
*/

t_sha256            *sha256_init(t_input *input);
void                sha256_execute(t_input *input);
t_sha256            *sha256_init(t_input *input);
void                sha256_padding(t_sha256 *sha256);
uint32_t            sha256_k(int index);
void                sha256_run(t_sha256 *sha256);
void                sha256_add(t_sha256 *sha256);
void                sha256_decompose(t_sha256 *sha256, int *k);
uint32_t            sha256_p0(t_sha256 *s, int pos);
uint32_t            sha256_p1(t_sha256 *s, int pos);
void                sha256_hash(t_sha256 *sha256);
void                sha256_output(t_sha256 *sha256);
uint32_t            sha256_word(uint8_t a, uint8_t b, uint8_t c, uint8_t d);


#endif
