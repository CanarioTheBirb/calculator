#include "pch.h"
#include "CppUnitTest.h"
#include "../SWE_App/ButtonFactory.h"
#include "../SWE_App/CalculatorProcess.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SWEAPPTest
{
	TEST_CLASS(Buttons)
	{
	public:
		wxFrame* parent = new wxFrame(nullptr, wxID_ANY, "Test");
		TEST_METHOD(checkForPlus)
		{
			wxButton* button = ButtonFactory::CreateAddButton(parent);
			Assert::AreEqual("+",button->GetLabel());
		}
		TEST_METHOD(checkForMinus)
		{
			wxButton* button = ButtonFactory::CreateMinusButton(parent);
			Assert::AreEqual("-", button->GetLabel());
		}
		TEST_METHOD(checkForMul)
		{
			wxButton* button = ButtonFactory::CreateMultiplyButton(parent);
			Assert::AreEqual("*", button->GetLabel());
		}
		TEST_METHOD(checkForDivide)
		{
			wxButton* button = ButtonFactory::CreateDivideButton(parent);
			Assert::AreEqual("/", button->GetLabel());
		}
		TEST_METHOD(checkForModulo)
		{
			wxButton* button = ButtonFactory::CreateModButton(parent);
			Assert::AreEqual("%", button->GetLabel());
		}
		TEST_METHOD(checkForEqual)
		{
			wxButton* button = ButtonFactory::CreateEqualButton(parent);
			Assert::AreEqual("=", button->GetLabel());
		}
		TEST_METHOD(checkForSin)
		{
			wxButton* button = ButtonFactory::CreateSinButton(parent);
			Assert::AreEqual("sin", button->GetLabel());
		}
		TEST_METHOD(checkForCos)
		{
			wxButton* button = ButtonFactory::CreateCosButton(parent);
			Assert::AreEqual("cos", button->GetLabel());
		}
		TEST_METHOD(checkForTan)
		{
			wxButton* button = ButtonFactory::CreateTanButton(parent);
			Assert::AreEqual("tan", button->GetLabel());
		}
		TEST_METHOD(checkFor9)
		{
			wxButton* button = ButtonFactory::Create9Button(parent);
			Assert::AreEqual("9", button->GetLabel());
		}
	};

	TEST_CLASS(Calculator)
	{
	public:
		CalculatorProcess* calc = CalculatorProcess::getInstance();
		TEST_METHOD(Addition)
		{
			calc->SetLabel("=");
			calc->SetText("2 + 2");
			calc->Process();
			Assert::AreEqual("4",calc->GetText());
		}
		TEST_METHOD(Minus)
		{
			calc->SetLabel("=");
			calc->SetText("20 - 15");
			calc->Process();
			Assert::AreEqual("5", calc->GetText());
		}
		TEST_METHOD(Multiply)
		{
			calc->SetLabel("=");
			calc->SetText("509 * 75");
			calc->Process();
			Assert::AreEqual("38175", calc->GetText());
		}
		TEST_METHOD(Divide)
		{
			calc->SetLabel("=");
			calc->SetText("450 / 32");
			calc->Process();
			Assert::AreEqual("14.0625", calc->GetText());
		}
		TEST_METHOD(Modulo)
		{
			calc->SetLabel("=");
			calc->SetText("78 % 23");
			calc->Process();
			Assert::AreEqual("9", calc->GetText());
		}
		TEST_METHOD(PEMDAS)
		{
			calc->SetLabel("=");
			calc->SetText("345 - 45 * 15 + 32 / 8");
			calc->Process();
			Assert::AreEqual("–326", calc->GetText());
		}
		TEST_METHOD(Decimal)
		{
			calc->SetLabel("=");
			calc->SetText("23.56 + 57.65 * 100.50 / 20.31");
			calc->Process();
			Assert::AreEqual("308.83", calc->GetText());
		}
		TEST_METHOD(Negative)
		{
			calc->SetLabel("=");
			calc->SetText("–75 - –34 * –45");
			calc->Process();
			Assert::AreEqual("–1605", calc->GetText());
		}
		TEST_METHOD(SinCosTan)
		{
			calc->SetLabel("=");
			calc->SetText("sin90 + cos75 - tan180");
			calc->Process();
			Assert::AreEqual("1.25882", calc->GetText());
		}
		TEST_METHOD(Everything)
		{
			calc->SetLabel("=");
			calc->SetText("67.25 - 1.9 * sin180 / tan–50 + 26");
			calc->Process();
			Assert::AreEqual("93.25", calc->GetText());
		}
	};
}
