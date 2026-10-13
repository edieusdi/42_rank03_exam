#include "get_next_line.h"

char *ft_strchr(char *s, int c)
{
  int i = 0;
  while(s[i] && s[i] != c)
    i++;
  if (s[i] == c)
    return (s + i);
  else
    return (NULL);
}

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    size_t index = 0;
  while(index < n)
  {
    ((char *)dest)[index] = ((char *)src)[index];
    index++;
  }
  return (dest);
}

size_t ft_strlen(char *s)
{
  size_t len = 0;
  if (!s)
    return (0);
  while (s[len])
    len++;
  return len;
}

int str_append_mem(char **s1, char *s2, size_t size2)
{
  size_t size1 = ft_strlen(*s1);
  char *tmp = malloc(size2 + size1 + 1);
  if (!tmp)
    return 0;
  ft_memcpy(tmp, *s1, size1);
  ft_memcpy(tmp + size1, s2, size2);
  tmp[size1 + size2] = '\0';
  free(*s1);
  *s1 = tmp;
  return 1; 
}

int str_append_str(char **s1, char *s2)
{
  return str_append_mem(s1, s2, ft_strlen(s2));
}

void *ft_memmove(void *dest, const void *src, size_t n)
{
    size_t index;

    if (dest == src)
        return(dest);
    if (dest < src)
    {
        index = 0;
        while(index < n)
        {
            ((char *)dest)[index] = ((const char*)src)[index];
            index++;
        }
    }
    if (dest > src)
    {
        index = n;
        while (0 < index)
        {
            index--;
            ((char *)dest)[index] = ((const char*)src)[index];
        }
    }
    return(dest);
}

char *get_next_line(int fd)
{
    static char b[BUFFER_SIZE + 1] = "";
    char *ret = NULL;
    char *tmp = ft_strchr(b, '\n');

    if (fd < 0 || BUFFER_SIZE <= 0 )
        return (NULL);

    while(!tmp)
    {
        if (!str_append_str(&ret, b))
        {
            b[0] = '\0';
            free(ret);
            return (NULL);
        }

        int read_ret = read(fd, b, BUFFER_SIZE);
        if (read_ret == -1)
        {
            b[0] = '\0';
            free(ret);
            return(NULL);
        }
        else if (read_ret == 0)
        {
            b[0] = '\0';
            if (ret && ret[0] != '\0')
                return(ret);
            free(ret);
            return(NULL);
        }
        b[read_ret] = '\0';
        tmp = ft_strchr(b,'\n');
    }

    char c = tmp[1];
    tmp[1] = '\0';
    if (!str_append_str(&ret,b))
    {
        tmp[1] = c;
        free(ret);
        return (NULL);
    }
    tmp[1] = c;
    ft_memmove(b, tmp +1, ft_strlen(tmp + 1)+1);
    return ret;
}
