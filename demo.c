/**
 *----------------------------------------
 * Usage demo for cBuffer.
 * Build: gcc demo.c bin/cBuffer.o -o demo
 *----------------------------------------
 */

#include "src/cBuffer.h"

int main(int argc, char **argv){

  buffer *buff = create_buffer(0);
  if (!buff){
    fprintf(stderr, "Error creating buffer!\n");
    return 1;
  }
  printf("[+] Before;\n");
  printf("[*]   Address:            0x%012x\n", buff->buffer);
  printf("[*]   Bytes allocated:    %ld\n", buff->size);
  printf("[*]   Bytes in use:       %ld\n", buff->used);
  char msgs[][20] = {"hello ", "world, this", " string is built ", "using cBuffer!"};
  printf("\n[*] Building buffer...\n");
  for (int i = 0; i < 4; i++)
    append_buffer(buff, msgs[i], strlen(msgs[i]));
  char *res = buffer_to_string(buff);
  printf("[+] Buffer: %s\n\n", res);
  printf("[+] After;\n");
  printf("[*]   Address:            0x%012x\n", buff->buffer);
  printf("[*]   Bytes allocated:    %ld\n", buff->size);
  printf("[*]   Bytes in use:       %ld\n", buff->used);
  free(res);
  free_buffer(buff);
  return 0;
}
