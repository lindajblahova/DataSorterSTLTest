#include "pch.h"

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

/*
I will change this to parametrized testing tommorrow
*/
TEST_F(ComparatorTest, CompareByNameAscending) {

	m_comparator = std::make_unique<ComparatorByName>();
	m_comparator->setOrder(true);
	EXPECT_FALSE(m_comparator->compare(m_territorialUnitState, m_territorialUnitRegion)) << "Comparator by Name in Ascending order - Territorial unit1 should be less than Territorial Unit2";
}

TEST_F(ComparatorTest, CompareByNameDescending) {

	m_comparator = std::make_unique<ComparatorByName>();
	m_comparator->setOrder(false);
	EXPECT_TRUE(m_comparator->compare(m_territorialUnitState, m_territorialUnitRegion)) << "Comparator by Name in Descending order - Territorial unit1 should be greater than Territorial Unit2";
}

TEST_F(ComparatorTest, CompareByPopulationAscending) {

	m_comparator = std::make_unique<ComparatorByPopulation>();
	m_comparator->setOrder(true);
	EXPECT_FALSE(m_comparator->compare(m_territorialUnitState, m_territorialUnitRegion)) << "Comparator by Population in Ascending order - Territorial unit1 should be less than Territorial Unit2";
}

TEST_F(ComparatorTest, CompareByPopulationDescending) {

	m_comparator = std::make_unique<ComparatorByPopulation>();
	m_comparator->setOrder(false);
	EXPECT_TRUE(m_comparator->compare(m_territorialUnitState, m_territorialUnitRegion)) << "Comparator by Population in Descending order - Territorial unit1 should be greater than Territorial Unit2";
}

TEST_F(ComparatorTest, CompareByBuiltUpRateAscending) {

	m_comparator = std::make_unique<ComparatorByBuiltUpRate>();
	m_comparator->setOrder(true);
	EXPECT_TRUE(m_comparator->compare(m_territorialUnitState, m_territorialUnitRegion)) << "Comparator by BuiltUpRate in Ascending order - Territorial unit1 should be less than Territorial Unit2";
}

TEST_F(ComparatorTest, CompareByBuiltUpRateDescending) {

	m_comparator = std::make_unique<ComparatorByBuiltUpRate>();
	m_comparator->setOrder(false);
	EXPECT_FALSE(m_comparator->compare(m_territorialUnitState, m_territorialUnitRegion)) << "Comparator by BuiltUpRate in Descending order - Territorial unit1 should be greater than Territorial Unit2";
}