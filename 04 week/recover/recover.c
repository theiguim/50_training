#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Define BYTE como um tipo de dado
typedef uint8_t BYTE;

// Define o tamanho do bloco (geralmente 512 bytes para recuperação de imagens)
#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Open memory card file
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Buffer to hold data block
    BYTE buffer[BLOCK_SIZE];

    // Variables for output JPEG file
    FILE *output_file = NULL;
    char filename[8]; // ###.jpg + '\0'
    int file_count = 0;

    // Read through memory card block by block
    while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, input_file) == BLOCK_SIZE)
    {
        // Check for JPEG signature
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // If a new JPEG is found, close the previous file (if open)
            if (output_file != NULL)
            {
                fclose(output_file);
            }

            // Create a new file for the new JPEG
            sprintf(filename, "%03i.jpg", file_count);
            output_file = fopen(filename, "w");
            if (output_file == NULL)
            {
                printf("Could not create output file.\n");
                fclose(input_file);
                return 1;
            }

            file_count++;
        }

        // If a JPEG file is open, write the block to it
        if (output_file != NULL)
        {
            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, output_file);
        }
    }

    // Close any remaining open files
    if (output_file != NULL)
    {
        fclose(output_file);
    }
    fclose(input_file);

    return 0;
}
