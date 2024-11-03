#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *filein;
	FILE *fileout;
	filein = fopen("bitstream1.bit", "r");
	fileout = fopen("bitstream1.hex", "w");

	if (filein == NULL || fileout == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

	char bit;
	int bitCount = 0;
	unsigned char byte = 0;

 	while (fscanf(filein, " %c", &bit) != EOF) {
        byte = (byte >> 1) | ((bit - '0') << 7);
        bitCount++;

        if (bitCount == 8) {
            fprintf(fileout, "%02X\n", byte);
            bitCount = 0;
            byte = 0;
        }
    	}

	if (bitCount > 0) {
        byte >>= (8 - bitCount);
        fprintf(fileout, "%02X\n", byte);
    	}

 	fclose(filein);
 	fclose(fileout);

	printf("Conversion completed. Output saved to bitstream.hex\n");
	return 0;
}
