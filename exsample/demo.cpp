/***************************************************
* @projectName   cereal
* @brief         读取一个json文件
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
using namespace std;

class JSONPredInfo {
public:
    int id = -1;
    std::string name = "";
    int category_id = 0;
    std::string category = "";
    double depth = 0.0;
    double alpha = 0.0;
    double score = 0.0;
    std::vector<float> bbox{0.0, 0.0, 0.0, 0.0};
    std::vector<float> dim{0.0, 0.0, 0.0};

    template <class Archive>
    void serialize(Archive & ar)
    {
        ar(CEREAL_NVP(id),
           CEREAL_NVP(name),
           CEREAL_NVP(category_id),
           CEREAL_NVP(category),
           CEREAL_NVP(depth),
           CEREAL_NVP(alpha),
           CEREAL_NVP(bbox),
           CEREAL_NVP(dim),
           CEREAL_NVP(score)
           );
    }

    friend std::ostream & operator << (std::ostream &os , const JSONPredInfo &info);
};

std::ostream & operator << (std::ostream &os , const JSONPredInfo &info)
{
    os << "id: " << info.id << std::endl;
    os << "name: " << info.name << std::endl;
    os << "category_id: " << info.category_id << std::endl;
    os << "category: " << info.category << std::endl;
    os << "depth: " << info.depth << std::endl;
    os << "alpha: " << info.alpha << std::endl;
    os << "score: " << info.score << std::endl;
    os << "----bbox----" << std::endl;
    for (auto b : info.bbox)
    {
        os << b << "  ";
    }
    os << std::endl;

    os << "----dim----" << std::endl;
    for (auto d : info.dim)
    {
        os << d << "  ";
    }
    os << std::endl;
    return  os;
}

class JSONPredictions {
public:
    std::vector<JSONPredInfo> images;

    template <class Archive>
    void serialize(Archive & ar)
    {
        ar(CEREAL_NVP(images));
    }
};

bool LoadPredictionJson(
        std::string & pred_json,
        JSONPredictions & pred)
{
    cout << "Loading prediction json: " << pred_json << endl;

    std::ifstream is(pred_json);
    if (!is)
    {
        cerr << "Failed to load prediction json: " << pred_json << endl;
        return false;
    }
    cereal::JSONInputArchive pred_json_arxiv(is); //
    pred.serialize(pred_json_arxiv);
    return true;
}

int main(int argc , char *argv[])
{
    std::string json_file = "/Users/han/git_project/cereal/exsample/prediction.json";
    JSONPredictions preds;
    LoadPredictionJson(json_file , preds);

    for (auto image : preds.images)
    {
        std::cout << image << std::endl;
        std::cout << "------------------------------------------" << std::endl;
    }
    return 1;
}
