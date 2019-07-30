//
//  ApplicationParameters.cpp
//  dfs-tool
//
//  Created by Joseph Crane on 24/05/2019.
//  Copyright © 2019 Joseph Crane. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>

/*
CLI structure:
--file | --f the .ssd file to parse

--type | --t { values: dsd | ssd }

*/

enum FileType {
    SSD, /* Single-Sided-Disk */
    DSD, /* Double-sided-disk */
    NVD  /* Not-A-Valid-Disk */
};


/*
 Returns an FileType case for a string
 */
inline FileType getTypeForString(std::string leString) {
    return leString.compare("ssd") ? SSD : leString.compare("dsd") ? DSD : NVD;
}


// Encapsulates the Applications parameters

struct ApplicationParameters {
    // path to the .ssd file
    std::string filePath;
    // single or double sided disk
    FileType type;
    
    ApplicationParameters(int length, const char * parameters[]) {
        
        bool found = false;
        std::string currentParamter;
        std::string nextParameter;
        
        for (int i = 1; i < length - 1; i++) {
            
            currentParamter = parameters[i];
            nextParameter = parameters[i+1];
            
            if (currentParamter.compare("file") || currentParamter.compare("f")) {
                found = true;
                filePath = nextParameter;
            }
            else if (currentParamter.compare("type") || currentParamter.compare("t")) {
                found = true;
                this->type = getTypeForString(nextParameter);
            }
            else {
                if (found) {
                    found = false;
                }
            }
        }
        
        if (this->filePath.empty()) {
            throw "--file is a required parameter";
        }
        else if (this->type == NVD) {
            throw "--type is a required parameter";
        }
        else {
            std::cout << "Parsed application parameters" << std::endl;
        }
    }
};
