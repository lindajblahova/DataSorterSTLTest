#pragma once
#include "../DataSortingApp/Filter/Filter.cpp"
#include "TerritorialUnitTest.h"

class FilterTest : public TerritorialUnitTest {
protected:
	void SetUp() override {
		m_filter = std::make_unique<Filter>();
		m_territorialUnitState->addValues(1500000, 2000000, 1500000, 49035000.4, 539000.38);
	}

	std::unique_ptr<IFilter> m_filter;

};