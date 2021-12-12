#include "imgcompare.h"
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <iostream>
#include <vector>
#include <string>
int get_accuracy_param()
{
    int accuracy = 0;
    std::cin >> accuracy;
    while(std::cin.fail())
    {
        std::cerr<<"Expected an int"<<std::endl;
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> accuracy;
    }
    std::cin.ignore(32767, '\n');
    return accuracy;
}
std::string get_file_name()
{
    std::string res;
    std::getline(std::cin, res);
    if(std::cin.eof())
    {
        return "";
    }
    return res;
}
int main(int argc, char** argv)
{
    int accuracy =  get_accuracy_param();
    std::vector<std::string> fnames;
    auto name = get_file_name();
    while(name != "")
    {
        fnames.push_back(name);
        name = get_file_name();
    }
    if(fnames.size() < 2)
    {
        std::cerr<<"Need at least two images"<<std::endl;
        return 0;
    }
    for(auto it1 = fnames.begin(); it1 < fnames.end();++it1)
    {
        for(auto it2 = it1 + 1; it2 < fnames.end(); ++it2)
        {
            auto comp = mycompare::ImagesCompare::create(*it1, *it2);
            auto match = comp->run();
            if(match >= accuracy)
            {
                std::cout<< (*it1) <<", "<< (*it2)<<", "<<match<<"\%"<<std::endl;
            }
        }
    }
    return 0;
}