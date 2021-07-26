#pragma once

#include "../DataSortingApp/Criterion/Criterion.h"
#include "TerritorialUnitTest.h"

class CriterionTest : public TerritorialUnitTest {
protected:
	void SetUp() override {
		m_criterion = std::make_unique<Criterion>();
	}

	std::unique_ptr<ICriterion> m_criterion;

};

