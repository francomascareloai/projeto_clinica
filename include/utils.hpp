#ifndef UTILS_HPP
#define UTILS_HPP

#include "estoque.hpp"  // Necessario para usar o tipo Medicamento

void limparBuffer();
void vazioPorEnquanto(Medicamento lista[], int total);

#endif

// Criar diretório portable (Windows / POSIX)
#ifdef _WIN32
# include <direct.h>
# define MKDIR(path) _mkdir(path)
#else
# include <sys/stat.h>
# include <sys/types.h>
# define MKDIR(path) mkdir(path, 0755)
#endif
