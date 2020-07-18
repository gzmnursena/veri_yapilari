#include <iostream>
#include <zipper/unzipper.h>
#include <zipper/zipper.h>
#include <fstream>

using namespace zipper;


int main() {
    std::ifstream input1("a");
    std::ifstream input2("b");

    Zipper zipper("ziptest.zip");
    zipper.add(input1, "Test1");
    zipper.add(input2, "Test1");

    zipper.close();
    return 0;
}
