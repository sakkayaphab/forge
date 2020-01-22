#include <gtest/gtest.h>
#include <iostream>
#include "vcf/writer.h"
#include <string>
#include <bits/stdc++.h>
#include "vcf/metainfoline.h"
#include "vcf/dataline.h"

TEST(FilePathTest, getTestVCF1)
{
    Writer vcfwriter;
    MetaInfoline metainfoline;
    metainfoline.setheader_fileformat("VCFv4.2");
    metainfoline.setheader_fileDate(metainfoline.getDateStringNow());
    metainfoline.setheader_source("boltV3.1");
    metainfoline.setheader_reference("ucsc_hg19.fa");
    Dataline dataline;
    dataline.setTextCHROM("chr20");
    dataline.setTextPOS("0");
    dataline.setTextID(".");
    dataline.setTextREF(".");
    dataline.setTextALT(".");
    dataline.setTextQUAL("0");
    dataline.setTextFILTER("q10;s50");
    dataline.setTextInfoKeyValue("END","13131232");
    vcfwriter.setMetaInfoLines(metainfoline);
    vcfwriter.addDataline(dataline);
    vcfwriter.setOutputPath("1");
    vcfwriter.writeHeader();
    vcfwriter.writeBufferAndClear();
}
