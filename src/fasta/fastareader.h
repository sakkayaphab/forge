#ifndef FASTAREADER_H
#define FASTAREADER_H

#include <string>
#include <vector>
#include <map>
#include <stdint.h>
#include "faidx.h"
#include "fasta.h"
#include <algorithm>
#include "block.h"
#include "blockcontainer.h"
#include "containermanager.h"
#include <tbb/parallel_for.h>
#include <tbb/task_arena.h>
#include <tbb/global_control.h>
#include <mutex>

class FastaReader {
private:
    Faidx faidx;
    Fasta fasta;

public:
    FastaReader();

    void setFilePath(std::string filepath);

    std::string getFilePath();

    bool hasFilePath();

    void setIndexFilePath(std::string indexfilepath);

    std::string getIndexFilePath();

    bool hasIndexFilePath();

    void exitIfNoFilePath();

    bool FileExists(std::string filename);

    void initialize();

    std::string getSeqbyPosition(std::string chromosome, int64_t start, int64_t end);

    std::string getSeqbyChr(std::string chromosome);

    Faidx getFastaIndex();

    void replaceSeqToUppercase(std::string *str) {
        std::transform((*str).begin(), (*str).end(), (*str).begin(), ::toupper);
    }


    struct RegionRange {
        std::string chrname;
        int64_t pos = 0;
        int64_t end = 0;
    };

    struct ChromosomeRegion {
        std::vector<FastaReader::RegionRange> RegionRange;
    };

    ContainerManager getAllChrBlockContainerWithThreads(int threads);
    ContainerManager getAllChrBlockContainerWithSingleThread();
    BlockContainer getBlockContainerByChr(std::string chrname);
    std::vector<Block> convertSeqToBlockWithoutMasked(std::string chrname,std::string *seq);
    std::vector<Block> convertSeqToBlockWithMasked(std::string chrname,std::string *seq);

    void showChromosomeRegion(FastaReader::ChromosomeRegion cr);
};

#endif