#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <conio.h>

#define ROWS 8
#define COLS 128
#define PARTS 8
int main() {
    int a[PARTS][ROWS][COLS]; // Mảng để lưu trữ tất cả các phần tử trong trong file
    FILE *infile = fopen("white.txt", "r");

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
                a[a][i][j] = c - '0'; // Chuyển đổi ký tự sang số và lưu vào mảng 2 chiều
            }
        }
    }
    }
    fclose(infile); // Đóng file đầu vào

// In ra mảng 2 chiều để kiểm tra dữ liệu sau khi đọc từ file text
    /*
    for(int a = 0; a<PARTS ; a++){
        printf("PART: %d\n",a);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d", a[a][i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    }
    printf("\n\n");
    */
    uint8_t b[PARTS][COLS] = {0}; 
    for(int a = 0; a<PARTS ; a++){
        for (int i = 0; i < COLS; i++) {
            for (int j = ROWS - 1; j >= 0; j--) {
                b[a][i] |= (a[a][j][i] << (j));
            }
        }
        printf("\n\n");
    }

// Tiến hành mở và tạo ra một file text để ghi dữ liệu
    FILE *outfile = fopen("white_logo.txt", "w"); // Mở file để ghi dữ liệu

    if (outfile == NULL) {
        printf("Error opening file!");
        return 1;
    }

// Ghi dữ liệu của mảng b dưới dạng Hex vào file
    for (int i = 0; i < PARTS; i++) {
        fprintf(outfile, "{ ");
        for (int j = 0; j < COLS; j++) {
                fprintf(outfile, "0x%02x, ", b[i][j]);    
        }
            fprintf(outfile, "}, \n");
    }
// Đóng file
    fclose(outfile);

            getch();
            return 0;
}