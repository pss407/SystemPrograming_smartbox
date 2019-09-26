#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


#define FILE_DEVICE    "/dev/sound_sensor"  /* Char device driver file. */


int main(int argc, char *argv[])
{
    char buf[16];
    int fp;

  /* Clear buffer. */
  memset(buf, 0, 16);

  /* Open char device driver. */
  fp = open(FILE_DEVICE, O_RDONLY);
  if (fp < 0) {
    perror("pir-sensor-app: open() pir-sensor driver failed: reason ");
    exit (-1);
  }

  /* Infinite loop, the process will sleep if there is nothing to read. */
  while(1) {
    if (read(fp, buf, 16) < 0) {
      perror("pir-sensor-app: read() pir-sensor driver failed: reason ");
      exit (-1);
    }

    /* Dummy print for debug. */
     printf("Sound Detected %c\n",buf[0]);

    /* Clear buffer. */
    memset(buf, 0, 16);
  }

  return 0;
}
