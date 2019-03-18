/* 题目：给定二维数组，每列从上到下递增，每行从左到右递增，确认某个数是否在数组中；
 * 解法：这题的关键在于每次要批量地缩小范围，如果从右下角或者左上角开始，则需要遍历MXN;
 *       如果从左下角或者右上角开始，则每次可以整列或者整行地排除。
 */
#include <stdio.h>
#include <stdbool.h>

#define ROW_NUM 4
#define COL_NUM 4

void printArray(int arr[ROW_NUM][COL_NUM]) {
    for(int i = 0; i < ROW_NUM; i++) {
        for(int j = 0; j < COL_NUM; j++) {
            printf("%5d", arr[i][j]);
        }
        printf("\n");
    }

}
bool findInArray(int arr[ROW_NUM][COL_NUM], int target, int* row, int* col) {
    int x = 0, y = ROW_NUM - 1;
    while(x < ROW_NUM && y >= 0) {
        if(arr[x][y] < target) {
            x++;
            continue;
        } else if(arr[x][y] > target) {
            y--;
            continue;
        } else {
            *row = x;
            *col = y;
            return true;
        }
    }
    return false;
}

int main(int argc, char* argv[]) {
    int arr[ROW_NUM][COL_NUM] = {
        {1, 2, 8, 9},
        {2, 4, 9, 12},
        {4, 7, 10, 13},
        {6, 8, 11, 15}
    };
    printArray(arr);
    int target;
    scanf("%d", &target);
    printf("target is %d\n", target);

    int row, col;
    if(findInArray(arr, target, &row, &col)) {
        printf("target was found at (%d, %d)\n", row, col);
    } else {
        printf("target not found\n");
    }
    return 0;
}
