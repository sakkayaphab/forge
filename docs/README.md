# Documentations

## Input/Output files
![](https://i.imgur.com/GhWPlnu.png)

- example of template file
```yaml
files:
  input:
    reference: ~/reference/ucsc_hg19.fa
  output:
    output_directory : ~/mysim
  config:
    sequencing: paired-end
    read_length: 101
    average_insert_size: 400
    sd: 50
    base_error_rate: 0.2
    coverage: 30
    seed: 0

variations:
  DEL:
    range:
      - 100-1000
      - 1001-10000
    number:
      - 200
      - 100
  INS:
    range:
      - 100-20000
    number:
      - 100
  INV:
    range:
      - 400-10000
    number:
      - 90
```
## Convert reference genome (FASTA) to reference containers (RCs)
![](https://i.imgur.com/aRoTvkq.png)



## Complex SV syntax

- common variable
```text
DEL = deletion
INV = inversion
DUP = tandem duplication
INS = insertion
TRA = Translocation;
STA = Static (No mutation)
```

- customize complex SVs
```yaml
delINV:
    pattern:
      - [DEL(1/2),INV(1/2)]
    allocate_ref:
      - 2/2
INVdel:
    pattern:
      - [INV(1/2)DEL(1/2)]
    allocate_ref:
      - 2/2

delINVdel:
    pattern:
      - [DEL(1/3),INV(1/3),DEL(1/3)]
    allocate_ref:
      - 3/3

dupINV:
    pattern:
      - [DUP.A(1/3),DUP.A(1/3),STA(1/3)] > [STA(1/3),INV(2/3)]
    allocate_ref:
      - 2/3

INVdup:
    pattern:
      - [STA(1/3),DUP.A(1/3),DUP.A(1/3)] > [INV(2/3),STA(1/3)]
    allocate_ref:
      - 2/3

dupINVdup:
    pattern:
      - [DUP.A(1/4),DUP.A(1/4),DUP(1/4),DUP(1/4)] > [STA(1/4),INV(2/4),STA(1/4)]
    allocate_ref:
      - 2/4

dupINVdel:
    pattern:
      - [DUP.A(1/4),DUP.A(1/4),STA(1/4),DEL(1/4)] > [STA(1/4),INV(2/4),STA(1/4)]

dupTRIPdup-INV
    pattern:
      - [DUP.A(1/7),DUP.B(1/7),DUP.C(1/7),DUP.A(1/7),DUP.B(1/7),DUP.C(1/7),DUP.B(1/7)] > [STA(3/7),INV(3/7),STA(1/7)]

```




