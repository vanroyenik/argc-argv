#include <stdio.h>
#include <string.h>
#include <locale.h>

#define OK_MSG "Команда выполненеа успешно"
#define FILE_IS_EXIST "Файл уже существует"
#define FILE_NOT_FOUND "Файл не найден"
#define COMMAND_ERR "Команда не корректна\n"
#define HELP "-c filename создание файла, -d filename удаление файла"

#define NEW_FILE "-c"
#define DELETE_FILE "-d"

int main(int argc, char* argv[]) {
    printf(argv[0]);
    setlocale(LC_ALL, "Russian");
    if (argc==3){
        FILE *file = fopen(argv[2], "r");
        if(strcmp(argv[1], NEW_FILE)==0) {
            if (file == NULL) {
                file = fopen(argv[2], "w");
                fclose(file);
                printf(OK_MSG);
            } else {
                printf(FILE_IS_EXIST);
            }
        }else if(strcmp(argv[1], DELETE_FILE)==0) {
            if(file==NULL){
                printf(FILE_NOT_FOUND);
            } else {
                fclose(file);
                remove(argv[2]);
                printf(OK_MSG);
            }
        } else{
            printf(COMMAND_ERR);
        }
    }else {
        printf(COMMAND_ERR);
        printf(HELP);
    }
    return 0;
}
