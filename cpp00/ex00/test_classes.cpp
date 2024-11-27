#include <iostream>
#include <string>

class Coffee
{
	private:
		bool			is_served;
		int				number_of_shots;
		bool			oat_milk;
		bool			to_go;
		std::string		name;
	public:
		void			serve();
		void			serve(std::string user_name);
		Coffee(int a, bool b, bool c, std::string d)
		{
			is_served = false;
			number_of_shots = a;
			oat_milk = b;
			to_go = c;
			name = d;
		}
		//setters
		//getters
		std::string	getName()
		{
			return (name);
		}
};

void	Coffee::serve()
{
	std::cout << name << " is served." << std::endl;
	is_served = true;
}

void	Coffee::serve(std::string user_name)
{
	std::cout << name << " is served to " << user_name << "." << std::endl;
	is_served = true;
}

int	main()
{
	Coffee order1(2, true, false, "Flat white");
	std::cout << order1.getName() << std::endl;
	order1.serve("Lovely");
	order1.serve();
	return (0);
}
