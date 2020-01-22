FROM ubuntu:18.04

LABEL maintainer="Sakkayaphab Piwluang <sakkayaphab@gmail.com>"

WORKDIR /project
COPY . .

RUN apt-get -y update
RUN apt-get -y install wget
RUN wget https://repo.continuum.io/miniconda/Miniconda3-latest-Linux-x86_64.sh -O miniconda.sh;
RUN bash miniconda.sh -b -p $HOME/miniconda
RUN export PATH="$HOME/miniconda/bin:$PATH"
RUN hash -r
RUN $HOME/miniconda/bin/conda config --set always_yes yes
RUN HOME/miniconda/bin/conda update -q conda
RUN HOME/miniconda/bin/conda install -y -c bioconda seqan3
RUN mkdir build && cd build && cmake .. -DINSTALL_BIN_PREFIX=${PWD} -DINCLUDE_LIBRARY_PREFIX=$HOME/miniconda/include -DLIBRARY_LINK_PREFIX=$HOME/miniconda/lib/
RUN cd build && make
RUN cd build && make install

CMD ["/project/build/forge"]