#!/bin/bash
VERSION=2018.08.14
QTVERSION=5.11.0
OLDPATH=$PATH
./cleanup.sh
export PATH=../../../proxysh/qt-$QTVERSION-32bit/qtbase/bin:$OLDPATH
./builddebian32.sh $VERSION
./cleanup.sh
export PATH=../../../proxysh/qt-$QTVERSION-64bit/qtbase/bin:$OLDPATH
./builddebian64.sh $VERSION
./cleanup.sh
export PATH=$OLDPATH
