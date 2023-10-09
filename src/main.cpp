#include <iostream>
#include <fstream>
#include <iomanip>
#include "asset_id.h"
#include "png_exporter.h"

std::vector<AssetID> loadAssetIDs(const std::filesystem::path& inputFilePath);
void displayResults(const std::vector<AssetID>& assetIDs);
void generatePNGFiles(const std::vector<AssetID>& assetIDs,const std::filesystem::path& outputDirectory);


int main(int argc, char* argv[]){
    if(argc != 3){
       std::cout << "usage: " << argv[0] << " <input_filename_path> <output_directory_path>" << std::endl;
       exit(1);
    }
    auto inputFilePath = std::filesystem::path(argv[1]);
    auto outputDirectory = std::filesystem::path(argv[2]);

    auto assetIDs = loadAssetIDs(inputFilePath);
    displayResults(assetIDs);

    generatePNGFiles(assetIDs, outputDirectory);
    std::cout<<"PNG images generated in directory: "<<outputDirectory.string()<<std::endl<<std::endl;
}



std::vector<AssetID> loadAssetIDs(const std::filesystem::path& inputFilePath){
    std::ifstream input(inputFilePath.string());
    if(!input){
        std::cerr<<"could not open numbers file"<<std::endl;
        exit(1);
    }

    std::vector<AssetID> assetIDs;

    try{
        while(input.good()){
            std::string number;
            input >> number;
            if(!number.empty())
                assetIDs.emplace_back(AssetID{number});
        }
    }catch(std::exception& e){
        std::cerr << "error loading asset IDs: " << e.what() << std::endl;
    }

    return assetIDs;
}

void displayResults(const std::vector<AssetID>& assetIDs){
    std::cout << std::endl << std::left << std::setw(10) << "ID" << "Checksum" << std::endl;
    std::cout << std::setfill('-') << std::setw(20) << "" << std::endl;

    for(const auto& assetID : assetIDs){
        std::cout << std::setfill(' ') << std::left << std::setw(10);
        std::cout << assetID.str() << uint(assetID.checksum()) << std::endl;
    }    
    std::cout << std::endl; 
}

void generatePNGFiles(const std::vector<AssetID>& assetIDs,const std::filesystem::path& outputDirectory){
    auto exporter = PNGExporter();
    for(const auto& assetID : assetIDs){
        auto img = assetID.exportID(&exporter);
        auto outputDirectoryCpy = outputDirectory;
        auto outputPath = outputDirectoryCpy /= (assetID.str()+".png");
        cv::imwrite(outputPath.string(), img);
    }  
}
