 

SOFTWARE DE ESTOQUE E CÁLCULO DE DOSAGEM PARA CLÍNICA 

 

 

Eduardo Luiz Wittmann 

eduardowittmann@acad.ftec.com.br 

Nicolas Bizinotto Lacerda 

email02@acad.ftec.com.br 

Franco Mascarelo Ortiz 

email02@acad.ftec.com.br 

Me Neiva Larisane Kuyven 

neivakuyven@acad.ftec.com.br 

 

ALGORITMOS E PROGRAMAÇÃO I 

Caxias do Sul - RS 

 

 

Resumo: O presente artigo foi criado com o objetivo de documentar a criação de um software de controle de estoque e cálculo de dosagem para uma pequena clínica, desenvolvido em linguagem C, através do Visual Studio Code. 

 

Palavras-chave: Linguagem C. Clínica. Estoque. Dosagem. Cálculo. 

 

1 INTRODUÇÃO 

O avanço das tecnologias aplicadas à saúde tem impulsionado o desenvolvimento de ferramentas capazes de otimizar rotinas administrativas e reduzir falhas humanas. Entre essas rotinas, o controle de estoque de medicamentos e o cálculo correto de dosagens ocupam papel central na segurança e eficiência do atendimento clínico. Em pequenas clínicas, onde muitas tarefas ainda são executadas manualmente, a ausência de sistemas informatizados pode gerar desperdícios, erros de dosagem, perda de medicamentos por vencimento e dificuldade no acompanhamento do inventário. 

Diante desse cenário, o presente estudo propõe o desenvolvimento de um software em linguagem C capaz de integrar cálculos de dosagem e gerenciamento de estoque em uma única aplicação. A pesquisa busca preencher a lacuna existente na criação de soluções simples, acessíveis e voltadas ao ensino de algoritmos, ao mesmo tempo em que simula um ambiente real de operação clínica. O trabalho delimita-se ao desenvolvimento de um protótipo funcional, com foco em manipulação de dados via vetores, structs, laços de repetição e condicionais, sem integração com banco de dados ou interface gráfica. 

Assim, o estudo pretende demonstrar como conceitos fundamentais de programação podem ser aplicados para resolver problemas práticos, contribuindo tanto para o aprendizado acadêmico quanto para a modelagem de ferramentas úteis ao cotidiano de clínicas de pequeno porte. 

 

2 OBJETIVOS 

Objetivo Geral:  

Desenvolver um software em linguagem C que permita realizar cálculos de dosagem e gerenciar o estoque de medicamentos de uma pequena clínica, integrando funções de cadastro, consulta, alerta e análise. 

Objetivos Específicos:  

Implementar um módulo de cadastro de medicamentos utilizando structs. 

Criar rotinas de listagem e consulta do inventário em memória. 

Desenvolver verificações automáticas de validade e baixo estoque. 

Gerar estatísticas simples, como quantidade total de medicamentos cadastrados e médias de estoque. 

Simular vendas, atualizando o estoque automaticamente. 

Implementar uma função para cálculo de dosagem com base em parâmetros do usuário. 

Testar, documentar e validar o funcionamento do software através de casos de uso. 

 

3 MATERIAL E MÉTODOS 

O software foi desenvolvido em linguagem C, utilizando o ambiente Visual Studio Code. Para sua construção, foram aplicados conceitos fundamentais da disciplina de Algoritmos e Programação I. 

 

Materiais e Técnicas Utilizadas: 

Linguagem: C 

Ambiente de Desenvolvimento: Visual Studio Code 

Estruturas de Dados: vetores e structs 

Técnicas de Programação: 

Estruturas condicionais (if, else if, switch) 

Laços de repetição (for, while) 

Manipulação de strings e dados numéricos 

Modularização das funções do programa 

 

Metodologia: 

Modelagem da estrutura base: definição da struct Medicamento, contendo: ID, nome, quantidade atual, quantidade mínima e data de validade. 

Implementação do menu principal: criação de rotinas para navegação entre as funcionalidades do sistema. 

Desenvolvimento das funções centrais: cada item do menu foi implementado como uma função independente, permitindo: 

cadastro de medicamentos; 

listagem dos itens armazenados; 

análise de validade e estoque mínimo; 

cálculo de dosagens; 

simulação de vendas. 

Testes e validação: Foram executados testes com entradas simuladas para garantir a correção dos cálculos e da manipulação dos dados. 

Os procedimentos foram descritos de forma a permitir que outros estudantes reproduzam o experimento com fidelidade. 

 

4 RESULTADOS E DISCUSSÃO 

O desenvolvimento do software resultou em um protótipo funcional capaz de realizar todas as operações previstas na proposta inicial. Durante os testes, verificou-se que o sistema conseguiu cadastrar corretamente os medicamentos, armazenando suas informações em vetores estruturados. A função de listagem exibiu os dados de forma organizada, enquanto o módulo de alertas identificou com precisão tanto medicamentos vencidos quanto itens com estoque abaixo do mínimo definido. 

O cálculo de dosagem apresentou resultados adequados conforme os parâmetros fornecidos pelo usuário, demonstrando eficácia na aplicação de fórmulas simples dentro do contexto clínico simulado. A simulação de venda também se mostrou funcional, reduzindo o estoque de acordo com as quantidades informadas. 

Os testes apontaram que a abordagem modular facilitou a compreensão e manutenção do código, reforçando a importância da organização das funções em projetos iniciais. Observou-se, ainda, que o uso de structs possibilitou um armazenamento estruturado eficiente para o objetivo do estudo. 

 

5 CONSIDERAÇÕES FINAIS 

O projeto atingiu seu objetivo de desenvolver um software simples, funcional e capaz de apoiar atividades essenciais de uma pequena clínica: controle de estoque e cálculo de dosagens. As funcionalidades implementadas demonstraram que técnicas básicas de programação podem ser aplicadas de forma eficaz para resolver problemas reais ou simulados, contribuindo tanto para o aprendizado acadêmico quanto para a prototipagem de soluções práticas. 

Embora o sistema cumpra sua função, trabalhos futuros podem incluir melhorias como persistência de dados em arquivos, interfaces gráficas, exportação completa do inventário e integração com bancos de dados. Ainda assim, o protótipo apresentado cumpre satisfatoriamente o escopo do estudo e evidencia o potencial educativo e prático das ferramentas desenvolvidas. 

 

 

 