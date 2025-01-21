#include "../inc/libft.h"

char    *str_join(char *s1, char *s2)
{
    char    *s3;
    int     i;
    int     j;

    if (!s2)
        return (s1);
    s3 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!s3)
        return (free(s1), free(s2), s1 == NULL, s2 == NULL, NULL);
    i = -1;
    while (s1[++i])
        s3[i] = s1[i];
    j = -1;
    while (s2[++j])
        s3[i + j] = s2[j];
    s3[i + j] = '\0';
    return (s3);
}