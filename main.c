#include <stdio.h>
#include <string.h>
#include <Windows.h>

// #define ACCESS_FAIL     1
// #define INVALID_FORMAT  2
// #define INVALID_COMMAND 3

/*
 * Tóm tắt chương trình:
 *  - Xử lí dữ liệu file .csv từ task 1
 * + Đầu tiên viết chương trình xử lí command: ./lux_process [data_filename.csv] [location.csv]
*/

int checkInputCommand(int argc, char *argv[], SYSTEMTIME time);
int checkFileName(char *fileName);
// int logError();

int main(int argc, char *argv[])
{
    SYSTEMTIME time;
    GetLocalTime(&time);

    checkInputCommand(argc, &argv[0], time);
    
    
    return 0;
}

int checkInputCommand(int argc, char *argv[], SYSTEMTIME time)
{
    FILE *fptrLog = fopen("task2.log", "a");
    FILE *fptrData = fopen(argv[1], "r");
    FILE *fptrLocation = fopen(argv[2], "w");
    //Error 1
    if(fptrData == NULL && fptrLocation ==NULL)
    {
        fprintf(fptrLog, "%04d:%02d:%02d %02d:%02d:%02d, Error 01: input file not found or not accessible\n",
        time.wYear, time.wMonth, time.wDay, time.wHour, time.wMinute, time.wSecond);
    }

    //Error 2

    if(checkFileName(argv[1]) && checkFileName(argv[2]))
    {   
        fprintf(fptrLog, "%04d:%02d:%02d %02d:%02d:%02d, Error 02: invalid input file format\n",
        time.wYear, time.wMonth, time.wDay, time.wHour, time.wMinute, time.wSecond);
    }
    // if()
    // {
    //     fprintf(fptrLog, "%04d:%02d:%02d %02d:%02d:%02d, Error 01: input file not found or not accessible\n",
    //     time.wYear, time.wMonth, time.wDay, time.wHour, time.wMinute, time.wSecond);
    // }

    //Error 3 
    if(argc < 3)
    {
        fprintf(fptrLog, "%04d:%02d:%02d %02d:%02d:%02d, Error 03: invalid command\n",
        time.wYear, time.wMonth, time.wDay, time.wHour, time.wMinute, time.wSecond);
    }

    //Close files when done
    fclose(fptrLog);
    fclose(fptrData);
    fclose(fptrLocation);
}

int checkFileName(char *fileName)
{
    char *name = strrchr(fileName, '.');
    if(strcmp(name, ".csv"))
    {
        return 1;
    }
    else
        return 0;
}
