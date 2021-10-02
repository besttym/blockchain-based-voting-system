FROM ubuntu:bionic

ARG USERNAME=user
ARG USER_UID=1000
ARG USER_GID=$USER_UID

RUN apt-get update \
    && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install build-essential cmake cppcheck valgrind \
        git gcc g++ gdb clang clang-tools curl libxml2-dev libxml2-utils \
        libboost-filesystem-dev libboost-regex-dev libboost-system-dev libboost-thread-dev \
        sudo bash-completion vim dos2unix

RUN groupadd --gid $USER_GID $USERNAME \
    && useradd --uid $USER_UID --gid $USER_GID -m $USERNAME \
    && usermod -aG sudo $USERNAME \
    && echo $USERNAME ALL=\(ALL\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME \
    && chmod 0440 /etc/sudoers.d/$USERNAME

USER $USERNAME
RUN mkdir /home/$USERNAME/workspace
WORKDIR /home/$USERNAME/workspace