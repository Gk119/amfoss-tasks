#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./recover image");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if( file == NULL)
    {
        printf("Cannot open file: %s", argv[1]);
        return 1;
    }

    unsigned char buffer[512];
    int size, chunks;

    fseek(file, 0L, SEEK_END);
    size = ftell(file);
    rewind(file);
    chunks = size / 512;

    printf("Size of file: %d\n", size);

    FILE * img = NULL;
    int is_open = false;
    int imgno = 1;

    for(int i = 0; i < chunks; i++)
    {
        fread(buffer, 512, 1, file);


        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && ((buffer[3] >> 4) == 0xe))
        {
            if(is_open)
            {
                fclose(img);
                is_open = false;

                char file_name[15];
                snprintf(file_name, 15, "images/%03d.jpg", imgno);
                img = fopen(file_name, "wb");
                if(img == NULL)
                {
                    printf("Error opening %s\n", file_name);
                    return 1;
                }
                imgno++;
                is_open = true;

                fwrite(buffer, 512, 1, img);

            }
            else
            {
                char file_name[15];
                snprintf(file_name, 15, "images/%03d.jpg", imgno);
                img = fopen(file_name, "wb");
                if(img == NULL)
                {
                    printf("Error opening %s\n", file_name);
                    return 1;
                }
                imgno++;
                is_open = true;

                fwrite(buffer, 512, 1, img);

            }
        }
        else
        {
            if(is_open)
            {
                fwrite(buffer, 1, 512, img);

            }
        }
    }


}