/***************************************************
* @projectName   cereal
* @brief         简单序列化，生成一个xml文件
* @author        hscoder
* @date          2020-03-21
**************************************************/

#include <iostream>
#include <cereal/archives/json.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/archives/xml.hpp>
#include <ostream>
#include <fstream>

using namespace cereal;

int main(int argc , char *argv[])
{
    std::ofstream os("myinfo.xml");
    cereal::XMLOutputArchive archive(os);

    std::string name = "han";
    int age = 30;
    std::string career = "engineer";
    std::string Residence = "beijing";
    archive(cereal::make_nvp("Age" , age) , cereal::make_nvp("Name" , name) , cereal::make_nvp("Career" , career) , cereal::make_nvp("Residence" , Residence));

    return 1;
}
