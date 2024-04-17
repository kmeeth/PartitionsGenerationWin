#include "h/generators/IntegerPartitionsGeneratorFactory.h"
#include "h/generators/SimpleBacktrackingIntegerPartitionsGenerator.h"
#include "h/generators/TreeIntegerPartitionsGenerator.h"
#include "h/generators/ConjugationIntegerPartitionsGenerator.h"

const std::vector<std::string> IntegerPartitionsGeneratorFactory::algorithms = {"SimpleBacktracking", "Tree", "Conjugation"};

std::unique_ptr<IntegerPartitionsGenerator> IntegerPartitionsGeneratorFactory::make(const std::string_view name)
{
    if(name == "SimpleBacktracking")
        return std::make_unique<SimpleBacktrackingIntegerPartitionsGenerator>();
    else if(name == "Tree")
        return std::make_unique<TreeIntegerPartitionsGenerator>();
    else if(name == "Conjugation")
        return std::make_unique<ConjugationIntegerPartitionsGenerator>();
    else
        return nullptr;
}
