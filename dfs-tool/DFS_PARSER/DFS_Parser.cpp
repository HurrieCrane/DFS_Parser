////
////  DFS_Parser.cpp
////  dfs-tool
////
////  Created by Joseph Crane on 12/04/2019.
////  Copyright © 2019 Joseph Crane. All rights reserved.
////
//
#include "DFS_Parser.hpp"

DFS_Parser::Parser::Parser(ApplicationParameters* parameters) {
    this->dfsFilePath = parameters->filePath;
    this->parameters = parameters;
    this->type = parameters->type;
}

DFS* DFS_Parser::Parser::parseFile() {
    
    DFS* dfs = new DFS();
    
    ifstream dfsFile(this->dfsFilePath, ios::binary);
    vector<unsigned char> dfsBuffer (istreambuf_iterator<char>(dfsFile), {});
    
    unsigned long dfsFileLength = dfsBuffer.size();
    
    string diskName;
    for (int i = 0; i < dfsFileLength; i++) {
        diskName += dfsBuffer.at(i);
    }

    dfs->diskName = diskName;
    
    return dfs;
}
