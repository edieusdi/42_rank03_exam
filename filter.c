
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void    print_stars(size_t length)
{
    while (length > 0)
    {
        write(1, "*", 1);
        length--;
    }
}

size_t  process_buffer(char *buffer, size_t used, char *pattern, size_t pattern_len)
{
    size_t  buffer_index;
    size_t  pattern_index;

    buffer_index = 0;
    while (buffer_index + pattern_len <= used)
    {
        pattern_index = 0;
        while (pattern_index < pattern_len &&
            buffer[buffer_index + pattern_index] == pattern[pattern_index])
            pattern_index++;
        if (pattern_index == pattern_len)
        {
            print_stars(pattern_len);
            buffer_index += pattern_len;
        }
        else
        {
            write(1, &buffer[buffer_index], 1);
            buffer_index++;
        }
    }
    return (buffer_index);
}

size_t  keep_leftovers(char *buffer, size_t used, size_t processed)
{
    size_t  index;

    index = 0;
    while (processed + index < used)
    {
        buffer[index] = buffer[processed + index];
        index++;
    }
    return (index);
}

int main(int argc, char **argv)
{
    char    *buffer;
    size_t  pattern_len;
    size_t  used;
    size_t  processed;
    ssize_t n;

    if (argc != 2 || argv[1][0] == '\0')
        return (1);
    pattern_len = 0;
    while (argv[1][pattern_len])
        pattern_len++;
    buffer = malloc(pattern_len + 1024);
    if (buffer == NULL)
    {
        perror("Error");
        return (1);
    }
    used = 0;
    while ((n = read(0, buffer + used, 1024)) > 0)
    {
        used += (size_t)n;
        processed = process_buffer(buffer, used, argv[1], pattern_len);
        used = keep_leftovers(buffer, used, processed);
    }
    if (n < 0)
    {
        perror("Error");
        free(buffer);
        return (1);
    }
    if (used > 0)
        write(1, buffer, used);
    free(buffer);
    return (0);
}
