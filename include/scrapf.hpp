#ifndef SCRAPING_FUNCTIONS
#define SCRAPING_FUNCTIONS

#include <string>

std::string gethtml(const std::string& url);

std::string geturlimage(const std::string& htmlpage);

bool downloadImage(std::string url, int page);

#endif //!SCRAPING_FUNCTIONS
