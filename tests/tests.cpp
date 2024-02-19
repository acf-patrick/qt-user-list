#include "pch.h"
#include "CppUnitTest.h"
#include "../observable.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace tests
{
	TEST_CLASS(ObservableTests)
	{
	public:
		TEST_METHOD(shouldSubscribe)
		{
			Observable<int> observable(0);
			int currentValue;

			observable.subscribe([&](int value) {
				currentValue = value;
			});

			observable.next(1);
			Assert::AreEqual(currentValue, observable.getValue());
		}

		TEST_METHOD(shouldUnsubscribe)
		{
			Observable<int> observable(0);
			int currentValue;

			auto observer = observable.subscribe([&](int value) {
				currentValue = value;
			});

			observable.next(1);
			Assert::AreEqual(currentValue, observable.getValue());

			observer.unsubscribe();
			observable.next(2);

			Assert::AreNotEqual(currentValue, observable.getValue());
		}

		TEST_METHOD(shouldSubscribeOnce) 
		{
			Observable<int> observable(0);
			int currentValue;

			observable.subscribeOnce([&](int value) {
				currentValue = value;
			});

			observable.next(1);
			Assert::AreEqual(currentValue, observable.getValue());

			observable.next(2);
			Assert::AreEqual(currentValue, 1);
		}

		TEST_METHOD(shouldRemoveAllObservers)
		{
			Observable<int> observable(0);
			int value = 0;
			auto addOne = [&value](int _) { value++; };

			observable.subscribe(addOne);
			observable.subscribe(addOne);
			observable.subscribe(addOne);

			observable.unsubscribeAll();
			observable.next(1);
			
			Assert::AreEqual(value, 0);
		}
	};
}
