#ifndef FT_SSL
# define FT_SSL



# include "libft.h"
# include <stdio.h>
# include "struct.h"
# include "define.h"


t_input         *input_init(char *message);
char            *get_input(int fd);
size_t          get_padding_size(size_t len, int modulo, size_t congruent);
int             little_endian(uint32_t h);
void            throw_error(char *err, char *desc);

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



/*
**  -----------------------------------------------------
**                  S  H  A  5  1  2
**  -----------------------------------------------------
*/

t_sha512            *sha512_init(t_input *input);
void                sha512_execute(t_input *input);
t_sha512            *sha512_init(t_input *input);
void                sha512_padding(t_sha512 *sha512);
uint64_t            sha512_k(int index);
uint64_t            sha512_k40(int index);
uint64_t            sha512_k80(int index);
void                sha512_run(t_sha512 *sha512);
void                sha512_add(t_sha512 *sha512);
void                sha512_decompose(t_sha512 *sha512, int *k);
uint64_t            sha512_p0(t_sha512 *s, int pos);
uint64_t            sha512_p1(t_sha512 *s, int pos);
void                sha512_hash(t_sha512 *sha512);
void                sha512_output(t_sha512 *sha512);
uint64_t            sha512_word(t_sha512 *sha512, int cursor);


void                base64_engine(char **args);
void                base64_encode(t_base64 *b64);
void                base64_decode(t_base64 *b64);
t_base64            *init_base64(char **args);
void                base64_print_encoded(t_base64 *b64, e_state last);
void                base64_print_decoded(t_base64 *b64);


void                hash_engine(char **args, void (*p)(t_input *), char *name);
void                interpret_command(t_hash *env, char *entry, char *arg);
t_hash              *hash_init(char **entries, char *name, void (*cmd)(t_input *));


#endif
