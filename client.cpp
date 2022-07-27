#include <iostream>
#include <mqueue.h>

int main() {
   mqd_t mqd = mq_open ("/OpenCSF_MQ", O_WRONLY,  0600, NULL);
  
  /* Ensure the creation was successful */
  if (mqd == -1)
    {
      perror ("mq_open");
      exit (1);
    }
  
  /* Send "HELLO" as a message with priority 10, then close the queue.
     Note the size is 6 to include the null byte '\0'. */
  mq_send (mqd, "HELLO", 6, 10);
  mq_close (mqd);
 }
