#pragma once

#include "../DataSortingApp/TerritorialUnit/TerritorialUnit.h"

class TerritorialUnitTest : public ::testing::Test {
protected:

	std::shared_ptr<ITerritorialUnit> m_territorialUnitState = 
		std::make_shared<TerritorialUnit>(L"Slovensko", TerritorialUnitType::State, nullptr, 0, 0, 0, 0.0, 0.0);
	std::shared_ptr<ITerritorialUnit> m_territorialUnitRegion = 
		std::make_shared<TerritorialUnit>(L"Nitriansky", TerritorialUnitType::Region, m_territorialUnitState, 50000, 100000, 50000, 765390.3, 68903.1);
};