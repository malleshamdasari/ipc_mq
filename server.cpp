#include <iostream>
#include <mqueue.h>
#include <cassert>


int main() {
 
/* Code Listing 3.8:
   Opening a POSIX message queue and retrieving a message
 */

/* Open the message queue for reading */
mqd_t mqd = mq_open ("/OpenCSF_MQ", O_RDONLY);
assert (mqd != -1);

/* Get the message queue attributes */
struct mq_attr attr;
assert (mq_getattr (mqd, &attr) != -1);

char *buffer = (char *) calloc (attr.mq_msgsize, 1);
assert (buffer != NULL);

printf("size: %ld\n", attr.mq_msgsize);

/* Retrieve message from the queue and get its priority level */
unsigned int priority = 0;
if ((mq_receive (mqd, buffer, attr.mq_msgsize, &priority)) == -1)
  printf ("Failed to receive message\n");
else
  printf ("Received [priority %u]: '%s'\n", priority, buffer);

/* Clean up the allocated memory and message queue */
free (buffer);
buffer = NULL;
mq_close (mqd);
}
