#include "Polybius.h"

int main( int argc, char* argv[] ) {
    if (argc != 4) {
        // argc must be equal 4 because first argument is program name and another three are arguments
        std::cout << "Error, wrong number of arguments entered" << std::endl;
        return EXIT_FAILURE;
    }
    std::string path = "/home/daniel/CLionProjects/jimp2/lab2/polybius/";
    std::string inputFilePath = path + argv[1];
    std::string outputFilePath = path + argv[2];
    std::string conversionOption= argv[3];

    std::string inputMessage;
    std::string outputMessage;

    std::ifstream myInputFile(inputFilePath);
    if(!myInputFile.good()) {
        std::cout << "Input file error!" << std::endl;
        return EXIT_FAILURE;
    }

    getline(myInputFile, inputMessage);

    std::ofstream myOutputFile(outputFilePath);
    if(!myOutputFile.good()) {
        std::cout << "Output file error!" << std::endl;
        return EXIT_FAILURE;
    }

    if ( conversionOption == "1" ) {
        // encrypt
        std::string encryptedMessage = PolybiusCrypt(inputMessage);
        std::cout << encryptedMessage << std::endl;
        myOutputFile << encryptedMessage;
    } else if ( conversionOption == "0") {
        // decrypt
        std::string decryptedMessage = PolybiusDecrypt(inputMessage);
        std::cout << decryptedMessage << std::endl;
        myOutputFile << decryptedMessage;
    }

    myInputFile.close();
    myOutputFile.close();
    return 0;
}

