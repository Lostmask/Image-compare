#include <iostream>

int main(int argc, char** argv)
{
    if(argc < 3)
    {
        std::cout<<"Usage of "<<argv[0]<<":"<<std::endl;
        std::cout<<argv[0]<<" image_1 image_2 [image_3 ...]"<<std::endl;
        return 0;
    }
    return 0;
}