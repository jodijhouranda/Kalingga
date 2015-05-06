#ifndef RESULTINDEX_H
#define RESULTINDEX_H


class ResultIndex
{
public:
    ResultIndex(int rootIdx , int childIdx);
    ~ResultIndex();
    int getRootIdx();
    int getChildIdx();

private:
    int rootIdx;
    int childIdx;
};

#endif // RESULTINDEX_H
