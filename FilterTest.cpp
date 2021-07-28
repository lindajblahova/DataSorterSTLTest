#include "pch.h"

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

// constructor of filter
TEST_F(FilterTest, FilterTerritorialUnit) {

	EXPECT_TRUE(m_filter->hasName(m_territorialUnitState, L"Slovensko")) << "Filter Name should be 'Slovensko'";
	EXPECT_TRUE(m_filter->hasType(m_territorialUnitState, TerritorialUnitType::State)) << "Filter Type should be 'State'";
	EXPECT_TRUE(m_filter->hasParent(m_territorialUnitState, nullptr)) << "Filter Parent of state should be nullptr";
	EXPECT_TRUE(m_filter->hasPopulation(m_territorialUnitState, 4900000, 5100000)) << "Filter Population should be between 4900000 and 5100000";
	EXPECT_TRUE(m_filter->hasBuiltUpRate(m_territorialUnitState, 0.9, 3.5)) << "Filter BuiltUpArea should be between 0.9 and 1.5";

	EXPECT_TRUE(m_filter->hasParent(m_territorialUnitRegion, m_territorialUnitState)) << "Filter Parent of region should be state";

}