#include <string>
#include <vector>
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

int main()
{
    std::vector<std::string> v;
    std::string path = "data/";
    //for (const auto &entry : fs::directory_iterator(path))
    for (const auto &entry : fs::recursive_directory_iterator(path))
        v.push_back(entry.path());
        //std::cout << entry.path() << std::endl;

    //for (const auto &f : v)
    //    std::cout << f << std::endl;
    std::cout << v.size() << std::endl;
}
