//
//  DFS_Parser.hpp
//  dfs-tool
//
//  Created by Joseph Crane on 12/04/2019.
//  Copyright © 2019 Joseph Crane. All rights reserved.
//

#ifndef DFS_Parser_hpp
#define DFS_Parser_hpp

#include <stdio.h>

#include <string>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

#include "../DFS/DFS.hpp"
#include "../Application/ApplicationParameters.cpp"

using namespace std;

namespace DFS_Parser {

    class Parser {
        
        /// The path of the file to parse
        std::string dfsFilePath;
        
        /// The type of file being parsed
        FileType type;
        
        // A reference to hold any application flags
        const ApplicationParameters* parameters;
        
    public:
        
        /// Create a new DFS_Parser with the application parameters
        Parser(ApplicationParameters* parameters);
        
        /// Causes the file to be parsed
        DFS* parseFile();
        
    private:
        
        
        
    };

}
#endif /* DFS_Parser_hpp */
