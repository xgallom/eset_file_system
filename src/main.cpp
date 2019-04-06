#include "Arguments/Arguments.h"
#include "Application.h"
#include "OutputPresenter.h"

int main(int argc, const char *argv[])
{
	try {
		Arguments::Arguments arguments;

		try {
			arguments = Arguments::parse(argc, argv);
		}
		catch(Arguments::Exception &argumentException) {
			const auto result = OutputPresenter::presentException(argumentException);
			OutputPresenter::presentUsage();

			return result;
		}

		return Application::run(arguments.path(), arguments.key(), arguments.parallelize());
	}
	catch(std::exception &exception) {
		return OutputPresenter::presentException(exception);
	}
}