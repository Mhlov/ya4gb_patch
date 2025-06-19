#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("ya4gb_path.exe https://github.com/Mhlov/ya4gb_patch\n");
        printf("Usage: %s <exe_file>\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "rb+");
    if (!f) {
        perror("File open");
        return 1;
    }

    // Read PE header offset from DOS header
    fseek(f, 0x3C, SEEK_SET);
    uint32_t pe_offset;
    fread(&pe_offset, sizeof(pe_offset), 1, f);

    // Go to PE header and check signature
    fseek(f, pe_offset, SEEK_SET);
    uint32_t sig;
    fread(&sig, sizeof(sig), 1, f);
    if (sig != 0x00004550) { // "PE\0\0"
        printf("Invalid PE signature.\n");
        fclose(f);
        return 1;
    }

    // Go to Characteristics field (0x16 bytes after PE header)
    fseek(f, pe_offset + 0x16, SEEK_SET);
    uint16_t characteristics;
    fread(&characteristics, sizeof(characteristics), 1, f);

    // Set LARGE_ADDRESS_AWARE flag
    characteristics |= 0x20;

    // Write it back
    fseek(f, -2, SEEK_CUR);
    fwrite(&characteristics, sizeof(characteristics), 1, f);

    fclose(f);
    printf("Patched successfully.\n");
    return 0;
}

