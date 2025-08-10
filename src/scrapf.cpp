#include "../include/scrapf.hpp"
#include <cpr/api.h>
#include <cpr/cprtypes.h>
#include <cpr/response.h>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>

std::string gethtml(const std::string& url){
    // User-Agent d'un navigateur (exemple pour Chrome)
    std::string userAgent = "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36";
    return cpr::Get(cpr::Url{url.c_str()}, cpr::Header{{"User-Agent", userAgent}}).text;
}

std::string geturlimage(const std::string& htmlpage){
    char charactere;
    std::string result;
    std::string debutBalise = "<img";
    std::string reconaitreimage = "page";
    int corres = 0;
    int corresimage = 0;
    int debutbalise = 0;
    int finbalise = 0;
    for (int i = 0; i < htmlpage.length(); i++){
        if (htmlpage[i] == debutBalise[corres]){
            corres += 1;
        }
        else{
            corres = 0;
        }
        if (corres == 4){
            for(int i2 = i; htmlpage[i2] != '>'; i2++){
                if(htmlpage[i2] == reconaitreimage[corresimage]){
                    corresimage +=1;
                }
                else{
                    corresimage = 0;
                }
                if (corresimage == 4){
                    debutbalise = i;
                }
                finbalise = i2;
            }
        }
    }
    std::string debutURL = "src=\"";
    corres = 0;
    int debuturl = 0;
    bool ignore = false;
    bool lien = false;

    int i = debutbalise;
    int nbguillemet = 0;
    while (nbguillemet < 2){
        if (htmlpage[i] == '"'){
            nbguillemet++;
        }
        if (nbguillemet == 1 && htmlpage[i] != '"'){
            result += htmlpage[i];
        }
        i++;
    }

    return result;
}

bool downloadImage(std::string url, int page){
    std::string nameimage = "images/p" + std::to_string(page) + ".webp";
    std::string userAgent = "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36";
    std::ofstream image(nameimage, std::ios::binary);
    cpr::Response r = cpr::Get(cpr::Url{url.c_str()}, cpr::Header{{"User-Agent", userAgent}});
    if(r.status_code != 200){
        std::cout << "Erreur telechargement page " << page << std::endl;
        image.close();
        return false;
    }
    image << r.text;
    image.close();
    std::cout << "Page " << page << " telecharger\n";
    return true;
}
