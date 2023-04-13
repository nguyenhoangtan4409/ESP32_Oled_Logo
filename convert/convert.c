#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <conio.h>
#define ROWS 8
#define COLS 128
#define PARTS 8
int main() {
    int arr[PARTS][ROWS][COLS];
    FILE *infile = fopen("black.txt", "r");

    if (infile == NULL) {
        printf("Error opening file!");
        return 1;
    }

    // Đọc dữ liệu từ file vào mảng 2 chiều
    for(int a = 0; a<PARTS ; a++){
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            char c = fgetc(infile);
            if (c == '\n') {
                // Nếu gặp ký tự xuống dòng thì chuyển xuống hàng mới trong mảng 2 chiều
                j--;
            } else {
                arr[a][i][j] = c - '0'; // Chuyển đổi ký tự sang số và lưu vào mảng 2 chiều
            }
        }
    }
    }
    fclose(infile); // Đóng file đầu vào

    // In ra mảng 2 chiều
    for(int a = 0; a<PARTS ; a++){
        printf("PART: %d\n",a);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d", arr[a][i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    }
    printf("\n\n");

    uint8_t b[PARTS][COLS] = {0};
    for(int a = 0; a<PARTS ; a++){
        printf("PART: %d\n",a);
    for (int i = 0; i < COLS; i++) {
        for (int j = ROWS - 1; j >= 0; j--) {
            printf("%d", arr[a][j][i]);
            b[a][i] |= (arr[a][j][i] << (j));
        }
        printf("---%02x\n", b[a][i]);
    }
    printf("\n\n");
    }
    // In ra các giá trị trong mảng b ở dạng hex
    // for(int i = 0; i < COLS; i++){
    //     printf("%02x ", b[i]);
    // }
    // printf("\n");

    FILE *outfile = fopen("black_logo.txt", "w"); // Mở file để ghi dữ liệu

if (outfile == NULL) {
    printf("Error opening file!");
    return 1;
}

// Ghi dữ liệu của mảng b dưới dạng Hex vào file
for (int i = 0; i < PARTS; i++) {
    fprintf(outfile, "{ ");
    for (int j = 0; j < COLS; j++) {
        
        if(j == COLS-1)
            fprintf(outfile, "0x%02x", b[i][j]);
        else
            fprintf(outfile, "0x%02x, ", b[i][j]);
        
    }
    if(i == PARTS-1)
        fprintf(outfile, "} \n");
    else
        fprintf(outfile, "}, \n");
}

fclose(outfile);
    getch();
    return 0;
}