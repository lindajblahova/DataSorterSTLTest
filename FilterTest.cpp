#include "pch.h"
#include "FilterTest.h"

// constructor of filter
TEST_F(FilterTest, FilterTerritorialUnit) {

	EXPECT_TRUE(m_filter->hasName(m_territorialUnitState, L"Slovensko")) << "Filter Name should be 'Slovensko'";
	EXPECT_TRUE(m_filter->hasType(m_territorialUnitState, TerritorialUnitType::State)) << "Filter Type should be 'State'";
	EXPECT_TRUE(m_filter->hasParent(m_territorialUnitState, nullptr)) << "Filter Parent of state should be nullptr";
	EXPECT_TRUE(m_filter->hasPopulation(m_territorialUnitState, 4900000, 5100000)) << "Filter Population should be between 4900000 and 5100000";
	EXPECT_TRUE(m_filter->hasBuiltUpRate(m_territorialUnitState, 0.9, 3.5)) << "Filter BuiltUpArea should be between 0.9 and 1.5";

	EXPECT_TRUE(m_filter->hasParent(m_territorialUnitRegion, m_territorialUnitState)) << "Filter Parent of region should be state";

}