#include <unistd.h>
#include <sys/poll.h>
#include <stdio.h>

int main (void)
{
  int pipe_desc[2];

  pipe (pipe_desc);

  close (pipe_desc[1]);

  write (pipe_desc[1], (const void *) "foo", 3);

  struct pollfd pfd;
  pfd.fd = pipe_desc[0];
  pfd.events = POLLIN;

  int ready = poll (&pfd, 1, 0);

  printf ("ready: %i\n", ready);
  return 0;
}
