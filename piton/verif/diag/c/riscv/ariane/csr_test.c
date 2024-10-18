#include <stdio.h>

int main(int argc, char ** argv) {
  unsigned int writeValue = 0x8;
  
  printf("Beginning inline CSR assembly...\n");
  asm volatile (
    "csrw 0x300, %0"
    :
    : "r" (writeValue)
  );
  
  unsigned int writeResult;
  asm volatile (
      "csrr %0, 0x300"
      : "=r" (writeResult)    // Output: store the value in result
  );

  printf("0xC20 CSR after write: 0x%x\n", writeResult);
  return 0;
}