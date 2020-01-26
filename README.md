# Forge
Forge is a tool to simulate genomic structural variation

![Ubuntu](https://github.com/sakkayaphab/forge/workflows/Ubuntu/badge.svg?branch=master)
![MacOS](https://github.com/sakkayaphab/forge/workflows/MacOS/badge.svg?branch=master)
![Docker](https://github.com/sakkayaphab/forge/workflows/Docker/badge.svg?branch=master)
[![GitHub release (latest by date)](https://img.shields.io/github/v/release/sakkayaphab/forge)](https://github.com/sakkayaphab/forge/releases)
[![Conda](https://img.shields.io/conda/v/bioconda/forge?color=blue&label=Anaconda%20Cloud)](https://anaconda.org/bioconda/forge)


* template.yaml
```yaml
files:
  input:
    reference: ~/reference/ucsc_hg19.fa
  output:
    outputdirectory : ~/mysim
    sequencing: paired-end
    readlength: 101
    averageinsertsize: 400
    sd: 50
    baseerrorrate: 0.2
    coverage: 30

variations:
  DEL:
    range:
      - 10-100
      - 101-1000
    number:
      - 50
      - 100
  INS:
    range:
      - 10-100
      - 101-1000
    number:
      - 50
      - 100
  INV:
    range:
      - 100-1000
      - 1001-10000
    number:
      - 20
      - 40
```