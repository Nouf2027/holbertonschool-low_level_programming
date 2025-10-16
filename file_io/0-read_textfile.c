#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

ssize_t read_textfile(const char *filename, size_t letters)
{
int fd;
ssize_t r, w;
char *buf;

if (filename == NULL)
return (0);
fd = open(filename, O_RDONLY);
if (fd == -1)
return (0);
buf = malloc(letters);
if (buf == NULL)
{
close(fd);
return (0);
}
r = read(fd, buf, letters);
if (r <= 0)
{
free(buf);
close(fd);
return (0);
}
w = write(STDOUT_FILENO, buf, r);
if (w != r)
{
free(buf);
close(fd);
return (0);
}
free(buf);
close(fd);
return (r);
}
