//
//  AlgoritmoSubstituicaoPagina.hpp
//  Projeto2-SO
//
//  Created by Pedro Figueirêdo on 03/11/2017.
//  Copyright © 2017 Pedro Figueirêdo. All rights reserved.
//

#ifndef AlgoritmoSubstituicaoPagina_hpp
#define AlgoritmoSubstituicaoPagina_hpp

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>

class AlgoritmoSubstituicaoPagina {
public:
    
    AlgoritmoSubstituicaoPagina(const std::vector<unsigned>& seqAcesso, std::vector< std::pair<unsigned,unsigned> >& quadros);
    ~AlgoritmoSubstituicaoPagina();
    
    virtual int calculaFaltaDePaginas_() = 0;
    
protected:
    const std::vector<unsigned>& seqAcesso_;
    std::vector< std::pair<unsigned,unsigned> >& quadros_;
};

#endif /* AlgoritmoSubstituicaoPagina_hpp */
