#include <stdio.h>

int main(int argc, char ** argv) {
  unsigned int writeValue = 0x8;
  
  printf("Beginning inline CSR assembly...\n");
  asm volatile (
    "csrrw 0xC20, %0"
    :
    : "r" (writeValue)
  );
  
  unsigned int writeResult;
  asm volatile (
      "csrr %0, 0xC20"   // Read the mstatus CSR to check the result
      : "=r" (writeResult)    // Output: store the value in result
  );

  printf("mstatus CSR after write: 0x%x\n", writeResult);
  return 0;
}