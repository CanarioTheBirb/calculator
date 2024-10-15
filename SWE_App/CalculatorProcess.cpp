#include "CalculatorProcess.h"
#include "wx/tokenzr.h"
#include <queue>
#include <stack>
CalculatorProcess* CalculatorProcess::instance = nullptr;
CalculatorProcess::CalculatorProcess()
{
}
CalculatorProcess* CalculatorProcess::getInstance()
{
	if (instance == nullptr)
	{
		instance = new CalculatorProcess();
	}
	return instance;
}
void CalculatorProcess::SetText(wxString text)
{
	_equation = text;
}
void CalculatorProcess::SetLabel(wxString label)
{
	_label = label;
}
wxString CalculatorProcess::GetText()
{
	return _equation;
}
void CalculatorProcess::Process()
{
	if (_label == "Delete")
	{
		if (!_equation.IsEmpty())
		{
			if (_equation.Last() == ' ' || _equation.Last() == 's' || _equation.Last() == 'n')
			{
				_equation.RemoveLast(3);
			}
			else
			{
				_equation.RemoveLast();
			}
		}
	}
	else if (_label == "C")
	{
		_equation.Clear();
	}
	else if (_label == "+/-")
	{
		wxString equation = _equation;
		if (_equation.IsEmpty())
		{
			return;
		}

		if (equation.find_last_of("+-/*%") != equation.npos)
		{
			if (equation.find_last_of("+-/*%") == equation.length() - 1)
			{
				return;
			}
			else if (equation[equation.find_last_of("+-/*%") + 2] != '–')
			{
				equation.insert(equation.find_last_of("+-/*%") + 2, '–');

			}
			else
			{
				equation.Remove(equation.find_last_of("–"), 1);
			}
		}
		else if (equation.find_last_of("sn") != equation.npos)
		{
			if (equation.find_last_of("sn") == equation.length() - 1)
			{
				return;
			}
			else if (equation[equation.find_last_of("sn") + 1] != '–')
			{
				equation.insert(equation.find_last_of("sn") + 1, '–');

			}
			else
			{
				equation.Remove(equation.find_last_of("–"), 1);
			}
		}
		else
		{
			if (equation.find_last_of("–") == equation.npos)
			{
				equation.Prepend("–");
			}
			else
			{
				equation.Remove(equation.find_last_of("–"), 1);
			}
		}
		SetText(equation);
	}
	else if (_label == "=")
	{
		wxStringTokenizer token(_equation, " ");
		std::queue<wxString> equationQ;
		std::stack<wxString> operators;
		while (token.HasMoreTokens())
		{
			wxString cToken = token.GetNextToken();
			if (cToken.find_first_of("+-/*%") == cToken.npos)
			{
				equationQ.push(cToken);
			}
			else
			{
				if (operators.empty())
				{
					operators.push(cToken);
				}
				else if (operators.top().find_first_of("*/%") != operators.top().npos && cToken.find_first_of("*/%") != cToken.npos)
				{
					equationQ.push(operators.top());
					operators.pop();
					operators.push(cToken);
				}
				else if (operators.top().find_first_of("*/%") != operators.top().npos)
				{
					while (!operators.empty())
					{
						equationQ.push(operators.top());
						operators.pop();
					}
					operators.push(cToken);
				}
				else
				{
					operators.push(cToken);
				}
			}
		}

		while (!operators.empty())
		{
			equationQ.push(operators.top());
			operators.pop();
		}

		std::stack<double> holdStack;
		while (!equationQ.empty())
		{
			wxString front = equationQ.front();
			equationQ.pop();
			if (front.find_first_of("+-/*%") == front.npos)
			{
				if (front.find_first_of("sct") != front.npos)
				{
					if (front.find("sin") != front.npos && front.find_first_of("–") == front.npos)
					{
						front.Remove(front.find_first_of("s"), 3);
						holdStack.push(sin(wxAtof(front) * M_PI / 180));
					}
					else if (front.find("sin") != front.npos && front.find_first_of("–") != front.npos)
					{
						front.Remove(front.find_first_of("s"), 4);
						holdStack.push(sin(-wxAtof(front) * M_PI / 180));
					}
					else if (front.find("cos") != front.npos && front.find_first_of("–") == front.npos)
					{
						front.Remove(front.find_first_of("c"), 3);
						holdStack.push(cos(wxAtof(front) * M_PI / 180));
					}
					else if (front.find("cos") != front.npos && front.find_first_of("–") != front.npos)
					{
						front.Remove(front.find_first_of("c"), 4);
						holdStack.push(cos(-wxAtof(front) * M_PI / 180));
					}
					else if (front.find("tan") != front.npos && front.find_first_of("–") == front.npos)
					{
						front.Remove(front.find_first_of("t"), 3);
						holdStack.push(tan(wxAtof(front) * M_PI / 180));
					}
					else if (front.find("tan") != front.npos && front.find_first_of("–") != front.npos)
					{
						front.Remove(front.find_first_of("t"), 4);
						holdStack.push(tan(-wxAtof(front) * M_PI / 180));
					}
				}
				else if (front.find_first_of("+-/*%") == front.npos && front.find_first_of("–") != front.npos)
				{
					front.Remove(front.find_first_of("–"), 1);
					holdStack.push(-wxAtof(front));
				}
				else if (front.find_first_of("+-/*%") == front.npos)
				{
					holdStack.push(wxAtof(front));
				}
			}
			else
			{
				 char op = *front.mb_str(wxConvUTF8);
				 double num2 = holdStack.top();
				 holdStack.pop();
				 double num1 = holdStack.top();
				 holdStack.pop();
				if (op == '+')
				{
					num1 = num1 + num2;
				}
				else if (op == '-')
				{
					num1 = num1 - num2;
				}
				else if (op == '/')
				{
					num1 = num1 / num2;
				}
				else if (op == '*')
				{
					num1 = num1 * num2;
				}
				else if (op == '%')
				{
					num1 = fmod(num1, num2);
				}
				holdStack.push(num1);
			}
		}
		wxString answer;
		answer << holdStack.top();
		if (answer.find("-") != answer.npos)
		{
			answer[answer.find("-")] = '–';
		}
		SetText(answer);
	}
	else
	{
		if (_label.find_first_of("+-/*%") == _label.npos)
		{
			SetText(_equation + _label);
		}
		else
		{
			SetText(_equation + " " + _label + " ");
		}
	}
}