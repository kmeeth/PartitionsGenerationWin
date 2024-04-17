#ifndef PARTITIONSGENERATION_SETPARTITIONSGENERATOR_H
#define PARTITIONSGENERATION_SETPARTITIONSGENERATOR_H
#include <vector>
#include <ostream>
#include <chrono>

class SetPartitionVisitor;
class SetPartitionsGenerator
{
public:
    // Generates all partitions of set of size number that have partCount parts. Outputs partitions to partitionsOut and results to resultsOut if present.
    virtual std::chrono::duration<double> generatePartitions(int number, int partCount, std::ostream* partitionsOut, std::ostream* resultsOut, SetPartitionVisitor& visitor) const = 0;
    virtual ~SetPartitionsGenerator() = default;
    using Subset = std::vector<int>;
    using Partition = std::vector<Subset>;
    using PartitionList = std::vector<Partition>;
    using RGS = std::vector<int>;
};

#endif //PARTITIONSGENERATION_SETPARTITIONSGENERATOR_H
