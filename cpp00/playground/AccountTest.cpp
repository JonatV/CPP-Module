#include "AccountTest.hpp"

AccountTest::AccountTest(int initial_deposit)
{
	std::cout << DARK "Construct Account" N << std::endl;
	std::cout << "Initial deposit : " << initial_deposit << std::endl;
}

AccountTest::~AccountTest()
{
	std::cout << DARK "Destruct Account" N << std::endl;
}


bool	get_input(std::string *buffer)
{
	while (true)
	{
		std::cout << "> ";
		buffer->clear();
		if (!std::getline(std::cin, *buffer))
		{
			std::cout << "Error reading input, program is exiting" << std::endl;
			return (false);
		}
		if (buffer->empty())
			std::cout << "Write something." << std::endl;
		else
			break;
	}
	return (true);
}

static bool	string_to_int(int *initial_deposit)
{
	std::string	buffer;
	while (true)
	{
		if (!get_input(&buffer))
			return (false); 
		try
		{
			*initial_deposit = std::stoi(buffer, NULL, 10);
		}
		catch (const std::invalid_argument &exception_object)
		{
			std::cout << BRED "Invalid input: not a number" N << std::endl;
			continue;
		}
		catch (const std::out_of_range &exception_object)
		{
			std::cout << BRED "Input number is out of range" N << std::endl;
			continue;
		}
		// if (*index_choosen > current_profile_number || *index_choosen < 1)
		// 	std::cout << BRED "This number isn't in the valid range." N << std::endl;
		// else
		return (true);
	}
}
// ************************************************************************** //
//                                  MAIN                                      //
// ************************************************************************** //

int main(void)
{
	// typedef std::vector<AccountTest::me>							  accounts_t;
	std::string	buffer;
	std::vector<AccountTest> accounts;
	accounts.push_back(AccountTest(100));
	accounts.push_back(AccountTest(2364));
	std::cout << "Welcome :" << std::endl;
	while (true)
	{
		if (!get_input(&buffer))
			return (EXIT_FAILURE);
		if (buffer == "ADD")
		{
			std::cout << "Enter initial deposit: ";
			int	initial_deposit;
			if (!string_to_int(&initial_deposit))
				return (EXIT_FAILURE);
			accounts.push_back(AccountTest(initial_deposit));
		}
		else if (buffer == "EXIT")
		{
			std::cout << "Bye" << std::endl;
			return (0);
		}
	}
	return 0;
}
