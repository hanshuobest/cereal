/***************************************************
* @projectName   cereal
* @brief         简单序列化，生成一个json文件，并读取
* @author        hscoder
* @date          2020-03-21
**************************************************/

#include <iostream>
#include <cereal/archives/json.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/types/string.hpp>
#include <ostream>
#include <fstream>

using namespace cereal;

int main(int argc , char *argv[])
{
    {
        std::ofstream os("myinfo.json");
        cereal::JSONOutputArchive archive(os);

        std::string name = "han";
        int age = 30;
        std::string career = "engineer";
        std::string Residence = "beijing";
        archive(cereal::make_nvp("Age" , age) , cereal::make_nvp("Name" , name) , cereal::make_nvp("Career" , career) , cereal::make_nvp("Residence" , Residence));
    }

    {
        std::ifstream is("myinfo.json");
        cereal::JSONInputArchive archive(is);

        std::string name;
        int age;
        std::string career;
        std::string Residence;

        archive(cereal::make_nvp("Age" , age));
        archive(cereal::make_nvp("Name" , name));
        archive(cereal::make_nvp("Career" , career));
        archive(cereal::make_nvp("Residence" , Residence));

        std::cout << "Name: " << name << " , " << "Age: " << age << " , " << "career: " << career << " , " << " Residence: " << Residence << std::endl;
    }


    return 1;
}
