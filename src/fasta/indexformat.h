//
// Created by Sakkayaphab Piwluang on 26/1/20.
//

#ifndef FORGE_INDEXFORMAT_H
#define FORGE_INDEXFORMAT_H

#include <string>
#include <cstdint>

class IndexFormat {
private:
    std::string NAME;
    int64_t LENGTH = 0;
    int64_t OFFSET= 0;
    int64_t LINEBASES= 0;
    int64_t LINEWIDTH= 0;
    int64_t QUALOFFSET= 0;

public:
    IndexFormat();
    std::string getName();
    int64_t getLength();
    int64_t getOffset();
    int64_t getLineBases();
    int64_t getLineWidth();
    int64_t getQualOffset();
    void setName(std::string NAME);
    void setLength(int64_t LENGTH);
    void setOffset(int64_t OFFSET);
    void setLineBases(int64_t LINEBASES);
    void setLineWidth(int64_t LINEWIDTH);
    void setQualOffset(int64_t QUALOFFSET);
};


#endif //FORGE_INDEXFORMAT_H
