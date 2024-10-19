#include <stdio.h>

int main(int argc, char ** argv) {
  unsigned int writeValue = 0x8;
  
  printf("Writing 0x8 to the register...\n");
  asm volatile (
    "csrw 0xC20, %0"
    :
    : "r" (writeValue)
  );
  
  unsigned int writeResult;
  asm volatile (
      "csrr %0, 0xC20"
      : "=r" (writeResult)    // Output: store the value in result
  );

  printf("0xC20 CSR after write: 0x%x\n", writeResult);
  
  writeValue = 0x0;
  printf("Writing 0x0 to the register...\n");
  asm volatile (
    "csrw 0xC20, %0"
    :
    : "r" (writeValue)
  );

  asm volatile (
      "csrr %0, 0xC20"
      : "=r" (writeResult)    // Output: store the value in result
  );

  printf("0xC20 CSR after write: 0x%x\n", writeResult);
  return 0;
}