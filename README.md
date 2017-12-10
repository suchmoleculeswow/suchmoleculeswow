# suchmoleculeswow

## Requirements

On Debian based Linux systems

```sh
$ sudo apt-get install build-essential libboost-all-dev qt5-default
```

## Build app

```sh
$ qmake suchmoleculeswow.pro
$ make
```

### Run app

Assuming everything built correctly.

```
$ suchmoleculeswow
```

## Build tests

```
$ qmake DEFINES+=ENABLE_SUCH_WOW_TESTS=1 suchmoleculeswow.pro
```

### Run tests

Assuming the tests built correctly.

```
$ suchmoleculeswow
```

## Issues

If you have both qt4 and qt5 installed on the system, make sure to use qmake-qt5.
