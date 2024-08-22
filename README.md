# Keyboards

QMK configuration and code for the following keyboards:
  - [Planck](./planck/README.md)
  - [Totem](./totem/README.md)
  - [Voyager](./voyager/README.md)

# Installation

First, install the qmk-cli by following the instructions found on [this link](https://docs.qmk.fm/newbs_getting_started).

Then, you can clone the QMK repository or use the submodule found in this repository. Use the following commands for the latter option.

```bash
git submodule init
git submodule update
```

# Usage

You can use the [Makefile](./Makefile) at the root of this repository to easily compile and build the available keyboards.

## Planck

Use the [Makefile](./planck/Makefile) found in the planck directory.

```bash
cd ./planck
make build
```

## Totem

Use the [Makefile](./totem/Makefile) found in the totem directory. The [Totem keyboard](https://github.com/GEIGEIGEIST/qmk-config-totem) is not available by default in the qmk repository. Make sure you run make clone the totem repository before attempting to build it.

```bash
cd ./totem
make clone
make build
```

## Voyager

The Voyager depends on [ZSA's QMK fork](https://github.com/zsa/qmk_firmware). To build it, you need to clone the repository using the following commands.

```bash
cd voyager
git submodule update
make voyager:ireydiak
```
