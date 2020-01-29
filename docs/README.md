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
## Convert reference genome to reference containers
![](https://i.imgur.com/aRoTvkq.png)







