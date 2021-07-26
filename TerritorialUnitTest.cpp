#include "pch.h"
#include "TerritorialUnitTest.h"
#include "../DataSortingApp/TerritorialUnit/TerritorialUnit.cpp"

// what, class, method, output = passed if ..
TEST_F(TerritorialUnitTest, InitialValues) {

	EXPECT_EQ(L"Slovensko", m_territorialUnitState->getName()) << "Name should be 'Slovensko'";
	EXPECT_EQ(TerritorialUnitType::State, m_territorialUnitState->getType()) << "Type should be 'State'";
	EXPECT_EQ(nullptr, m_territorialUnitState->getParent()) << "Parent should be nullptr";
	EXPECT_EQ(0, m_territorialUnitState->getPreProductive()) << "PreProductive should be 0";
	EXPECT_EQ(0, m_territorialUnitState->getProductive()) << "Productive should be 0";
	EXPECT_EQ(0, m_territorialUnitState->getPostProductive()) << "PostProductive should be 0";
	EXPECT_EQ(0.0, m_territorialUnitState->getTotalArea()) << "TotalArea should be 0";
	EXPECT_EQ(0.0, m_territorialUnitState->getBuiltUpArea()) << "BuiltUpArea should be 0";

	EXPECT_EQ(m_territorialUnitState, m_territorialUnitRegion->getParent()) << "Parent should be 'Slovensko'";

}

TEST_F(TerritorialUnitTest, AddingValues) {

	//act
	m_territorialUnitState->addValues(1500000, 2000000, 1500000, 49035000.4, 539000.38);

	//assert
	EXPECT_EQ(1500000, m_territorialUnitState->getPreProductive()) << "PreProductive should be 1500000";
	EXPECT_EQ(2000000, m_territorialUnitState->getProductive()) << "Productive should be 2000000";
	EXPECT_EQ(1500000, m_territorialUnitState->getPostProductive()) << "PostProductive should be 1500000";
	EXPECT_EQ(49035000.4, m_territorialUnitState->getTotalArea()) << "TotalArea should be 49035000.4";
	EXPECT_EQ(539000.38, m_territorialUnitState->getBuiltUpArea()) << "BuiltUpArea should be 539000.38";

}