//
// Created by Sakkayaphab Piwluang on 30/1/20.
//

#include "baseerror.h"

BaseError::BaseError() {
    std::knuth_b rddengine;  // replace knuth_b with one of the engines listed below
    BaseError::rand_engine = rddengine;
    std::uniform_real_distribution<> random(0.0000, 1.0000);
    BaseError::uniform_zero_to_one = random;
}

void BaseError::setSeq(std::string *seq) {
    BaseError::seq = seq;
}

void BaseError::setErrorRate(double errorrate) {
    BaseError::errorrate = errorrate;
}

bool BaseError::random_bool_with_prob()
{
    return uniform_zero_to_one(BaseError::rand_engine) <= BaseError::errorrate;
}

std::string* BaseError::getSeq() {
    return seq;
}

void BaseError::execute() {
    for (char x:*seq) {
        if (random_bool_with_prob()) {
            seqwitherror = 'G';
        } else {
            seqwitherror = x;
        }

    }
}

std::string BaseError::getSeqWithBaseError() {
    return seqwitherror;
}
