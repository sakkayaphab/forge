//
// Created by Sakkayaphab Piwluang on 30/1/20.
//

#ifndef FORGE_BASEERROR_H
#define FORGE_BASEERROR_H

#include <string>
#include <random>

class BaseError {
    std::string *seq;
    double errorrate = 0;
    std::knuth_b rand_engine;
    std::uniform_real_distribution<> uniform_zero_to_one;
    std::string seqwitherror;

public:
    BaseError();
    void setSeq(std::string *seq);
    void setErrorRate(double errorrate);
    void execute();
    std::string *getSeq();
    bool random_bool_with_prob();
    std::string getSeqWithBaseError();
};


#endif //FORGE_BASEERROR_H
