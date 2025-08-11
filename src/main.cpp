#include <iostream>
#include <string>
#include "../include/scrapf.hpp"
#include <cpr/cpr.h>
#include <unistd.h>

int main(){
    std::string page1 = "https://www.scan-trad.com/scan/40114";
    std::string page = page1.c_str();
    bool end = true;
    int npage = 1;

    std::string dirName = "images";


    if (std::filesystem::create_directory(dirName)) {
        std::cout << "Directory created: " << dirName << std::endl;
    } else {
        std::cout << "Directory already exists or could not be created." << std::endl;
    }

    while (end){
        if (npage != 1){
            page = page1 + "/" + std::to_string(npage);
        }
        std::cout << page << std::endl;
        end = downloadImage(geturlimage(gethtml(page)), npage);
        npage++;

    }

    return 0;
}
