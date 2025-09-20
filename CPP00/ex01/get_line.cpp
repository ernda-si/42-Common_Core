#include "phonebook.hpp"

int	main(void)
{
	std::string input;
	Phonebook phonebook;

	while (true)
	{
		std::cout << "Input: " << std::flush;
		getline(std::cin, input);
		if (input == "ADD")
			phonebook.add_cmd();
		else if (input == "SEARCH")
			phonebook.search_cmd();
		else if (input == "EXIT")
			break;
	}
}

// Conceitos chave:​
// Dilema moral | Conflito de interesses | Honestidade | Amizades verdadeiras​

//	Dilema moral: Situacao em que devemos escolher entre duas ou mais opcoes onde nenhuma delas seria satisfatoria, no caso do filme vemos isso na situacao onde Stephen fica entre escolher denunciar o ocorrido com a estagiaria e se prejudicar perdendo seu cargo porem fazendo algo moralmente correto 
//		e nao dizer nada para manter seu cargo porem fazendo algo moralmente incorreto ao esconder a verdade sobre Molly.​

//	Conflito de interesses:​ Ocorre quando os interesses pesssoais de um individuo influenciam o seu julgamento ou suas acoes de forma indevida 
// 		podendo ate prejudicar outro individuo ou um grupo por favorecer o individuo e seus interesses pessoais a custa dos outros.

//	Honestidade: a qualidade de um carater moral que se manifesta atraves da integridade, veracidade, franqueza e justica. Ser fiel a seus principios
//		e valores, falar e agir de acordo com a verdade alem de ser aberto e sincero nas suas acoes e palavras. Podemos observar na realidade e no filme
//			pessoas sendo desonestas, principalmente politicos em seus discursos quando fazem promessas que sabem que nao podem cumprir com as mesmas

//	Amizades verdadeiras: 

// ---------------------------------------------------------------------------------------------------------------------------------------------
//	vivido no filme: proteger a reputação do candidato e garantir o teu futuro político, ou revelar o escândalo
//	para preservar a integridade moral, mesmo que isso te prejudique? Fundamenta a tua resposta com
//	exemplos.
//	Tópicos para resposta

//	Qual seria o teu primeiro impulso perante a descoberta do escândalo?
//		Particularmente quando descobrisse do escandalo provavelmente iria sim passar algum tempo refletindo sobre a situacao devido ao quao
//			absurda tal noticia seria, e iria perguntar a Molly se ela gostaria que essa noticia fosse divulgada, e iria respeitar a decisao dela
//				independente do quanto pudesse me prejudicar. Entretanto mesmo que a decisao dela fosse para nao contar, eu iria arranjar alguma
//					forma de vinga-la pelo ocorrido prejudicando a vida de Morris.

//	Que valores (lealdade, integridade, ambição, justiça) influenciariam a tua decisão?
//		Lealdade a molly, integridade do meu proprio carater, justica pelo ocorrido.

//	Como achas que a tua escolha afetaria as pessoas envolvidas (Molly, Morris, a equipa de campanha)?
//		Acredito que a Molly iria se sentir extremamente envergonhada pelo ocorrido, Morris teria que lidar com a situacao que causou e deveria
//			pagar pelo que fez. A equipe da campanha teria que lidar com a situacao pois caso a noticia fosse divulgada com autorizacao, quem
//				continuasse la apos o ocorrido, teria que ter em mente que estariam apoiando um criminoso.

//	Considerarias guardar segredo para proteger o candidato e a campanha ou achas que a verdade deve ser a prioridade, independentemente das consequências?
//		Consideraria guardar segredo se fosse a decisao da Molly, caso contrario iria divulgar independente das consequencias.

//	Que impacto achas que a tua decisão teria na tua carreira e na tua visão sobre política?
//		Acredito que prejudicar Moris iria imapctar a minha carreira de forma direta porem em relacao a visao politica me faria dormir 
//			tranquilo a noite saber que ele esta pagando por suas proprias acoes.

// 18.2) Elabora um plano de 3 passos para resolver o dilema ético, considerando o seguinte:
// A. Analisar o contexto e os valores em conflito
// B. Consultar outras perspetivas e princípios éticos
// C. Decidir e agir de forma transparente e responsável
// Tópicos para Resposta Individual
// Que fatores precisas considerar para compreender o contexto deste dilema?
// Que valores estão em conflito? Quais darias prioridade e porquê?
// Quem poderias consultar (colegas, regulamentos, pessoas de confiança) para repensar as opções e garantir
// uma decisão ponderada?
// De que forma avaliarias o impacto da tua decisão nas pessoas envolvidas e na comunidade?
// Como comunicarias a tua decisão? Que argumentos usarias para justificar a tua escolha?
// Estarias preparado para assumir as consequências dessa decisão? Que impacto teria para ti e para o
// ambiente político ou organizacional?

