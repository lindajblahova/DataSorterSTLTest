#pragma once
#include "TerritorialUnitTest.h"
#include "../DataSortingApp/Comparator/ComparatorByName.h"
#include "../DataSortingApp/Comparator/ComparatorByPopulation.h"
#include "../DataSortingApp/Comparator/ComparatorByBuiltUpRate.h"
class ComparatorTest : public TerritorialUnitTest {
protected:
	void SetUp() override {
		m_territorialUnitState->addValues(1500000, 2000000, 1500000, 49035000.4, 539000.38);
	}

	std::unique_ptr<IComparator> m_comparator;
};
