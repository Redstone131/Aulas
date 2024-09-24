#include <iostream> //entrada
#include <cstdlib> // Para rand() e srand() - aleatorizar
#include <ctime> //para time()
#include <map> //para std::map

int main() 
{
	int entrada;
	std::string resposta;

	while (resposta != "sair" || "Sair" || "off" || "não" || "n" || "Não" || entrada < 1 || entrada > 3) {
		std::map<int, std::string> opcao;

   		opcao[1] = "Pedra";
   		opcao[2] = "Papel";
    	opcao[3] = "Tesoura";


		std::cout << "Pedra [1], papel [2] ou tesoura [3]?\n";
		std::cin >> entrada;

		if (entrada < 1 || entrada > 3) {
			std::cout << "Entrada invalida. Escolha 1 (Pedra), 2 (Papel) ou 3 (Tesoura).\n";
			return 1;
		}
	
		srand(static_cast<unsigned int>(time(0)));

		int dado = rand() % 3 + 1;

		std::string escolha = opcao[dado];
		std::cout << "Eu escolhi: " << "'" << escolha << "'" << "!!\n";

	    if (entrada == dado) { 
        std::cout << "Empate!\n";
  	  } else if ((entrada == 1 && dado == 3) || // Pedra ganha de Tesoura
               (entrada == 2 && dado == 1) || // Papel ganha de Pedra
               (entrada == 3 && dado == 2)) { // Tesoura ganha de Papel
        std::cout << "Voce venceu!\n";
		} else {
     std::cout << "Voce perdeu!\n";
  	  }
		std::cout << "Deseja jogar novamente? Digite um proximo nnmero para continuar\n";
		std::getline(std::cin, resposta);
	}	
	return 0;
}