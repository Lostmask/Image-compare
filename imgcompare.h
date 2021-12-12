#ifndef IMAGE_COMPARE_H
#define IMAGE_COMPARE_H
#include <opencv2/core.hpp>
#include <memory>
namespace mycompare {
class ImagesCompare
{
    public:
    static  std::unique_ptr<ImagesCompare> create(std::string filename1, std::string filename2);
    virtual int run() = 0;
    virtual ~ImagesCompare(){}
};
}

#endif