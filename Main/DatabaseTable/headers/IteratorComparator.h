//
// Created by tale on 2017/2/22.
//

#ifndef A3NEW_ITERATORCOMPARATOR_H
#define A3NEW_ITERATORCOMPARATOR_H
#include "MyDB_RecordIteratorAlt.h"
#include "MyDB_Record.h"
#include <iostream>
using namespace std;

class IteratorComparator {

public:

    IteratorComparator (function <bool ()> comparatorIn, MyDB_RecordPtr lhsIn,  MyDB_RecordPtr rhsIn) {
        comparator = comparatorIn;
        lhs = lhsIn;
        rhs = rhsIn;
    }

    bool operator () (MyDB_RecordIteratorAltPtr lhsPtr, MyDB_RecordIteratorAltPtr rhsPtr) {
//        leftIter->fromBinary (lhsPtr);
//        rightIter->fromBinary (rhsPtr);

        lhsPtr->getCurrent(lhs);
        rhsPtr->getCurrent(rhs);

        return !comparator ();
    }

private:

    function <bool ()> comparator;

    MyDB_RecordPtr lhs;
    MyDB_RecordPtr rhs;

};
#endif //A3NEW_ITERATORCOMPARATOR_H
