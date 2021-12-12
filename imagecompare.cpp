#include "imgcompare.h"
#include <opencv2/core/mat.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/features2d.hpp>
#include <vector>
#include <iostream>

namespace mycompare {
    class ImagesCompare_impl final: public ImagesCompare
    {
        public:
        ImagesCompare_impl(std::string fname1, std::string fname2):
        d_filename1(fname1),d_filename2(fname2)
        {}
        int run()
        {
            const float TARGET_DISTANCE = 50;
            int res = 0;
            cv::Mat img1 = cv::imread(d_filename1);
            cv::Mat img2 = cv::imread(d_filename2);
            auto feat_engine = cv::ORB::create();
            std::vector<cv::KeyPoint> ft1;
            std::vector<cv::KeyPoint> ft2;
            cv::Mat descp1;
            cv::Mat descp2;
            feat_engine->detect(img1, ft1);
            feat_engine->compute(img1, ft1, descp1);
            feat_engine->detect(img2, ft2);
            feat_engine->compute(img2, ft2, descp2);
            std::vector<cv::DMatch> matches;
            auto matcher = cv::DescriptorMatcher::create("BruteForce-Hamming");
            matcher->match(descp1, descp2, matches, cv::Mat());
            size_t count = 0;
            for(auto& m : matches)
            {
                if(m.distance <= TARGET_DISTANCE)
                {
                    ++count;
                }
            }
            res = floor(100.0*count/matches.size());
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