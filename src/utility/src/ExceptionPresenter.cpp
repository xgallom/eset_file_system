//
// Created by xgallom on 4/10/19.
//

#include "ExceptionPresenter.h"

#include <iostream>

namespace OutputPresenter
{
	int presentException(const std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;

		return EXIT_FAILURE;
	}
}
