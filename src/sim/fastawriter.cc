//
// Created by Sakkayaphab Piwluang on 31/1/20.
//

#include "fastawriter.h"

FastaWriter::FastaWriter() {

}

void FastaWriter::writeRefFile(std::string filepath, std::string *seq, std::string chr, int64_t pos, int64_t end) {
    std::ofstream myfile;
    std::string_view tempseq = *seq;
    myfile.open (filepath, std::fstream::app);
    myfile << ">" << chr << "\n";
    std::cout << "# " << chr << " " << pos << " " << end << std::endl;
    int64_t i =0;
    for (;;) {
        if (i+50<end-pos) {
            myfile << tempseq.substr(i,50) << "\n";
            i += 50;
        } else {
            myfile << tempseq.substr(i,i+50-(end-pos)) << "\n";
            break;
        }
    }
    myfile.close();
}
