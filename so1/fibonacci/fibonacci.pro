TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    bigint/BigInteger.cc \
    bigint/BigIntegerAlgorithms.cc \
    bigint/BigIntegerUtils.cc \
    bigint/BigUnsigned.cc \
    bigint/BigUnsignedInABase.cc

HEADERS += \
    bigint/BigInteger.hh \
    bigint/BigIntegerAlgorithms.hh \
    bigint/BigIntegerLibrary.hh \
    bigint/BigIntegerUtils.hh \
    bigint/BigUnsigned.hh \
    bigint/BigUnsignedInABase.hh \
    bigint/NumberlikeArray.hh

