#include "../header/options.h"

int main(int argc, char *argv[]) {
    csvType vote;
    char *method = malloc(sizeof(char));
    char *csvName = malloc(sizeof(char));
    char *logfp = malloc(sizeof(char));
    defineOptions(argc, argv, &vote, csvName, logfp, method);
    printf("csvname : %s\nlogfp : %s\nmethod :%s\n", csvName, logfp, method);

    free(logfp);
    free(csvName);
    free(method);
    return EXIT_SUCCESS;
}
