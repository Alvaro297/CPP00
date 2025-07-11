# include <iostream>
# include <cctype>

int main(int argc, char const *argv[])
{
	if (argc > 1) {
		for (int i = 1; i < argc; ++i) {
			for (int j = 0; argv[i][j] != '\0'; ++j) {
				std::cout << static_cast<char>(std::toupper(argv[i][j]));
			}
			if (i != argc - 1)
				std::cout << " ";
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}
