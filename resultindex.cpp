#include "resultindex.h"

ResultIndex::ResultIndex(int rootIdx , int childIdx):
    rootIdx(rootIdx),
    childIdx(childIdx)
{

}

ResultIndex::~ResultIndex()
{

}

int ResultIndex::getRootIdx(){
    return rootIdx;
}
int ResultIndex::getChildIdx(){
    return childIdx;
}

