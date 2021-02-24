#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    typedef uint8_t BYTE;

    // Open file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) // check proper usage
    {
        return 1;
    }

    FILE *jpg = NULL;  // create pointer file
    int jpgcounter = 0; // count when jpg is found
    int counter = 1; // count when new jpg is complete
    BYTE buffer[512]; // create buffer with 512 bytes of memory allocated
    char filename[50]; // allocate 50 bytes for new jpg files

    while (fread(buffer, 512, 1, file) == 1) // loop over memory
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) // check if file is jpg
        {
            if (jpg != NULL) // if so, check if file is already opened
            {
                fclose(jpg); // if so, close
                counter++; // if so, increment counter variable to show new jpg has finished
            }
            sprintf(filename, "%03i.jpg", jpgcounter); // create new file
            jpg = fopen(filename, "w"); // assign pointer to new file
            fwrite(&buffer, 512, 1, jpg); // write the buffer onto newly created jpg file
            jpgcounter++; // increment jpg counter to show jpg was found
        }
        else if (jpgcounter == counter) // ask if a jpg has already been found
        {
            fwrite(&buffer, 512, 1, jpg); // if so write
        }
    }
    // Close file
    fclose(file);
}
