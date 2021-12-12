#include "imgcompare.h"
#include <memory>

namespace mycompare {
    class ImagesCompare_impl final: public ImagesCompare
    {
        public:
        ImagesCompare_impl(std::string fname1, std::string fname2):
        d_filename1(fname1),d_filename2(fname2)
        {}
        int run()
        {
            int res = 0;
            return res;
        }
        private:
        std::string d_filename1;
        std::string d_filename2;

    };
    std::unique_ptr<ImagesCompare> ImagesCompare::create(std::string filename1, std::string filename2)
    {
        return std::make_unique<ImagesCompare_impl>(filename1, filename2);
    }
}