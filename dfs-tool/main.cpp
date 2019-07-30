//
//  main.cpp
//  dfs-tool
//
//  Created by Joseph Crane on 12/04/2019.
//  Copyright © 2019 Joseph Crane. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>

#include "./DFS_PARSER/DFS_Parser.hpp"

ApplicationParameters* parameters;
DFS_Parser::Parser* parser;

int main(int argc, const char * argv[]) {
    if (argc <= 1) {
        printf( "error: no input passed" );
        return 1;
    }
    
    parameters = new ApplicationParameters(argc, argv);
    parser = new DFS_Parser::Parser(parameters);
    
    parser->parseFile();
    
    return 0;
}
