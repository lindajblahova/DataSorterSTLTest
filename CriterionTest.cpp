#include "pch.h"

#include "../DataSortingApp/Criterion/Criterion.cpp"
#include "../DataSortingApp/Criterion/Criterion.h"
#include "TerritorialUnitTest.h"

class CriterionTest : public TerritorialUnitTest {
protected:
	void SetUp() override {
		m_criterion = std::make_unique<Criterion>();
	}

	std::unique_ptr<ICriterion> m_criterion;

};

// constructor of criterion
TEST_F(CriterionTest, EvaluateTerritorialUnit) {

	EXPECT_EQ(L"Slovensko", m_criterion->name(m_territorialUnitState)) << "Criterion Name is not equal to 'Slovensko'";
	EXPECT_EQ(TerritorialUnitType::State, m_criterion->type(m_territorialUnitState)) << "Criterion Type is not equal to 'State'";
	EXPECT_TRUE(m_criterion->hasParent(m_territorialUnitState, nullptr)) << "Criterion Parent of state should be nullptr";
	EXPECT_EQ(0, m_criterion->preProductive(m_territorialUnitState)) << "Criterion PreProductive should be 0";
	EXPECT_EQ(0, m_criterion->productive(m_territorialUnitState)) << "Criterion Productive should be 0";
	EXPECT_EQ(0, m_criterion->postProductive(m_territorialUnitState)) << "Criterion PostProductive should be 0";
	EXPECT_EQ(0.0, m_criterion->totalArea(m_territorialUnitState)) << "Criterion TotalArea should be 0";
	EXPECT_EQ(0.0, m_criterion->builtUpArea(m_territorialUnitState)) << "Criterion BuiltUpArea should be 0";

	EXPECT_TRUE(m_criterion->hasParent(m_territorialUnitRegion, m_territorialUnitState)) << "Criterion Parent of region should be state";

}