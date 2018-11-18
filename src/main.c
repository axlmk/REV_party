#include "../header/option.h"

int main(int argc, char *argv[]) {
    csvType vote;
    defineOption(argc, argv, &vote, "test");
    return EXIT_SUCCESS;
}
