#include "shell.h"

/**
 * _getline - read a line from stdin
 * @line: pointer to a pointer to a string
 *
 * Return: number of characters, or -1 on the error or end of the input.
 */
ssize_t _getline(char **line)
{
        ssize_t nread = 0;
        size_t bytes_allocate = 0, total_bytes = 0;
        char *buff = NULL;

        if (line == NULL)
                return (-1);

        buff = malloc(sizeof(char) * READ_SIZE);
        if (buff == NULL)
                return (-1);

        while (1)
        {
                
                if (total_bytes >= bytes_allocate - 1)
                {
                        bytes_allocate += READ_SIZE;
                        char *new_buff = realloc(buff, bytes_allocate);
                        if (new_buff == NULL)
                        {
                                free(buff);
                                return (-1);
                        }
                        buff = new_buff;
                }

                
                nread = read(STDIN_FILENO, buff + total_bytes, READ_SIZE);
                if (nread < 0)
                {
                        free(buff);
                        return (-1);
                }
                else if (nread == 0)
                {
                        
                        if (total_bytes == 0)
                        {
                                free(buff);
                                return (-1);
                        }
                        break;
                }

                /* Update the total number of bytes */
                total_bytes =total_bytes + nread;

                
                if (memchr(buff + total_bytes - nread, '\n', nread) != NULL)
                        break;
        }

        while (total_bytes > 0 && (buffer[total_bytes - 1] == '\n' || buffer[total_bytes - 1] == '\r'))
                total_bytes--;

        
        char *new_line = realloc(buff, total_bytes + 1);
        if (new_line == NULL)
        {
                free(buff);
                return (-1);
        }
        new_line[total_bytes] = '\0';

        *line = new_line;

        return (total_bytes);
}
