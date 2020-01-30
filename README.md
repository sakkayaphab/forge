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
    output_directory : ~/mysim
  config:
    sequencing: paired-end
    read_length: 101
    insert_size: 400
    sd: 50
    base_error_rate: 0.2
    coverage: 30
    seed: 0

variations:
  DEL:
    range:
      - 100-1000
    number:
      - 1

  INV:
    range:
      - 100-1000
    number:
      - 1

  DUP:
    range:
      - 1000-10000
    number:
      - 1

  INS:
    range:
      - 100-20000
    number:
      - 100

  delINV:
    allocate: AB
    pattern: DEL[A],INV[B]
    range:
      - 10000-20000
    number:
      - 1

  INVdel:
    allocate: AB
    pattern: INV[A],DEL[B]
    range:
      - 10000-20000
    number:
      - 1

  delINVdel:
    allocate: ABC
    pattern: DEL[A],INV[B],DEL[C]
    range:
      - 10000-20000
    number:
      - 1

  dupINV:
    allocate: AB
    pattern: A,INV[A;B]
    range:
      - 10000-20000
    number:
      - 1

  INVdup:
    allocate: AB
    pattern: INV[A;B],A
    range:
      - 10000-20000
    number:
      - 1

  dupINVdup:
    allocate: ABC
    pattern: A;INV[A,B,C];C
    range:
      - 10000-20000
    number:
      - 1

  dupINVdel:
    allocate: ABC
    pattern: A;INV[A,B];C
    range:
      - 10000-20000
    number:
      - 1

  delINVdup:
    allocate: ABC
    pattern: DEL[A];INV[B,C];C
    range:
      - 10000-20000
    number:
      - 1

  delINVdup:
    allocate: ABC
    pattern: DEL[A];INV[B,C];C
    range:
      - 10000-20000
    number:
      - 1

  dupTRIPdup-INV:
    allocate: ABC
    pattern: A;B;C;INV[A,B,C];B
    range:
      - 10000-20000
    number:
      - 1

  IR:
    allocate: AB
    pattern: A;INV[B]
    range:
      - 10000-20000
    number:
      - 1

  dDUP:
    allocate: AB
    pattern: A;B;A
    range:
      - 10000-20000
    number:
      - 1

  dDUPdel:
    allocate: ABC
    pattern: A;B;DEL[C];A
    range:
      - 10000-20000
    number:
      - 1

  cpdINS:
    allocate: ABC
    pattern: DEL[A];B;DEL[C];A
    range:
      - 10000-20000
    number:
      - 1
```


## License
Forge is distributed under the [GPLv3][GPLv3]. However, Forge includes several third-party open-source libraries, please see [Third Party Software Notices][LICENSETHIRDPARTY] for details.


[GPLv3]:LICENSE
[LICENSETHIRDPARTY]:THIRD-PARTY-LICENSE