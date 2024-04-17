#include "h/generators/SimpleBacktrackingSetPartitionsGenerator.h"
#include "h/visitors/SetPartitionVisitor.h"
#include <vector>

using Subset = SetPartitionsGenerator::Subset;
using Partition = SetPartitionsGenerator::Partition;
using PartitionList = SetPartitionsGenerator::PartitionList;

static PartitionList part(Subset& A, const int k)
{
    if(k == 1)
        return {{A}};
    if(k == A.size())
    {
        Partition P;
        for(int a : A)
            P.push_back({a});
        return {P};
    }
    PartitionList B;
    const int a1 = A[A.size() - 1];
    A.pop_back();
    PartitionList P = part(A, k);
    for(Partition& p : P)
        for(Subset& sub : p)
        {
            sub.push_back(a1);
            B.push_back(p);
            sub.pop_back();
        }
    P = part(A, k - 1);
    for(Partition& p : P)
    {
        p.push_back({a1});
        B.push_back(p);
        p.pop_back();
    }
    A.push_back(a1);
    return B;
}

std::chrono::duration<double>
SimpleBacktrackingSetPartitionsGenerator::generatePartitions(const int n, const int k, std::ostream* const partitionsOut,
    std::ostream* const resultsOut, SetPartitionVisitor& visitor) const
{
    auto start = std::chrono::high_resolution_clock::now();
    Subset A;
    for(int i = 0; i < n; i++)
        A.push_back(i + 1);
    PartitionList allPartitions = part(A, k);
    for(auto& partition : allPartitions)
        visitor.visit(partition, partitionsOut);
    visitor.results(resultsOut);
    auto end = std::chrono::high_resolution_clock::now();
    return end - start;
}
