#include "cli.h"
#include <iostream>
#include <string>
#include <thread>
#include <cstdlib>
#include "sim/sim.h"

Cli::Cli(int m_argc, char **m_argv)
{
    argc = m_argc;
    argv = m_argv;

    if (argc > 1)
    {
        args_lists.assign(argv + 1, argv + argc);
    }
}

void Cli::ShowHelp()
{
    std::cout << std::endl;
    std::cout << "NAME:" << std::endl;
    std::cout << "\tforge - a SV simulator" << std::endl;
    std::cout << std::endl;
    std::cout << "USAGE:" << std::endl;
    std::cout << "\tforge command [command options] [arguments...]" << std::endl;
    std::cout << std::endl;
    std::cout << "COMMANDS:" << std::endl;
    std::cout << "\tsim\tsimulate structural variation" << std::endl;
    std::cout << "\tversion\tShows version" << std::endl;
    std::cout << std::endl;
}

void Cli::showHelpCallSV()
{
    std::cout << std::endl;
    std::cout << "USAGE:" << std::endl;
    std::cout << "\tforge sv [command options] [arguments...]" << std::endl;
    std::cout << std::endl;
    std::cout << "COMMAND OPTIONS:" << std::endl;
    std::cout << "\t-b\tsample file path (*required)" << std::endl;
    std::cout << "\t-r\treference file path (*required)" << std::endl;
    std::cout << "\t-o\toutput path (*required)" << std::endl;
    std::cout << "\t-t\tnumber of threads to use" << std::endl;

    std::cout << std::endl;
}

std::string Cli::getCommand()
{
    if (args_lists.size() > 0)
    {
        return args_lists.at(0);
    }
    return "";
}

int Cli::vcfSV()
{
//    if (args_lists.size() < 2)
//    {
//        showHelpCallSV();
//        return 1;
//    }
//
//    if (args_lists.at(1) == "-h" || args_lists.at(1) == "-help")
//    {
//        showHelpCallSV();
//        return 0;
//    }
//
//
//    // Find Reference
//    bool foundRef = false;
//    std::string refPath;
//    for (auto n : args_lists)
//    {
//        if (foundRef)
//        {
//            refPath = n;
//            break;
//        }
//
//        if (n == "-r")
//        {
//            foundRef = true;
//        }
//    }
//
//    if (refPath == "")
//    {
//        std::cout << "not found reference file path" << std::endl;
//        return 1;
//    }
//
//    // Find output
//    bool foundOut = false;
//    std::string outPath;
//    for (auto n : args_lists)
//    {
//        if (foundOut)
//        {
//            outPath = n;
//            break;
//        }
//
//        if (n == "-o")
//        {
//            foundOut = true;
//        }
//    }
//
//    if (outPath == "")
//    {
//        std::cout << "not found output file path" << std::endl;
//        return 1;
//    }
//
//    // Find threads
//    bool foundThread = false;
//    std::string outThread;
//    for (auto n : args_lists)
//    {
//        if (foundThread)
//        {
//            outThread = n;
//            break;
//        }
//
//        if (n == "-t")
//        {
//            outThread = true;
//        }
//    }
//
//    unsigned int threads = std::thread::hardware_concurrency();
//    if (outThread != "")
//    {
//        try
//        {
//            threads = std::stoi(outThread);
//        }
//        catch (std::invalid_argument const &e)
//        {
//            std::cout << "Bad input: std::invalid_argument thrown" << '\n';
//            return 1;
//        }
//        catch (std::out_of_range const &e)
//        {
//            std::cout << "Integer overflow: std::out_of_range thrown" << '\n';
//            return 1;
//        }
//    }
//    std::cout << "Hello" << std::endl;
//    Variant variant;
//    Reference reference;
//    reference.setFastaIndexPath("/data/users/duangdao/kan/reference/ucsc_hg19.fa.fai");
//    reference.setFastaPath("/data/users/duangdao/kan/reference/ucsc_hg19.fa");

//    seqan3::debug_stream << "Hello world\n";
//    seqan::CharString pathToFile = seqan::getAbsolutePath("/data/users/duangdao/kan/reference/hs37d5.fa");
//    seqan::FaiIndex faiIndex;
//
//    if (!build(faiIndex, toCString(pathToFile)))
//        std::cout << "ERROR: Could not build the index!\n";


//
//    std::string namechar = "1";
//    unsigned idx = 0;
//    if (!seqan::getIdByName(idx, faiIndex, namechar.c_str()))
//    {
//        std::cerr << "ERROR: Index does not know about sequence " << namechar.c_str() << "\n";
//        return 0;
//    }
//
//    unsigned beginPos = 0, endPos = 10000;
//
//    if (beginPos > seqan::sequenceLength(faiIndex, idx))
//        beginPos = seqan::sequenceLength(faiIndex, idx);
//    if (endPos > seqan::sequenceLength(faiIndex, idx))
//        endPos = seqan::sequenceLength(faiIndex, idx);
//    if (beginPos > endPos)
//        endPos = beginPos;
//
//    // Finally, get infix of sequence.
//    seqan::Dna5String sequenceInfix;
//    seqan::readRegion(sequenceInfix, faiIndex, idx, beginPos, endPos);
//    std::cout << sequenceInfix << "\n";
    Sim sim;
    sim.setFastaPath("/home/sakkayaphab/kan/reference/ucsc_hg19.fa");
    sim.readFasta();

    return 0;
}

int Cli::debug()
{
    return 0;
}