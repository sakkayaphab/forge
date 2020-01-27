#include "vcfwriter.h"
#include <iostream>
#include <fstream>

VCFWriter::VCFWriter()
{
}

void VCFWriter::setOutputPath(std::string path)
{
    outputPath = path;
}

void VCFWriter::writeBufferAndClear()
{
    std::ofstream myfile;
    myfile.open(outputPath, std::ios_base::app);
    if (myfile.is_open())
    {
        for (int i = 0; i < datalines.size(); i++)
        {
            myfile << datalines.at(i).getTextCHROM() << "\t"
                   << datalines.at(i).getTextPOS() << "\t"
                   << datalines.at(i).getTextID() << "\t"
                   << datalines.at(i).getTextREF() << "\t"
                   << datalines.at(i).getTextALT() << "\t"
                   << datalines.at(i).getTextQUAL() << "\t"
                   << datalines.at(i).getTextFILTER() << "\t"
                   << datalines.at(i).getTextINFO() << "\t"
                   << std::endl;
        }
        datalines.clear();

        myfile.close();
    }
}

void VCFWriter::writeHeader()
{
    std::ofstream myfile;
    myfile.open(outputPath, std::ios_base::app);
    if (myfile.is_open())
    {
        myfile << metainfolines.getTextFileformat() << std::endl;
        myfile << metainfolines.getTextFileDate() << std::endl;
        myfile << metainfolines.getTextSource() << std::endl;
        myfile << metainfolines.getTextReference() << std::endl;
        myfile << "#CHROM\tPOS\tID\tREF\tALT\tQUAL\tFILTER\tINFO" << std::endl;
        myfile.close();
    }
}