//
// Created by daniel on 11.03.18.
//

#include "Polybius.h"

std::string PolybiusCrypt(std::string message) {
    std::vector< std::vector<char> > polybiusBoard = {{'a', 'b', 'c', 'd', 'e'}, {'f','g','h','i','k'}, {'l', 'm', 'n', 'o', 'p'}, {'q', 'r', 's', 't', 'u'}, {'v', 'w', 'x', 'y', 'z'}};
    std::string outputMessage;
    for (int l = 0; l < message.size(); l++) {
        message[l] = tolower(message[l]);
    }
    for (int k = 0; k < message.size(); k++) {
        if ( message[k] == 'j' ) {
            outputMessage += "24";
        } else {
            for (int i = 0; i < polybiusBoard.size(); i++)
            {
                auto it = std::find(polybiusBoard[i].begin(), polybiusBoard[i].end(), message[k]);
                if (it != polybiusBoard[i].end())
                {
                    outputMessage.append(std::to_string(i + 1));
                    outputMessage.append(std::to_string(std::distance(polybiusBoard[i].begin(), it) + 1));
                }
            }
        }
    }
    return outputMessage;
}

std::string PolybiusDecrypt(std::string crypted) {
    std::string outputMessage;
    char polybiusBoard [5][5] = {{'a', 'b', 'c', 'd', 'e'}, {'f','g','h','i','k'}, {'l', 'm', 'n', 'o', 'p'}, {'q', 'r', 's', 't', 'u'}, {'v', 'w', 'x', 'y', 'z'}};

    for (int k = 0; k < crypted.size(); k += 2) {
        int firstCoordinate = (int)crypted[k]-49;
        int secondCoordinate = (int)crypted[k+1]-49;
        outputMessage.push_back(polybiusBoard[firstCoordinate][secondCoordinate]);
    }
    return outputMessage;
}
